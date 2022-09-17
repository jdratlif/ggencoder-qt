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

#include "model/gbggrawcode.hh"

using namespace ggencoder;

GBGGRawCode::GBGGRawCode(int address, int value, int compare)
    : RawCode{address & 0xFFFF, value & 0xFF}, CompareRawCode{compare} {}

GBGGRawCode::GBGGRawCode(int address, int value)
    : RawCode{address & 0xFFFF, value & 0xFF}, CompareRawCode{-1} {}

void GBGGRawCode::setAddress(int address) {
    this->address = (address & 0xFFFF);
}

void GBGGRawCode::setValue(int value) {
    this->value = (value & 0xFF);
}
