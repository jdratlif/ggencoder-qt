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

#ifndef GGENCODER_RAWCODE_HH_
#define GGENCODER_RAWCODE_HH_

namespace ggencoder {
    /**
     * Interface for a raw hex/PAR code.
     */
    class RawCode {
      protected:
        int address;
        int value;

      public:
        /**
         * Virtual destructor for RawCode derivatives.
         */
        virtual ~RawCode();

        /**
         * Gets the address of this RawCode.
         *
         * @return The address.
         */
        virtual int getAddress() const;

        /**
         * Sets the address of this RawCode.
         *
         * @param address The new address.
         */
        virtual void setAddress(int address) = 0;

        /**
         * Gets the value of this RawCode.
         *
         * @return The value.
         */
        virtual int getValue() const;

        /**
         * Sets the value of this RawCode.
         *
         * @param value The new value.
         */
        virtual void setValue(int value) = 0;
    };

    inline RawCode::~RawCode() {}
    inline int RawCode::getAddress() const {
        return address;
    }
    inline int RawCode::getValue() const {
        return value;
    }
}  // namespace ggencoder

#endif
