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

#ifndef GGENCODER_DECODER_HH_
#define GGENCODER_DECODER_HH_

namespace ggencoder {
    class GameGenieCode;
    class GBGGRawCode;
    class GenesisRawCode;
    class NESRawCode;
    class SNESRawCode;

    /**
     * Class to decode game genie codes into raw/PAR codes.
     */
    class Decoder {
      private:
        /**
         * Private constructor to prevent instantiation.
         */
        Decoder();

      public:
        /**
         * Decodes Game Boy or Game Gear game genie code into a GBGGRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded GBGGRawCode.
         */
        static GBGGRawCode decodeGBGG(const GameGenieCode &code);

        /**
         * Decodes Genesis game genie code into a GenesisRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded GenesisRawCode.
         */
        static GenesisRawCode decodeGenesis(const GameGenieCode &code);

        /**
         * Decodes NES game genie code into an NESRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded NESRawCode.
         */
        static NESRawCode decodeNES(const GameGenieCode &code);

        /**
         * Decodes SNES game genie code into an SNESRawCode.
         *
         * @param code The game genie code.
         *
         * @return The decoded SNESRawCode.
         */
        static SNESRawCode decodeSNES(const GameGenieCode &code);
    };

    inline Decoder::Decoder() {}
}  // namespace ggencoder

#endif
