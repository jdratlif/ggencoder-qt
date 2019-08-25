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

// $Id: geniedialog.cc,v 1.6 2008/12/18 03:23:30 jdratlif Exp $

#include <QValidator>

#include "exceptions/invalidgamegeniecode.hh"

#include "model/gbgggamegeniecode.hh"
#include "model/gbggrawcode.hh"
#include "model/genesisgamegeniecode.hh"
#include "model/genesisrawcode.hh"
#include "model/nesgamegeniecode.hh"
#include "model/nesrawcode.hh"
#include "model/snesgamegeniecode.hh"
#include "model/snesrawcode.hh"

#include "tools/decoder.hh"
#include "tools/encoder.hh"

#include "view/geniedialog.hh"
#include "view/system.hh"

using namespace ggencoder;

GenieDialog::GenieDialog() : QDialog(), encoding(false), decoding(false) {
    setAttribute(Qt::WA_QuitOnClose);
    ui.setupUi(this);
    
    // setup text box validation
    QRegExp regex;
    
    regex = QRegExp("[A-Fa-f0-9]+");
    hexValidator = new QRegExpValidator(regex, this);
    
    regex = QRegExp("[APZLGITYEOXUKSVNapzlgityeoxuksvn]+");
    nesValidator = new QRegExpValidator(regex, this);
    
    regex = QRegExp("[A-Fa-f0-9-]+");
    snesValidator = new QRegExpValidator(regex, this);
    
    regex = QRegExp("[A-HJ-NPR-TV-Z0-9a-hj-np-tv-z-]+");
    genesisValidator = new QRegExpValidator(regex, this);
    
    regex = QRegExp("[A-Fa-f0-9-]+");
    gbggValidator = new QRegExpValidator(regex, this);
    
    ui.valueEdit->setValidator(hexValidator);
    ui.addressEdit->setValidator(hexValidator);
    ui.compareEdit->setValidator(hexValidator);
    
    ui.compareEdit->setMaxLength(2);
    
    // initialize the system
    on_nesRadio_toggled(true);
}

GenieDialog::~GenieDialog() {
    delete hexValidator;
    delete nesValidator;
    delete snesValidator;
    delete genesisValidator;
    delete gbggValidator;
}

void GenieDialog::decode() {
    if (encoding) {
        return;
    }
    
    decoding = true;
    
    QString text = ui.gamegenieEdit->text().toUpper();
    
    try {
        QString str;
        
        if (system == NES) {
            NESGameGenieCode ggcode = NESGameGenieCode::create(text);
            NESRawCode rawcode = Decoder::decodeNES(ggcode);
            
            str.sprintf("%02X", rawcode.getValue());
            ui.valueEdit->setText(str);
            
            str.sprintf("%04X", rawcode.getAddress());
            ui.addressEdit->setText(str);
            
            if (rawcode.hasCompare()) {
                str.sprintf("%02X", rawcode.getCompare());
                ui.compareEdit->setText(str);
            } else {
                ui.compareEdit->clear();
            }
        } else if (system == SNES) {
            SNESGameGenieCode ggcode = SNESGameGenieCode::create(text);
            SNESRawCode rawcode = Decoder::decodeSNES(ggcode);
            
            str.sprintf("%02X", rawcode.getValue());
            ui.valueEdit->setText(str);
            
            str.sprintf("%04X", rawcode.getAddress());
            ui.addressEdit->setText(str);
        } else if (system == GENESIS) {
            GenesisGameGenieCode ggcode = GenesisGameGenieCode::create(text);
            GenesisRawCode rawcode = Decoder::decodeGenesis(ggcode);
            
            str.sprintf("%04X", rawcode.getValue());
            ui.valueEdit->setText(str);
            
            str.sprintf("%04X", rawcode.getAddress());
            ui.addressEdit->setText(str);
        } else if (system == GBGG) {
            GBGGGameGenieCode ggcode = GBGGGameGenieCode::create(text);
            GBGGRawCode rawcode = Decoder::decodeGBGG(ggcode);
            
            str.sprintf("%02X", rawcode.getValue());
            ui.valueEdit->setText(str);
            
            str.sprintf("%04X", rawcode.getAddress());
            ui.addressEdit->setText(str);
            
            if (rawcode.hasCompare()) {
                str.sprintf("%02X", rawcode.getCompare());
                ui.compareEdit->setText(str);
            } else {
                ui.compareEdit->clear();
            }
        }
    } catch (InvalidGameGenieCodeException e) {
        // must not be ready yet...
    }
    
    decoding = false;
}

void GenieDialog::encode() {
    if (decoding) {
        return;
    }
    
    encoding = true;
    
    bool ok;
    
    int value = ui.valueEdit->text().toInt(&ok, 16);
    int address = ui.addressEdit->text().toInt(&ok, 16);
    int compare = ui.compareEdit->text().toInt(&ok, 16);
    
    if (system == NES) {
        NESRawCode *rawcode;
        
        if (!ui.compareEdit->text().isEmpty()) {
            rawcode = new NESRawCode(address, value, compare);
        } else {
            rawcode = new NESRawCode(address, value);
        }
        
        NESGameGenieCode ggcode = Encoder::encode(*rawcode);
        ui.gamegenieEdit->setText(ggcode.getCode());
        
        delete rawcode;
    } else if (system == SNES) {
        SNESRawCode rawcode(address, value);
        SNESGameGenieCode ggcode = Encoder::encode(rawcode);
        ui.gamegenieEdit->setText(ggcode.getCode());
    } else if (system == GENESIS) {
        GenesisRawCode rawcode(address, value);
        GenesisGameGenieCode ggcode = Encoder::encode(rawcode);
        ui.gamegenieEdit->setText(ggcode.getCode());
    } else if (system == GBGG) {
        GBGGRawCode *rawcode;
        
        if (!ui.compareEdit->text().isEmpty()) {
            rawcode = new GBGGRawCode(address, value, compare);
        } else {
            rawcode = new GBGGRawCode(address, value);
        }
        
        GBGGGameGenieCode ggcode = Encoder::encode(*rawcode);
        ui.gamegenieEdit->setText(ggcode.getCode());
        
        delete rawcode;
    }
    
    encoding = false;
}

void GenieDialog::reset() {
    encoding = true;
    decoding = true;
    
    ui.gamegenieEdit->clear();
    ui.valueEdit->clear();
    ui.addressEdit->clear();
    ui.compareEdit->clear();
    
    encoding = false;
    decoding = false;
}

void GenieDialog::on_addressEdit_textEdited(const QString &) {
    encode();
}

void GenieDialog::on_compareEdit_textEdited(const QString &) {
    encode();
}

void GenieDialog::on_gamegenieEdit_textEdited(const QString &) {
    decode();
}

void GenieDialog::on_gbggRadio_toggled(bool checked) {
    if (checked) {
        reset();
        system = GBGG;
        ui.compareEdit->setEnabled(true);
        
        ui.valueEdit->setMaxLength(2);
        ui.addressEdit->setMaxLength(4);
        ui.gamegenieEdit->setMaxLength(11);
        ui.gamegenieEdit->setValidator(gbggValidator);
    }
}

void GenieDialog::on_genesisRadio_toggled(bool checked) {
    if (checked) {
        reset();
        system = GENESIS;
        ui.compareEdit->setEnabled(false);
        
        ui.valueEdit->setMaxLength(4);
        ui.addressEdit->setMaxLength(6);
        ui.gamegenieEdit->setMaxLength(9);
        ui.gamegenieEdit->setValidator(genesisValidator);
    }
}

void GenieDialog::on_nesRadio_toggled(bool checked) {
    if (checked) {
        reset();
        system = NES;
        ui.compareEdit->setEnabled(true);
        
        ui.valueEdit->setMaxLength(2);
        ui.addressEdit->setMaxLength(4);
        ui.gamegenieEdit->setMaxLength(8);
        ui.gamegenieEdit->setValidator(nesValidator);
    }
}

void GenieDialog::on_snesRadio_toggled(bool checked) {
    if (checked) {
        reset();
        system = SNES;
        ui.compareEdit->setEnabled(false);
        
        ui.valueEdit->setMaxLength(2);
        ui.addressEdit->setMaxLength(6);
        ui.gamegenieEdit->setMaxLength(9);
        ui.gamegenieEdit->setValidator(snesValidator);
    }
}

void GenieDialog::on_valueEdit_textEdited(const QString &) {
    encode();
}

