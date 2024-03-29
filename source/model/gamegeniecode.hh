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

#ifndef GGENCODER_GAMEGENIECODE_HH_
#define GGENCODER_GAMEGENIECODE_HH_

#include <QString>

namespace ggencoder {
    /**
     * Interface for a Game Genie code.
     */
    class GameGenieCode {
      private:
        QString code;

      public:
        /**
         * Virtual destructor for a GameGenieCode.
         */
        virtual ~GameGenieCode();

        /**
         * Gets the game genie alphabet.
         *
         * @return The genie alphabet array.
         */
        virtual const char *getAlphabet() const = 0;

        /**
         * Gets the number of letters in the game genie alphabet.
         *
         * @return The alphabet letter count.
         */
        virtual int getAlphabetCount() const;

        /**
         * Gets the game genie code.
         *
         * @return The game genie code.
         */
        const QString &getCode() const;

        /**
         * Sets the game genie code.
         *
         * @param code The new game genie code.
         */
        void setCode(const QString &code);

        /**
         * Gets the corresponding hex value for a particular game genie letter.
         *
         * @param letter The game genie letter.
         *
         * @return The hex value of the letter or -1 if the letter is invalid.
         */
        virtual int toHex(char letter) const;
    };

    inline GameGenieCode::~GameGenieCode() {}
    inline int GameGenieCode::getAlphabetCount() const {
        return 16;
    }
    inline const QString &GameGenieCode::getCode() const {
        return code;
    }
    inline void GameGenieCode::setCode(const QString &code) {
        this->code = code.toUpper();
    }
}  // namespace ggencoder

#endif
