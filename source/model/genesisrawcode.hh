/*
 * Game Genie Encoder/Decoder
 * Copyright (C) 2004-2006,2008 emuWorks
 * http://games.technoplaza.net/
 *
 * This file is part of Game Genie Encoder/Decoder.
 *
 * Game Genie Encoder/Decoder is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Game Genie Encoder/Decoder is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Game Genie Encoder/Decoder; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
// $Id: genesisrawcode.hh,v 1.6 2008/12/18 03:23:30 jdratlif Exp $

#ifndef GGENCODER_GENESISRAWCODE_HH_
#define GGENCODER_GENESISRAWCODE_HH_

#include "model/rawcode.hh"

namespace ggencoder {
    /**
     * Implementation of a Genesis raw (or PAR) code.
     */
    class GenesisRawCode : public RawCode {
    public:
        /**
         * Constructor for an GenesisRawCode.
         *
         * @param address The code's address.
         * @param value The code's value.
         */
        GenesisRawCode(int address, int value);
        
        /**
         * Sets the address of this RawCode.
         *
         * @param address The new address.
         */
        void setAddress(int address);
        
        /**
         * Sets the value of this RawCode.
         *
         * @param value The new value.
         */
        void setValue(int value);
    };
}

#endif

