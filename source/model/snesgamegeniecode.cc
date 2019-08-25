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
 
// $Id: snesgamegeniecode.cc,v 1.4 2005/07/30 02:36:45 technoplaza Exp $

#include "snesgamegeniecode.hh"
#include "../exceptions/invalidgamegeniecode.hh"

using namespace emuWorks;

const char SNESGameGenieCode::ALPHABET[] = {
    'D', 'F', '4', '7', '0', '9', '1', '5',
    '6', 'B', 'C', '8', 'A', '2', '3', 'E'
};

SNESGameGenieCode SNESGameGenieCode::create(QString &code) {
    if (isValidCode(code)) {
        return SNESGameGenieCode(code);
    }
    
    throw InvalidGameGenieCodeException();
}

bool SNESGameGenieCode::isValidCode(QString &code) {
    SNESGameGenieCode temp(code);
    
    const char *alphabet = temp.getAlphabet();
    int count = temp.getAlphabetCount();
    
    QString upper = code.toUpper();
    int length = upper.length();
    
    if (length != 9) {
        return false;
    }
    
    if (code[4] != '-') {
        return false;
    }
    
    for (int i = 0; i < length; i++) {
        if (i == 4) {
            continue;
        }
        
        bool found = false;
        QChar ch = code[i];
        char letter = ch.toAscii();
        
        for (int j = 0; j < count; j++) {
            if (letter == alphabet[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            return false;
        }
    }
    
    return true;
}

const char *SNESGameGenieCode::getAlphabet() {
    return ALPHABET;
}

