/*****************************************************************************
 * input.h: input modules header for vlc
 *****************************************************************************
 * Copyright (C) 2002 VideoLAN
 * $Id: input.h 8007 2004-06-22 19:29:19Z fenrir $
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

#ifndef _VLC_INPUT_H
#define _VLC_INPUT_H 1

# ifdef __cplusplus
extern "C" {
# endif

/*****************************************************************************
 * Required public headers
 *****************************************************************************/
#include <vlc/vlc.h>

/*****************************************************************************
 * Required internal headers
 *****************************************************************************/
#include "vlc_block.h"

#include "vlc_es.h"
#include "vlc_es_out.h"

#include "vlc_input.h"

#include "vlc_access.h"
#include "vlc_stream.h"
#include "vlc_demux.h"

# ifdef __cplusplus
}
# endif

#endif /* <vlc/input.h> */
