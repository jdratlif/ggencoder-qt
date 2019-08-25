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
 
// $Id: encoder.cc,v 1.7 2008/12/18 03:23:30 jdratlif Exp $

#include "model/gbgggamegeniecode.hh"
#include "model/gbggrawcode.hh"
#include "model/genesisgamegeniecode.hh"
#include "model/genesisrawcode.hh"
#include "model/nesgamegeniecode.hh"
#include "model/nesrawcode.hh"
#include "model/snesgamegeniecode.hh"
#include "model/snesrawcode.hh"

#include "tools/encoder.hh"

using namespace ggencoder;

GBGGGameGenieCode Encoder::encode(const GBGGRawCode &code) {
    int temp, address = code.getAddress(), value = code.getValue();
    qint64 genie;
    
    // start with the value
    genie = value;
    
    temp = (address & 0xF000) >> 12;
    temp = (~temp & 0xF);
    temp |= (address & 0xFFF) << 4;
    genie <<= 16;
    genie |= temp;
    
    if (code.hasCompare()) {
        int compare = code.getCompare();
        
        compare ^= 0xBA;
        compare = (compare << 2) | (compare >> 6);
        temp = (compare & 0xF0) >> 4;
        genie <<= 4;
        genie |= temp;
        
        temp ^= 8;
        genie <<= 4;
        genie |= temp;
        
        temp = (compare & 0xF);
        genie <<= 4;
        genie |= temp;
    }
    
    QString ggcode;
    const char *alphabet = GBGGGameGenieCode::ALPHABET;
    
    for (int i = 0; i < (code.hasCompare() ? 9 : 6); i++) {
        if ((i == 3) || (i == 6)) {
            ggcode.insert(0, '-');
        }
        
        ggcode.insert(0, alphabet[(int)((genie >> (i * 4)) & 0xF)]);
    }
    
    return GBGGGameGenieCode::create(ggcode);
}

GenesisGameGenieCode Encoder::encode(const GenesisRawCode &code) {
    int temp;
    qint64 genie;
    int value = code.getValue();
    int address = code.getAddress();
    
    // position ijkl
    genie = (value & 0xF0) >> 4;
    
    // position mnop
    temp = (value & 0xF);
    genie <<= 4;
    genie |= temp;
    
    // position IJKL
    temp = (address & 0xF000) >> 12;
    genie <<= 4;
    genie |= temp;
    
    // position MNOP
    temp = (address & 0xF00) >> 8;
    genie <<= 4;
    genie |= temp;
    
    // position ABCD
    temp = (address & 0xF00000) >> 20;
    genie <<= 4;
    genie |= temp;
    
    // position EFGH
    temp = (address & 0xF0000) >> 16;
    genie <<= 4;
    genie |= temp;
    
    // position defg
    temp = ((value & 0x1000) >> 9) | ((value & 0xE00) >> 9);
    genie <<= 4;
    genie |= temp;
    
    // position habc
    temp = ((value & 0x100) >> 5) | ((value & 0xE000) >> 13);
    genie <<= 4;
    genie |= temp;
    
    // position QRST
    temp = (address & 0xF0) >> 4;
    genie <<= 4;
    genie |= temp;
    
    // position UVWX
    temp = (address & 0xF);
    genie <<= 4;
    genie |= temp;
    
    QString ggcode;
    const char *alphabet = GenesisGameGenieCode::ALPHABET;
    
    for (int i = 0; i < 8; i++) {
        if (i == 4) {
            ggcode.insert(0, "-");
        }
        
        ggcode.insert(0, alphabet[(int)((genie >> (i * 5)) & 0x1F)]);
    }
    
    return GenesisGameGenieCode::create(ggcode);
}

NESGameGenieCode Encoder::encode(const NESRawCode &code) {
    int genie;
    int temp = 0;
    int value = code.getValue();
    int address = code.getAddress();
    
    // position 1678
    genie = ((value & 0x80) >> 4) | (value & 0x7);
    
    // position H234
    temp = ((address & 0x80) >> 4) | ((value & 0x70) >> 4);
    genie <<= 4;
    genie |= temp;
    
    // position -IJK
    temp = (address & 0x70) >> 4;
    
    if (code.hasCompare()) {
        temp |= 0x8;
    }
    
    genie <<= 4;
    genie |= temp;
    
    // position LABC
    temp = (address & 0x8) | ((address & 0x7000) >> 12);
    genie <<= 4;
    genie |= temp;
    
    // position DMNO
    temp = ((address & 0x800) >> 8) | (address & 0x7);
    genie <<= 4;
    genie |= temp;
    
    if (code.hasCompare()) {
        int compare = code.getCompare();
        
        // position eEFG
        temp = (compare & 0x8) | ((address & 0x700) >> 8);
        genie <<= 4;
        genie |= temp;
        
        // position afgh
        temp = ((compare & 0x80) >> 4) | (compare & 0x7);
        genie <<= 4;
        genie |= temp;
        
        // position 5bcd
        temp = (value & 0x8) | ((compare & 0x70) >> 4);
        genie <<= 4;
        genie |= temp;
    } else {
        // position 5EFG
        temp = (value & 0x8) | ((address & 0x700) >> 8);
        genie <<= 4;
        genie |= temp;
    }
    
    QString ggcode;
    const char *alphabet = NESGameGenieCode::ALPHABET;
    
    for (int i = 0; i < (code.hasCompare() ? 8 : 6); i++) {
        ggcode.insert(0, alphabet[(genie >> (i * 4)) & 0xF]);
    }
    
    return NESGameGenieCode::create(ggcode);
}

SNESGameGenieCode Encoder::encode(const SNESRawCode &code) {
    int genie;
    int temp;
    int value = code.getValue();
    int address = code.getAddress();
    
    // position 1-8
    genie = value;
    
    // position IJKL
    temp = (address & 0xF000) >> 12;
    genie <<= 4;
    genie |= temp;
    
    // position QRST
    temp = (address & 0xF0) >> 4;
    genie <<= 4;
    genie |= temp;
    
    // position OPAB
    temp = ((address & 0x300) >> 6) | (address >> 22);
    genie <<= 4;
    genie |= temp;
    
    // position CDUV
    temp = ((address & 0x300000) >> 18) | ((address & 0xC) >> 2);
    genie <<= 4;
    genie |= temp;
    
    // position WXEF
    temp = ((address & 0x3) << 2) | ((address & 0xC0000) >> 18);
    genie <<= 4;
    genie |= temp;
    
    // position GHMN
    temp = ((address & 0x30000) >> 14) | ((address & 0xC00) >> 10);
    genie <<= 4;
    genie |= temp;
    
    QString ggcode;
    const char *alphabet = SNESGameGenieCode::ALPHABET;
    
    for (int i = 0; i < 8; i++) {
        if (i == 4) {
            ggcode.insert(0, '-');
        }
        
        ggcode.insert(0, alphabet[(genie >> (i * 4)) & 0xF]);
    }
    
    return SNESGameGenieCode::create(ggcode);
}

