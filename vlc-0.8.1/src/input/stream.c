/*****************************************************************************
 * stream.c
 *****************************************************************************
 * Copyright (C) 1999-2004 VideoLAN
 * $Id: stream.c 8928 2004-10-06 10:50:35Z gbazin $
 *
 * Authors: Laurent Aimar <fenrir@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

#include <stdlib.h>
#include <vlc/vlc.h>
#include <vlc/input.h>

#include "input_internal.h"

/* TODO:
 *  - tune the 2 methods
 *  - compute cost for seek
 *  - improve stream mode seeking with closest segments
 *  - ...
 */

/* Two methods:
 *  - using pf_block
 *      One linked list of data read
 *  - using pf_read
 *      More complex scheme using mutliple track to avoid seeking
 */

/* How many track we have, currently only used for stream mode */
#define STREAM_CACHE_TRACK 3
/* Max size of our cache 4Mo per track */
#define STREAM_CACHE_SIZE  (4*STREAM_CACHE_TRACK*1024*1024)
  /* How many data we try to prebuffer */
#define STREAM_CACHE_PREBUFFER_SIZE (32767)
/* Maximum time we take to pre-buffer */
#define STREAM_CACHE_PREBUFFER_LENGTH (100*1000)


/* Method1: Simple, for pf_block.
 *  We get blocks and put them in the linked list.
 *  We release blocks once the total size is bigger than CACHE_BLOCK_SIZE
 */
#define STREAM_DATA_WAIT 40000       /* Time between before a pf_block retry */

/* Method2: A bit more complex, for pf_read
 *  - We use ring buffers, only one if unseekable, all if seekable
 *  - Upon seek date current ring, then search if one ring match the pos,
 *      yes: switch to it, seek the access to match the end of the ring
 *      no: search the ring with i_end the closer to i_pos,
 *          if close enough, read data and use this ring
 *          else use the oldest ring, seek and use it.
 *
 *  TODO: - with access non seekable: use all space available for only one ring, but
 *          we have to support seekable/non-seekable switch on the fly.
 *        - compute a good value for i_read_size
 *        - ?
 */
#define STREAM_READ_ATONCE 32767
#define STREAM_CACHE_TRACK_SIZE (STREAM_CACHE_SIZE/STREAM_CACHE_TRACK)

typedef struct
{
    int64_t i_date;

    int64_t i_start;
    int64_t i_end;

    uint8_t *p_buffer;
} stream_track_t;

struct stream_sys_t
{
    access_t    *p_access;

    vlc_bool_t  b_block;    /* Block method (1) or stream */

    int64_t     i_pos;      /* Current reading offset */

    /* Method 1: pf_block */
    struct
    {
        int64_t i_start;        /* Offset of block for p_first */
        int     i_offset;       /* Offset for data in p_current */
        block_t *p_current;     /* Current block */

        int     i_size;         /* Total amount of data in the list */
        block_t *p_first;
        block_t **pp_last;
    } block;

    /* Method 2: for pf_read */
    struct
    {
        int i_offset;   /* Buffer offset in the current track */
        int i_tk;       /* Current track */
        stream_track_t tk[STREAM_CACHE_TRACK];

        /* Global buffer */
        uint8_t *p_buffer;

        /* */
        int i_used; /* Used since last read */
        int i_read_size;
    } stream;

    /* Peek temporary buffer */
    int     i_peek;
    uint8_t *p_peek;

    /* Stat for both method */
    struct
    {
        vlc_bool_t b_fastseek;  /* From access */

        /* Stat about reading data */
        int64_t i_read_count;
        int64_t i_bytes;
        int64_t i_read_time;

        /* Stat about seek */
        int     i_seek_count;
        int64_t i_seek_time;
    } stat;
};

/* Method 1: */
static int  AStreamReadBlock( stream_t *, void *p_read, int i_read );
static int  AStreamPeekBlock( stream_t *, uint8_t **p_peek, int i_read );
static int  AStreamSeekBlock( stream_t *s, int64_t i_pos );
static void AStreamPrebufferBlock( stream_t * );

/* Method 2 */
static int  AStreamReadStream( stream_t *, void *p_read, int i_read );
static int  AStreamPeekStream( stream_t *, uint8_t **pp_peek, int i_read );
static int  AStreamSeekStream( stream_t *s, int64_t i_pos );
static void AStreamPrebufferStream( stream_t * );

/* Common */
static int AStreamControl( stream_t *, int i_query, va_list );


/****************************************************************************
 * stream_AccessNew: create a stream from a access
 ****************************************************************************/
stream_t *stream_AccessNew( access_t *p_access )
{
    stream_t *s = vlc_object_create( p_access, VLC_OBJECT_STREAM );
    stream_sys_t *p_sys;

    if( !s )
        return NULL;

    /* Attach it now, needed for b_die */
    vlc_object_attach( s, p_access );

    s->pf_block  = NULL;
    s->pf_read   = NULL;    /* Set up later */
    s->pf_peek   = NULL;
    s->pf_control= AStreamControl;

    s->p_sys = p_sys = malloc( sizeof( stream_sys_t ) );

    /* Common field */
    p_sys->p_access = p_access;
    p_sys->b_block = p_access->pf_block ? VLC_TRUE : VLC_FALSE;
    p_sys->i_pos = p_access->info.i_pos;

    /* Stats */
    access2_Control( p_access, ACCESS_CAN_FASTSEEK, &p_sys->stat.b_fastseek );
    p_sys->stat.i_bytes = 0;
    p_sys->stat.i_read_time = 0;
    p_sys->stat.i_read_count = 0;
    p_sys->stat.i_seek_count = 0;
    p_sys->stat.i_seek_time = 0;

    /* Peek */
    p_sys->i_peek = 0;
    p_sys->p_peek = NULL;

    if( p_sys->b_block )
    {
        s->pf_read = AStreamReadBlock;
        s->pf_peek = AStreamPeekBlock;

        /* Init all fields of p_sys->block */
        p_sys->block.i_start = p_sys->i_pos;
        p_sys->block.i_offset = 0;
        p_sys->block.p_current = NULL;
        p_sys->block.i_size = 0;
        p_sys->block.p_first = NULL;
        p_sys->block.pp_last = &p_sys->block.p_first;

        /* Do the prebuffering */
        AStreamPrebufferBlock( s );

        if( p_sys->block.i_size <= 0 )
        {
            msg_Err( s, "cannot pre fill buffer" );
            goto error;
        }
    }
    else
    {
        int i;

        s->pf_read = AStreamReadStream;
        s->pf_peek = AStreamPeekStream;

        /* Allocate/Setup our tracks */
        p_sys->stream.i_offset = 0;
        p_sys->stream.i_tk     = 0;
        p_sys->stream.p_buffer = malloc( STREAM_CACHE_SIZE );
        p_sys->stream.i_used   = 0;
        access2_Control( p_access, ACCESS_GET_MTU,
                         &p_sys->stream.i_read_size );
        if( p_sys->stream.i_read_size <= 0 )
            p_sys->stream.i_read_size = STREAM_READ_ATONCE;
        else if( p_sys->stream.i_read_size <= 256 )
            p_sys->stream.i_read_size = 256;

        for( i = 0; i < STREAM_CACHE_TRACK; i++ )
        {
            p_sys->stream.tk[i].i_date  = 0;
            p_sys->stream.tk[i].i_start = p_sys->i_pos;
            p_sys->stream.tk[i].i_end   = p_sys->i_pos;
            p_sys->stream.tk[i].p_buffer=
                &p_sys->stream.p_buffer[i * STREAM_CACHE_TRACK_SIZE];
        }

        /* Do the prebuffering */
        AStreamPrebufferStream( s );

        if( p_sys->stream.tk[p_sys->stream.i_tk].i_end <= 0 )
        {
            msg_Err( s, "cannot pre fill buffer" );
            goto error;
        }
    }

    return s;

error:
    if( p_sys->b_block )
    {
        /* Nothing yet */
    }
    else
    {
        free( p_sys->stream.p_buffer );
    }
    free( s->p_sys );
    vlc_object_detach( s );
    vlc_object_destroy( s );
    return NULL;
}

/****************************************************************************
 * stream_AccessDelete:
 ****************************************************************************/
void stream_AccessDelete( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;

    vlc_object_detach( s );

    if( p_sys->b_block )
    {
        block_ChainRelease( p_sys->block.p_first );
    }
    else
    {
        free( p_sys->stream.p_buffer );
    }

    if( p_sys->p_peek )
        free( p_sys->p_peek );

    free( s->p_sys );
    vlc_object_destroy( s );
}

/****************************************************************************
 * stream_AccessReset:
 ****************************************************************************/
void stream_AccessReset( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;

    p_sys->i_pos = p_sys->p_access->info.i_pos;

    if( p_sys->b_block )
    {
        block_ChainRelease( p_sys->block.p_first );

        /* Init all fields of p_sys->block */
        p_sys->block.i_start = p_sys->i_pos;
        p_sys->block.i_offset = 0;
        p_sys->block.p_current = NULL;
        p_sys->block.i_size = 0;
        p_sys->block.p_first = NULL;
        p_sys->block.pp_last = &p_sys->block.p_first;

        /* Do the prebuffering */
        AStreamPrebufferBlock( s );
    }
    else
    {
        int i;

        /* Setup our tracks */
        p_sys->stream.i_offset = 0;
        p_sys->stream.i_tk     = 0;
        p_sys->stream.i_used   = 0;

        for( i = 0; i < STREAM_CACHE_TRACK; i++ )
        {
            p_sys->stream.tk[i].i_date  = 0;
            p_sys->stream.tk[i].i_start = p_sys->i_pos;
            p_sys->stream.tk[i].i_end   = p_sys->i_pos;
        }

        /* Do the prebuffering */
        AStreamPrebufferStream( s );
    }
}

/****************************************************************************
 * stream_AccessUpdate:
 ****************************************************************************/
void stream_AccessUpdate( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;
    p_sys->i_pos = p_sys->p_access->info.i_pos;
}

/****************************************************************************
 * AStreamControl:
 ****************************************************************************/
static int AStreamControl( stream_t *s, int i_query, va_list args )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;

    vlc_bool_t *p_bool;
    int64_t    *pi_64, i_64;
    int        i_int;

    switch( i_query )
    {
        case STREAM_GET_SIZE:
            pi_64 = (int64_t*)va_arg( args, int64_t * );
            *pi_64 = p_access->info.i_size;
            break;

        case STREAM_CAN_SEEK:
            p_bool = (vlc_bool_t*)va_arg( args, vlc_bool_t * );
            access2_Control( p_access, ACCESS_CAN_SEEK, p_bool );
            break;

        case STREAM_CAN_FASTSEEK:
            p_bool = (vlc_bool_t*)va_arg( args, vlc_bool_t * );
            access2_Control( p_access, ACCESS_CAN_FASTSEEK, p_bool );
            break;

        case STREAM_GET_POSITION:
            pi_64 = (int64_t*)va_arg( args, int64_t * );
            *pi_64 = p_sys->i_pos;
            break;

        case STREAM_SET_POSITION:
            i_64 = (int64_t)va_arg( args, int64_t );
            if( p_sys->b_block )
                return AStreamSeekBlock( s, i_64 );
            else
                return AStreamSeekStream( s, i_64 );

        case STREAM_GET_MTU:
            return VLC_EGENERIC;

        case STREAM_CONTROL_ACCESS:
            i_int = (int) va_arg( args, int );
            if( i_int != ACCESS_SET_PRIVATE_ID_STATE
                 && i_int != ACCESS_SET_PRIVATE_ID_CA )
            {
                msg_Err( s, "Hey, what are you thinking ?"
                            "DON'T USE STREAM_CONTROL_ACCESS !!!" );
                return VLC_EGENERIC;
            }
            return access2_vaControl( p_access, i_int, args );

        default:
            msg_Err( s, "invalid stream_vaControl query=0x%x", i_query );
            return VLC_EGENERIC;
    }
    return VLC_SUCCESS;
}



/****************************************************************************
 * Method 1:
 ****************************************************************************/
static void AStreamPrebufferBlock( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;

    int64_t i_first = 0;
    int64_t i_start;

    msg_Dbg( s, "pre buffering" );
    i_start = mdate();
    for( ;; )
    {
        int64_t i_date = mdate();
        block_t *b;

        if( s->b_die || p_sys->block.i_size > STREAM_CACHE_PREBUFFER_SIZE ||
            ( i_first > 0 && i_first + STREAM_CACHE_PREBUFFER_LENGTH < i_date ) )
        {
            int64_t i_byterate;

            /* Update stat */
            p_sys->stat.i_bytes = p_sys->block.i_size;
            p_sys->stat.i_read_time = i_date - i_start;
            i_byterate = ( I64C(1000000) * p_sys->stat.i_bytes ) /
                         (p_sys->stat.i_read_time + 1);

            msg_Dbg( s, "prebuffering done "I64Fd" bytes in "I64Fd"s - "
                     I64Fd" kbytes/s",
                     p_sys->stat.i_bytes,
                     p_sys->stat.i_read_time / I64C(1000000),
                     i_byterate / 1024 );
            break;
        }

        /* Fetch a block */
        if( ( b = p_access->pf_block( p_access ) ) == NULL )
        {
            if( p_access->info.b_eof )
                break;

            msleep( STREAM_DATA_WAIT );
            continue;
        }

        if( i_first == 0 )
        {
            i_first = mdate();
            msg_Dbg( s, "received first data for our buffer");
        }

        /* Append the block */
        p_sys->block.i_size += b->i_buffer;
        *p_sys->block.pp_last = b;
        p_sys->block.pp_last = &b->p_next;

        p_sys->stat.i_read_count++;
    }

    p_sys->block.p_current = p_sys->block.p_first;
}

static int AStreamRefillBlock( stream_t *s );

static int AStreamReadBlock( stream_t *s, void *p_read, int i_read )
{
    stream_sys_t *p_sys = s->p_sys;

    uint8_t *p_data= (uint8_t*)p_read;
    int     i_data = 0;

    /* It means EOF */
    if( p_sys->block.p_current == NULL )
        return 0;

    if( p_read == NULL )
    {
	/* seek within this stream if possible, else use plain old read and discard */
        stream_sys_t *p_sys = s->p_sys;
        access_t     *p_access = p_sys->p_access;
        vlc_bool_t   b_aseek;
        access2_Control( p_access, ACCESS_CAN_SEEK, &b_aseek );
        if( b_aseek )
            return AStreamSeekBlock( s, p_sys->i_pos + i_read ) ? 0 : i_read;
    }

    while( i_data < i_read )
    {
        int i_current =
            p_sys->block.p_current->i_buffer - p_sys->block.i_offset;
        int i_copy = __MIN( i_current, i_read - i_data);

        /* Copy data */
        if( p_data )
        {
            memcpy( p_data,
                    &p_sys->block.p_current->p_buffer[p_sys->block.i_offset],
                    i_copy );
            p_data += i_copy;
        }
        i_data += i_copy;

        p_sys->block.i_offset += i_copy;
        if( p_sys->block.i_offset >= p_sys->block.p_current->i_buffer )
        {
            /* Current block is now empty, switch to next */
            if( p_sys->block.p_current )
            {
                p_sys->block.i_offset = 0;
                p_sys->block.p_current = p_sys->block.p_current->p_next;
            }
            /*Get a new block */
            if( AStreamRefillBlock( s ) )
            {
                break;
            }
        }
    }

    p_sys->i_pos += i_data;
    return i_data;
}

static int AStreamPeekBlock( stream_t *s, uint8_t **pp_peek, int i_read )
{
    stream_sys_t *p_sys = s->p_sys;
    uint8_t *p_data;
    int      i_data = 0;
    block_t *b;
    int      i_offset;

    if( p_sys->block.p_current == NULL ) return 0; /* EOF */

    /* We can directly give a pointer over our buffer */
    if( i_read <= p_sys->block.p_current->i_buffer - p_sys->block.i_offset )
    {
        *pp_peek = &p_sys->block.p_current->p_buffer[p_sys->block.i_offset];
        return i_read;
    }

    /* We need to create a local copy */
    if( p_sys->i_peek < i_read )
    {
        if( p_sys->p_peek )
            free( p_sys->p_peek );
        p_sys->i_peek = i_read;
        p_sys->p_peek = malloc( p_sys->i_peek );
    }

    /* Fill enough data */
    while( p_sys->block.i_size - (p_sys->i_pos - p_sys->block.i_start)
           < i_read )
    {
        block_t **pp_last = p_sys->block.pp_last;

        if( AStreamRefillBlock( s ) )
            break;

        /* Our buffer are probably filled enough, don't try anymore */
        if( pp_last == p_sys->block.pp_last )
            break;
    }

    /* Copy what we have */
    b = p_sys->block.p_current;
    i_offset = p_sys->block.i_offset;
    p_data = p_sys->p_peek;

    while( b && i_data < i_read )
    {
        int i_current = b->i_buffer - i_offset;
        int i_copy = __MIN( i_current, i_read - i_data );

        memcpy( p_data, &b->p_buffer[i_offset], i_copy );
        i_data += i_copy;
        p_data += i_copy;
        i_offset += i_copy;

        if( i_offset >= b->i_buffer )
        {
            i_offset = 0;
            b = b->p_next;
        }
    }

    *pp_peek = p_sys->p_peek;
    return i_data;
}

static int AStreamSeekBlock( stream_t *s, int64_t i_pos )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t   *p_access = p_sys->p_access;
    int64_t    i_offset = i_pos - p_sys->block.i_start;
    vlc_bool_t b_seek;

    /* We already have thoses data, just update p_current/i_offset */
    if( i_offset >= 0 && i_offset < p_sys->block.i_size )
    {
        block_t *b = p_sys->block.p_first;
        int i_current = 0;

        while( i_current + b->i_buffer < i_offset )
        {
            i_current += b->i_buffer;
            b = b->p_next;
        }

        p_sys->block.p_current = b;
        p_sys->block.i_offset = i_offset - i_current;

        p_sys->i_pos = i_pos;

        return VLC_SUCCESS;
    }

    /* We may need to seek or to read data */
    if( i_offset < 0 )
    {
        vlc_bool_t b_aseek;
        access2_Control( p_access, ACCESS_CAN_SEEK, &b_aseek );

        if( !b_aseek )
        {
            msg_Err( s, "backward seek impossible (access non seekable)" );
            return VLC_EGENERIC;
        }

        b_seek = VLC_TRUE;
    }
    else
    {
        vlc_bool_t b_aseek, b_aseekfast;

        access2_Control( p_access, ACCESS_CAN_SEEK, &b_aseek );
        access2_Control( p_access, ACCESS_CAN_FASTSEEK, &b_aseekfast );

        if( !b_aseek )
        {
            b_seek = VLC_FALSE;
            msg_Warn( s, I64Fd" bytes need to be skipped "
                      "(access non seekable)",
                      i_offset - p_sys->block.i_size );
        }
        else
        {
            int64_t i_skip = i_offset - p_sys->block.i_size;

            /* Avg bytes per packets */
            int i_avg = p_sys->stat.i_bytes / p_sys->stat.i_read_count;
            /* TODO compute a seek cost instead of fixed threshold */
            int i_th = b_aseekfast ? 1 : 5;

            if( i_skip <= i_th * i_avg &&
                i_skip < STREAM_CACHE_SIZE )
                b_seek = VLC_FALSE;
            else
                b_seek = VLC_TRUE;

            msg_Dbg( s, "b_seek=%d th*avg=%d skip="I64Fd,
                     b_seek, i_th*i_avg, i_skip );
        }
    }

    if( b_seek )
    {
        int64_t i_start, i_end;
        /* Do the access seek */
        i_start = mdate();
        if( p_access->pf_seek( p_access, i_pos ) )
            return VLC_EGENERIC;
        i_end = mdate();

        /* Release data */
        block_ChainRelease( p_sys->block.p_first );

        /* Reinit */
        p_sys->block.i_start = p_sys->i_pos = i_pos;
        p_sys->block.i_offset = 0;
        p_sys->block.p_current = NULL;
        p_sys->block.i_size = 0;
        p_sys->block.p_first = NULL;
        p_sys->block.pp_last = &p_sys->block.p_first;

        /* Refill a block */
        if( AStreamRefillBlock( s ) )
        {
            msg_Err( s, "cannot re fill buffer" );
            return VLC_EGENERIC;
        }
        /* Update stat */
        p_sys->stat.i_seek_time += i_end - i_start;
        p_sys->stat.i_seek_count++;
        return VLC_SUCCESS;
    }
    else
    {
        /* Read enought data */
        while( p_sys->block.i_start + p_sys->block.i_size < i_pos )
        {
            if( AStreamRefillBlock( s ) )
            {
                msg_Err( s, "can't read enough data in seek" );
                return VLC_EGENERIC;
            }
            while( p_sys->block.p_current &&
                   p_sys->i_pos + p_sys->block.p_current->i_buffer < i_pos )
            {
                p_sys->i_pos += p_sys->block.p_current->i_buffer;
                p_sys->block.p_current = p_sys->block.p_current->p_next;
            }
        }

        p_sys->block.i_offset = i_pos - p_sys->i_pos;
        p_sys->i_pos = i_pos;

        /* TODO read data */
        return VLC_SUCCESS;
    }

    return VLC_EGENERIC;
}

static int AStreamRefillBlock( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;
    int64_t      i_start, i_stop;
    block_t      *b;

    /* Release data */
    while( p_sys->block.i_size >= STREAM_CACHE_SIZE &&
           p_sys->block.p_first != p_sys->block.p_current )
    {
        block_t *b = p_sys->block.p_first;

        p_sys->block.i_start += b->i_buffer;
        p_sys->block.i_size  -= b->i_buffer;
        p_sys->block.p_first  = b->p_next;

        block_Release( b );
    }
    if( p_sys->block.i_size >= STREAM_CACHE_SIZE &&
        p_sys->block.p_current == p_sys->block.p_first &&
        p_sys->block.p_current->p_next )    /* At least 2 packets */
    {
        /* Enough data, don't read more */
        return VLC_SUCCESS;
    }

    /* Now read a new block */
    i_start = mdate();
    for( ;; )
    {
        if( s->b_die )
            return VLC_EGENERIC;


        /* Fetch a block */
        if( ( b = p_access->pf_block( p_access ) ) )
            break;

        if( p_access->info.b_eof )
            return VLC_EGENERIC;

        msleep( STREAM_DATA_WAIT );
    }
    i_stop = mdate();

    /* Append the block */
    p_sys->block.i_size += b->i_buffer;
    *p_sys->block.pp_last = b;
    p_sys->block.pp_last = &b->p_next;

    /* Fix p_current */
    if( p_sys->block.p_current == NULL )
        p_sys->block.p_current = b;

    /* Update stat */
    p_sys->stat.i_bytes += b->i_buffer;
    p_sys->stat.i_read_time += i_stop - i_start;
    p_sys->stat.i_read_count++;

    return VLC_SUCCESS;
}


/****************************************************************************
 * Method 2:
 ****************************************************************************/
static int AStreamRefillStream( stream_t *s );

static int AStreamReadStream( stream_t *s, void *p_read, int i_read )
{
    stream_sys_t *p_sys = s->p_sys;
    stream_track_t *tk = &p_sys->stream.tk[p_sys->stream.i_tk];

    uint8_t *p_data = (uint8_t *)p_read;
    int      i_data = 0;

    if( tk->i_start >= tk->i_end ) return 0; /* EOF */

    if( p_read == NULL )
    {
	/* seek within this stream if possible, else use plain old read and discard */
        stream_sys_t *p_sys = s->p_sys;
        access_t     *p_access = p_sys->p_access;
        vlc_bool_t   b_aseek;
        access2_Control( p_access, ACCESS_CAN_SEEK, &b_aseek );
        if( b_aseek )
            return AStreamSeekStream( s, p_sys->i_pos + i_read ) ? 0 : i_read;
    }

#if 0
    msg_Dbg( s, "AStreamReadStream: %d pos="I64Fd" tk=%d start="I64Fd
             " offset=%d end="I64Fd,
             i_read, p_sys->i_pos, p_sys->stream.i_tk,
             tk->i_start, p_sys->stream.i_offset, tk->i_end );
#endif

    while( i_data < i_read )
    {
        int i_off = (tk->i_start + p_sys->stream.i_offset) %
                    STREAM_CACHE_TRACK_SIZE;
        int i_current =
            __MIN( tk->i_end - tk->i_start - p_sys->stream.i_offset,
                   STREAM_CACHE_TRACK_SIZE - i_off );
        int i_copy = __MIN( i_current, i_read - i_data );

        if( i_copy <= 0 ) break; /* EOF */

        /* Copy data */
        /* msg_Dbg( s, "AStreamReadStream: copy %d", i_copy ); */
        if( p_data )
        {
            memcpy( p_data, &tk->p_buffer[i_off], i_copy );
            p_data += i_copy;
        }
        i_data += i_copy;
        p_sys->stream.i_offset += i_copy;

        /* Update pos now */
        p_sys->i_pos += i_copy;

        /* */
        p_sys->stream.i_used += i_copy;
        if( tk->i_start + p_sys->stream.i_offset >= tk->i_end ||
            p_sys->stream.i_used >= p_sys->stream.i_read_size )
        {
            if( AStreamRefillStream( s ) )
            {
                /* EOF */
                if( tk->i_start >= tk->i_end ) break;
            }
        }
    }

    return i_data;
}

static int AStreamPeekStream( stream_t *s, uint8_t **pp_peek, int i_read )
{
    stream_sys_t *p_sys = s->p_sys;
    stream_track_t *tk = &p_sys->stream.tk[p_sys->stream.i_tk];
    int64_t i_off;

    if( tk->i_start >= tk->i_end ) return 0; /* EOF */

#if 0
    msg_Dbg( s, "AStreamPeekStream: %d pos="I64Fd" tk=%d "
             "start="I64Fd" offset=%d end="I64Fd,
             i_read, p_sys->i_pos, p_sys->stream.i_tk,
             tk->i_start, p_sys->stream.i_offset, tk->i_end );
#endif

    /* Avoid problem, but that should *never* happen */
    if( i_read > STREAM_CACHE_TRACK_SIZE / 2 )
        i_read = STREAM_CACHE_TRACK_SIZE / 2;

    while( tk->i_end - tk->i_start - p_sys->stream.i_offset < i_read )
    {
        if( p_sys->stream.i_used <= 1 )
        {
            /* Be sure we will read something */
            p_sys->stream.i_used += i_read - (tk->i_end - tk->i_start - p_sys->stream.i_offset);
        }
        if( AStreamRefillStream( s ) )
            break;
    }

    if( tk->i_end - tk->i_start - p_sys->stream.i_offset < i_read )
        i_read = tk->i_end - tk->i_start - p_sys->stream.i_offset;

    /* Now, direct pointer or a copy ? */
    i_off = (tk->i_start + p_sys->stream.i_offset) % STREAM_CACHE_TRACK_SIZE;
    if( i_off + i_read <= STREAM_CACHE_TRACK_SIZE )
    {
        *pp_peek = &tk->p_buffer[i_off];
        return i_read;
    }

    if( p_sys->i_peek < i_read )
    {
        if( p_sys->p_peek ) free( p_sys->p_peek );
        p_sys->i_peek = i_read;
        p_sys->p_peek = malloc( i_read );
    }

    memcpy( p_sys->p_peek, &tk->p_buffer[i_off],
            STREAM_CACHE_TRACK_SIZE - i_off );
    memcpy( &p_sys->p_peek[STREAM_CACHE_TRACK_SIZE - i_off],
            &tk->p_buffer[0], i_read - (STREAM_CACHE_TRACK_SIZE - i_off) );

    *pp_peek = p_sys->p_peek;
    return i_read;
}

static int AStreamSeekStream( stream_t *s, int64_t i_pos )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;
    vlc_bool_t   b_aseek;
    vlc_bool_t   b_afastseek;
    int i_maxth;
    int i_new;
    int i;

#if 0
    msg_Dbg( s, "AStreamSeekStream: to "I64Fd" pos="I64Fd
             "tk=%d start="I64Fd" offset=%d end="I64Fd,
             i_pos, p_sys->i_pos, p_sys->stream.i_tk,
             p_sys->stream.tk[p_sys->stream.i_tk].i_start,
             p_sys->stream.i_offset,
             p_sys->stream.tk[p_sys->stream.i_tk].i_end );
#endif


    /* Seek in our current track ? */
    if( i_pos >= p_sys->stream.tk[p_sys->stream.i_tk].i_start &&
        i_pos < p_sys->stream.tk[p_sys->stream.i_tk].i_end )
    {
        //msg_Dbg( s, "AStreamSeekStream: current track" );
        p_sys->i_pos = i_pos;
        p_sys->stream.i_offset = i_pos - p_sys->stream.tk[p_sys->stream.i_tk].i_start;
        return VLC_SUCCESS;
    }

    access2_Control( p_access, ACCESS_CAN_SEEK, &b_aseek );
    if( !b_aseek )
    {
        /* We can't do nothing */
        msg_Dbg( s, "AStreamSeekStream: can't seek" );
        return VLC_EGENERIC;
    }

    /* Date the current track */
    p_sys->stream.tk[p_sys->stream.i_tk].i_date = mdate();

    /* Try to reuse already read data */
    for( i = 0; i < STREAM_CACHE_TRACK; i++ )
    {
        stream_track_t *tk = &p_sys->stream.tk[i];

        if( i_pos >= tk->i_start && i_pos <= tk->i_end )
        {
#if 0
            msg_Dbg( s, "AStreamSeekStream: reusing %d start="I64Fd
                     " end="I64Fd, i, tk->i_start, tk->i_end );
#endif
            /* Seek at the end of the buffer */
            if( p_access->pf_seek( p_access, tk->i_end ) )
                return VLC_EGENERIC;

            /* That's it */
            p_sys->i_pos = i_pos;
            p_sys->stream.i_tk = i;
            p_sys->stream.i_offset = i_pos - tk->i_start;

            if( p_sys->stream.i_used < 1024 )
                p_sys->stream.i_used = 1024;

            if( AStreamRefillStream( s ) )
                return VLC_EGENERIC;

            return VLC_SUCCESS;
        }
    }

    access2_Control( p_access, ACCESS_CAN_SEEK, &b_afastseek );
    /* FIXME compute seek cost (instead of static 'stupid' value) */
    i_maxth = __MIN( p_sys->stream.i_read_size, STREAM_READ_ATONCE / 2 );
    if( !b_afastseek )
        i_maxth *= 3;

    /* FIXME TODO */
#if 0
    /* Search closest segment TODO */
    for( i = 0; i < STREAM_CACHE_TRACK; i++ )
    {
        stream_track_t *tk = &p_sys->stream.tk[i];

        if( i_pos + i_maxth >= tk->i_start )
        {
            msg_Dbg( s, "good segment before current pos, TODO" );
        }
        if( i_pos - i_maxth <= tk->i_end )
        {
            msg_Dbg( s, "good segment after current pos, TODO" );
        }
    }
#endif

    /* Nothing good, seek and choose oldest segment */
    if( p_access->pf_seek( p_access, i_pos ) )
        return VLC_EGENERIC;
    p_sys->i_pos = i_pos;

    i_new = 0;
    for( i = 1; i < STREAM_CACHE_TRACK; i++ )
    {
        if( p_sys->stream.tk[i].i_date < p_sys->stream.tk[i_new].i_date )
            i_new = i;
    }

    /* Reset the segment */
    p_sys->stream.i_tk     = i_new;
    p_sys->stream.i_offset =  0;
    p_sys->stream.tk[i_new].i_start = i_pos;
    p_sys->stream.tk[i_new].i_end   = i_pos;

    /* Read data */
    if( p_sys->stream.i_used < STREAM_READ_ATONCE / 2 )
        p_sys->stream.i_used = STREAM_READ_ATONCE / 2;

    if( AStreamRefillStream( s ) )
        return VLC_EGENERIC;

    return VLC_SUCCESS;
}

static int AStreamRefillStream( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;
    stream_track_t *tk = &p_sys->stream.tk[p_sys->stream.i_tk];

    /* We read but won't increase i_start after initial start + offset */
    int i_toread =
        __MIN( p_sys->stream.i_used, STREAM_CACHE_TRACK_SIZE -
               (tk->i_end - tk->i_start - p_sys->stream.i_offset) );
    vlc_bool_t b_read = VLC_FALSE;
    int64_t i_start, i_stop;

    if( i_toread <= 0 ) return VLC_EGENERIC; /* EOF */

    /* msg_Dbg( s, "AStreamRefillStream: toread=%d", i_toread ); */

    i_start = mdate();
    while( i_toread > 0 )
    {
        int i_off = tk->i_end % STREAM_CACHE_TRACK_SIZE;
        int i_read;

        if( s->b_die )
            return VLC_EGENERIC;

        i_read = __MIN( i_toread, STREAM_CACHE_TRACK_SIZE - i_off );
        i_read = p_access->pf_read( p_access, &tk->p_buffer[i_off], i_read );

        /* msg_Dbg( s, "AStreamRefillStream: read=%d", i_read ); */
        if( i_read <  0 )
        {
            msleep( STREAM_DATA_WAIT );
            continue;
        }
        else if( i_read == 0 )
        {
            if( !b_read )
                return VLC_EGENERIC;
            return VLC_SUCCESS;
        }
        b_read = VLC_TRUE;

        /* Update end */
        tk->i_end += i_read;

        /* Windows of STREAM_CACHE_TRACK_SIZE */
        if( tk->i_end - tk->i_start > STREAM_CACHE_TRACK_SIZE )
        {
            int i_invalid = tk->i_end - tk->i_start - STREAM_CACHE_TRACK_SIZE;

            tk->i_start += i_invalid;
            p_sys->stream.i_offset -= i_invalid;
        }

        i_toread -= i_read;
        p_sys->stream.i_used -= i_read;

        p_sys->stat.i_bytes += i_read;
        p_sys->stat.i_read_count++;
    }
    i_stop = mdate();

    p_sys->stat.i_read_time += i_stop - i_start;

    return VLC_SUCCESS;
}

static void AStreamPrebufferStream( stream_t *s )
{
    stream_sys_t *p_sys = s->p_sys;
    access_t     *p_access = p_sys->p_access;

    int64_t i_first = 0;
    int64_t i_start;
    int64_t i_prebuffer = (s->p_sys->p_access->info.i_title > 1 ||
                           s->p_sys->p_access->info.i_seekpoint > 1) ? STREAM_CACHE_PREBUFFER_SIZE : STREAM_CACHE_TRACK_SIZE / 3;

    msg_Dbg( s, "pre buffering" );
    i_start = mdate();
    for( ;; )
    {
        stream_track_t *tk = &p_sys->stream.tk[p_sys->stream.i_tk];

        int64_t i_date = mdate();
        int i_read;

        if( s->b_die || tk->i_end >= i_prebuffer ||
            (i_first > 0 && i_first + STREAM_CACHE_PREBUFFER_LENGTH < i_date) )
        {
            int64_t i_byterate;

            /* Update stat */
            p_sys->stat.i_bytes = tk->i_end - tk->i_start;
            p_sys->stat.i_read_time = i_date - i_start;
            i_byterate = ( I64C(1000000) * p_sys->stat.i_bytes ) /
                         (p_sys->stat.i_read_time+1);

            msg_Dbg( s, "prebuffering done "I64Fd" bytes in "I64Fd"s - "
                     I64Fd" kbytes/s",
                     p_sys->stat.i_bytes,
                     p_sys->stat.i_read_time / I64C(1000000),
                     i_byterate / 1024 );
            break;
        }

        /* */
        i_read = STREAM_CACHE_TRACK_SIZE - tk->i_end;
        i_read = __MIN( p_sys->stream.i_read_size, i_read );
        i_read = p_access->pf_read( p_access, &tk->p_buffer[tk->i_end],
                                    i_read );
        if( i_read <  0 )
        {
            msleep( STREAM_DATA_WAIT );
            continue;
        }
        else if( i_read == 0 )
        {
            /* EOF */
            break;
        }

        if( i_first == 0 )
        {
            i_first = mdate();
            msg_Dbg( s, "received first data for our buffer");
        }

        tk->i_end += i_read;

        p_sys->stat.i_read_count++;
    }
}


/****************************************************************************
 * stream_ReadLine:
 ****************************************************************************/
/**
 * Read from the stream untill first newline.
 * \param s Stream handle to read from
 * \return A null-terminated string. This must be freed,
 */
#define STREAM_PROBE_LINE 2048
#define STREAM_LINE_MAX (2048*100)
char *stream_ReadLine( stream_t *s )
{
    char *p_line = NULL;
    int i_line = 0, i_read = 0;

    while( i_read < STREAM_LINE_MAX )
    {
        char *psz_eol;
        uint8_t *p_data;
        int i_data;

        /* Probe new data */
        i_data = stream_Peek( s, &p_data, STREAM_PROBE_LINE );
        if( i_data <= 0 ) break; /* No more data */

        /* Check if there is an EOL */
        if( ( psz_eol = memchr( p_data, '\n', i_data ) ) )
        {
            i_data = (psz_eol - (char *)p_data) + 1;
            p_line = realloc( p_line, i_line + i_data + 1 );
            i_data = stream_Read( s, &p_line[i_line], i_data );
            if( i_data <= 0 ) break; /* Hmmm */
            i_line += (i_data - 1);
            i_read += i_data;

            /* We have our line */
            break;
        }

        /* Read data (+1 for easy \0 append) */
        p_line = realloc( p_line, i_line + STREAM_PROBE_LINE + 1 );
        i_data = stream_Read( s, &p_line[i_line], STREAM_PROBE_LINE );
        if( i_data <= 0 ) break; /* Hmmm */
        i_line += i_data;
        i_read += i_data;
    }

    /* Remove trailing LF/CR */
    while( i_line > 0 && ( p_line[i_line-1] == '\r' ||
           p_line[i_line-1] == '\n') ) i_line--;

    if( i_read > 0 )
    {
        p_line[i_line] = '\0';
        return p_line;
    }

    /* We failed to read any data, probably EOF */
    if( p_line ) free( p_line );
    return NULL;
}
