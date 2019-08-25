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
 
// $Id: decoder.cc,v 1.5 2005/07/30 04:31:38 technoplaza Exp $

#include <QString>

#include "decoder.hh"
#include "../model/nesgamegeniecode.hh"
#include "../model/nesrawcode.hh"
#include "../model/snesgamegeniecode.hh"
#include "../model/snesrawcode.hh"
#include "../model/genesisgamegeniecode.hh"
#include "../model/genesisrawcode.hh"
#include "../model/gbgggamegeniecode.hh"
#include "../model/gbggrawcode.hh"
#include "../exceptions/invalidgamegeniecode.hh"

using namespace emuWorks;

NESRawCode Decoder::decodeNES(GameGenieCode &code) {
    QString ggcode = code.getCode();
    int length = ggcode.length();
    
    if (!NESGameGenieCode::isValidCode(ggcode)) {
        throw InvalidGameGenieCodeException();
    }
    
    int bitstring = 0;
    
    for (int i = 0; i < length; i++) {
        QChar ch = ggcode[i];
        
        bitstring <<= 4;        
        bitstring |= code.toHex(ch.toAscii());
    }
    
    int value;
    int address;
    int temp;
    
    if (length == 6) {
        bitstring <<= 8;
    }
    
    // position 1234
    value = ((bitstring >> 28) & 0x8) | ((bitstring >> 24) & 0x7);
    
    if (length == 6) {
        temp = (bitstring & 0x800) >> 8;
    } else {
        temp = bitstring & 0x8;
    }
    
    temp |= ((bitstring >> 28) & 0x7);
    
    value <<= 4;
    value |= temp;
    
    // position -ABC
    address = (bitstring & 0x70000) >> 16;
    
    // position DEFG
    temp = ((bitstring & 0x8000) >> 12) | ((bitstring & 0x700) >> 8);
    address <<= 4;
    address |= temp;
    
    // position HIJK
    temp = ((bitstring & 0x8000000) >> 24) | ((bitstring & 0x700000) >> 20);
    address <<= 4;
    address |= temp;

    // position LMNO
    temp = ((bitstring & 0x80000) >> 16) | ((bitstring & 0x7000) >> 12);
    address <<= 4;
    address |= temp;
    
    if (length == 6) {
        return NESRawCode(address, value);
    }
    
    int compare;
    
    // position abcd
    compare = ((bitstring & 0x80) >> 4) | (bitstring & 0x7);
    
    // position efgh
    temp = ((bitstring & 0x800) >> 8) | ((bitstring & 0x70) >> 4);
    compare <<= 4;
    compare |= temp;
    
    return NESRawCode(address, value, compare);
}

SNESRawCode Decoder::decodeSNES(GameGenieCode &code) {
    QString ggcode = code.getCode();
    int length = ggcode.length();
    
    if (!SNESGameGenieCode::isValidCode(ggcode)) {
        throw InvalidGameGenieCodeException();
    }
    
    int bitstring = 0;
    
    for (int i = 0; i < length; i++) {
        if (i == 4) {
            continue;
        }
        
        QChar ch = ggcode[i];
        
        bitstring <<= 4;
        bitstring |= code.toHex(ch.toAscii());
    }
    
    int value;
    int address;
    int temp;
    
    // position 12345678
    value = (bitstring >> 24) & 0xFF;
    
    // position ABCD
    address = ((bitstring >> 10) & 0xC) | ((bitstring >> 10) & 0x3);
    
    // position EFGH
    temp = ((bitstring >> 2) & 0xC) | ((bitstring >> 2) & 0x3);
    address <<= 4;
    address |= temp;
    
    // position IJKL
    temp = (bitstring >> 20) & 0xF;
    address <<= 4;
    address |= temp;
    
    // position MNOP
    temp = ((bitstring << 2) & 0xC) | ((bitstring >> 14) & 0x3);
    address <<= 4;
    address |= temp;
    
    // position QRST
    temp = (bitstring >> 16) & 0xF;
    address <<= 4;
    address |= temp;
    
    // position UVWX
    temp = ((bitstring >> 6) & 0xC) | ((bitstring >> 6) & 0x3);
    address <<= 4;
    address |= temp;
    
    return SNESRawCode(address, value);
}

GenesisRawCode Decoder::decodeGenesis(GameGenieCode &code) {
    QString ggcode = code.getCode();
    int length = ggcode.length();
    
    if (!GenesisGameGenieCode::isValidCode(ggcode)) {
        throw InvalidGameGenieCodeException();
    }
    
    qint64 bitstring = 0;
    
    for (int i = 0; i < length; i++) {
        if (i == 4) {
            continue;
        }
        
        QChar ch = ggcode[i];
        
        bitstring <<= 5;
        bitstring |= code.toHex(ch.toAscii());
    }
    
    int value;
    int address;
    int temp;
    
    // position abcd
    value = (int)(((bitstring >> 7) & 0xE) | ((bitstring >> 15) & 0x1));
    
    // position efgh
    temp = (int)(((bitstring >> 11) & 0xE) | ((bitstring >> 11) & 0x1));
    value <<= 4;
    value |= temp;
    
    // position ijklmnop
    temp = (int)(bitstring >> 32);
    value <<= 8;
    value |= temp;
    
    // a-p = value, a-x = addy
    // ijkl mnop IJKL MNOP ABCD EFGH defg habc QRST UVWX
    // position ABCDEFGH
    address = (int)((bitstring >> 16) & 0xFF);
    
    // position IJKLMNOP
    temp = (int)((bitstring >> 24) & 0xFF);
    address <<= 8;
    address |= temp;
    
    // position QRSTUVWX
    temp = (int)(bitstring & 0xFF);
    address <<= 8;
    address |= temp;
    
    return GenesisRawCode(address, value);
}

GBGGRawCode Decoder::decodeGBGG(GameGenieCode &code) {
    QString ggcode = code.getCode();
    int length = ggcode.length();
    
    if (!GBGGGameGenieCode::isValidCode(ggcode)) {
        throw InvalidGameGenieCodeException();
    }
    
    qint64 bitstring = 0;
    
    for (int i = 0; i < length; i++) {
        if ((i == 3) || (i == 7)) {
            continue;
        }
        
        QChar ch = ggcode[i];
        
        bitstring <<= 4;
        bitstring |= code.toHex(ch.toAscii());
    }
    
    int value;
    int address;
    int temp;
    
    if (length == 7) {
        bitstring <<= 12;
    }
    
    value = (int)(bitstring >> 28);
    
    temp = (int)((bitstring >> 12) & 0xF);
    temp = (~temp & 0xF) << 12;
    address = (int)((bitstring >> 16) & 0xFFF) | temp;
    
    if (length == 7) {
        return GBGGRawCode(address, value);
    }
    
    temp = (int)(((bitstring >> 4) & 0xF0) | (bitstring & 0xF));
    temp = (temp >> 2) | ((temp << 6) & 0xFC);
    
    int compare = temp ^ 0xBA;
    
    return GBGGRawCode(address, value, compare);
}

