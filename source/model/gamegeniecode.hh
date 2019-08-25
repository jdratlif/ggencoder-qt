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
 
// $Id: gamegeniecode.hh,v 1.5 2005/07/30 04:31:38 technoplaza Exp $

#ifndef _GAMEGENIECODE_HH
#define _GAMEGENIECODE_HH

#include <QString>

namespace emuWorks {
    /**
     * Interface for a Game Genie code.
     */
    class GameGenieCode {
    public:
        /**
         * Virtual destructor for a GameGenieCode.
         */
        virtual ~GameGenieCode() {}
    
        /**
         * Gets the game genie code.
         *
         * @return The game genie code.
         */
        QString getCode() { return code; }
        
        /**
         * Sets the game genie code.
         *
         * @param code The new game genie code.
         */
        void setCode(QString &code) { this->code = code.toUpper(); }
        
        /**
         * Gets the game genie alphabet.
         *
         * @return The genie alphabet array.
         */
        virtual const char *getAlphabet() = 0;
        
        /**
         * Gets the number of letters in the game genie alphabet.
         *
         * @return The alphabet letter count.
         */
        virtual int getAlphabetCount() { return 16; } 
        
        /**
         * Gets the corresponding hex value for a particular game genie letter.
         *
         * @param letter The game genie letter.
         *
         * @return The hex value of the letter or -1 if the letter is invalid.
         */
        virtual int toHex(char letter);
    protected:
        QString code;
    };
}

#endif

