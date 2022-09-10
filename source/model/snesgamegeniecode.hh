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

#ifndef GGENCODER_SNESGAMEGENIECODE_HH_
#define GGENCODER_SNESGAMEGENIECODE_HH_

#include "exceptions/invalidgamegeniecode.hh"

#include "model/gamegeniecode.hh"

namespace ggencoder {
    /**
     * An implementation of an SNES game genie code.
     */
    class SNESGameGenieCode : public GameGenieCode {
      private:
        /**
         * Constructor for an SNESGameGenieCode.
         */
        SNESGameGenieCode(const QString &code);

      public:
        /// The game genie alphabet.
        static const char ALPHABET[];

        /**
         * Creates an SNESGameGenieCode object.
         *
         * @param code The game genie code string.
         *
         * @throws InvalidGameGenieCodeException if the code is invalid.
         */
        static SNESGameGenieCode
        create(const QString &code) throw(InvalidGameGenieCodeException);

        /**
         * Gets the game genie alphabet.
         *
         * @return The genie alphabet array.
         */
        const char *getAlphabet() const;

        /**
         * Checks if the code is a valid game genie code.
         *
         * @param code The code to check.
         *
         * @return true if valid; false otherwise.
         */
        static bool isValidCode(const QString &code);
    };

    inline SNESGameGenieCode::SNESGameGenieCode(const QString &code) {
        setCode(code);
    }
}  // namespace ggencoder

#endif
