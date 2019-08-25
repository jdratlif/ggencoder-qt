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
 
// $Id: gamegeniecode.cc,v 1.7 2008/12/18 03:23:30 jdratlif Exp $

#include <cctype>

#include "model/gamegeniecode.hh"

using namespace ggencoder;

int GameGenieCode::toHex(char letter) const {
    letter = toupper(letter);
    
    const char *alphabet = getAlphabet();
    int count = getAlphabetCount();
    
    for (int i = 0; i < count; i++) {
        if (alphabet[i] == letter) {
            return i;
        }
    }
    
    return -1;
}

