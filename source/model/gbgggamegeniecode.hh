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
 
// $Id: gbgggamegeniecode.hh,v 1.3 2005/07/30 02:36:45 technoplaza Exp $

#ifndef _GBGGGAMEGENIECODE_HH
#define _GBGGGAMEGENIECODE_HH

#include "gamegeniecode.hh"

namespace emuWorks {
    /**
     * An implementation of a Game Boy or Game Gear game genie code.
     */
    class GBGGGameGenieCode : public GameGenieCode {
    public:
        /**
         * Creates a GBGGGameGenieCode object.
         *
         * @param code The game genie code string.
         *
         * @throws InvalidGameGenieCode if the code is invalid.
         */
        static GBGGGameGenieCode create(QString &code);
    
        /**
         * Checks if the code is a valid game genie code.
         *
         * @param code The code to check.
         *
         * @return true if valid; false otherwise.
         */
        static bool isValidCode(QString &code);
        
        /**
         * Gets the game genie alphabet.
         *
         * @return The genie alphabet array.
         */
        const char *getAlphabet();
        
        /**
         * The game genie alphabet.
         */
        static const char ALPHABET[];
    private:
        /**
         * Constructor for an GBGGGameGenieCode.
         */
        GBGGGameGenieCode(QString &code) { setCode(code); }
    };
}

#endif

