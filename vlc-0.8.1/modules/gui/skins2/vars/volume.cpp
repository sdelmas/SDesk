/*****************************************************************************
 * volume.cpp
 *****************************************************************************
 * Copyright (C) 2003 VideoLAN
 * $Id: volume.cpp 6961 2004-03-05 17:34:23Z sam $
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teuli�re <ipkiss@via.ecp.fr>
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

#include <stdio.h>  // snprintf

#include <vlc/aout.h>
#include "volume.hpp"


Volume::Volume( intf_thread_t *pIntf ): VarPercent( pIntf )
{
    // Initial value
    audio_volume_t val;
    aout_VolumeGet( getIntf(), &val );
    VarPercent::set( val / AOUT_VOLUME_MAX );
}


void Volume::set( float percentage )
{
    // Avoid looping forever...
    if( (int)(get() * AOUT_VOLUME_MAX) !=
        (int)(percentage * AOUT_VOLUME_MAX) )
    {
        VarPercent::set( percentage );

        aout_VolumeSet( getIntf(), (int)(get() * AOUT_VOLUME_MAX) );
    }
}


string Volume::getAsStringPercent() const
{
    int value = (int)(100. * VarPercent::get());
    // 0 <= value <= 100, so we need 4 chars
    char *str = new char[4];
    snprintf( str, 4, "%d", value );
    string ret = str;
    delete[] str;

    return ret;
}

