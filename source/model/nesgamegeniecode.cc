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

#include "model/nesgamegeniecode.hh"

using namespace ggencoder;

const char NESGameGenieCode::ALPHABET[] = {'A', 'P', 'Z', 'L', 'G', 'I',
                                           'T', 'Y', 'E', 'O', 'X', 'U',
                                           'K', 'S', 'V', 'N'};

auto NESGameGenieCode::create(const QString &code) -> NESGameGenieCode {
    if (isValidCode(code)) {
        return NESGameGenieCode(code);
    }

    throw InvalidGameGenieCodeException();
}

auto NESGameGenieCode::getAlphabet() const -> const char * {
    return ALPHABET;
}

auto NESGameGenieCode::isValidCode(const QString &code) -> bool {
    NESGameGenieCode temp(code);

    const char *alphabet = temp.getAlphabet();
    int         count    = temp.getAlphabetCount();

    QString upper  = code.toUpper();
    int     length = upper.length();

    if ((length != 6) && (length != 8)) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        bool  found  = false;
        QChar ch     = code[i];
        char  letter = ch.toLatin1();

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
