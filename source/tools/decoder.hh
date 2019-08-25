/*
 * Game Genie Encoder/Decoder
 * Copyright (C) 2004-2005 emuWorks
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
 
// $Id: decoder.hh,v 1.4 2005/07/30 04:31:38 technoplaza Exp $

#ifndef _DECODER_HH
#define _DECODER_HH

namespace emuWorks {
    class GameGenieCode;
    class NESRawCode;
    class SNESRawCode;
    class GenesisRawCode;
    class GBGGRawCode;
    
    /**
     * Class to decode game genie codes into raw/PAR codes.
     */
    class Decoder {
    public:
        /**
         * Decodes NES game genie code into an NESRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded NESRawCode.
         */
        static NESRawCode decodeNES(GameGenieCode &code);
        
        /**
         * Decodes SNES game genie code into an SNESRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded SNESRawCode.
         */
        static SNESRawCode decodeSNES(GameGenieCode &code);
        
        /**
         * Decodes Genesis game genie code into a GenesisRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded GenesisRawCode.
         */
        static GenesisRawCode decodeGenesis(GameGenieCode &code);
        
        /**
         * Decodes Game Boy or Game Gear game genie code into a GBGGRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded GBGGRawCode.
         */
        static GBGGRawCode decodeGBGG(GameGenieCode &code);
    private:
        /**
         * Private constructor to prevent instantiation.
         */
        Decoder() {}
    };
}

#endif

