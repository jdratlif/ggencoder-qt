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
 
// $Id: geniedialog.hh,v 1.3 2005/07/30 04:55:29 technoplaza Exp $

#ifndef _GENIEDIALOG_HH
#define _GENIEDIALOG_HH

#include <QDialog>

#include "ui_maindialog.h"

class QRegExpValidator;

namespace emuWorks {
    class GenieDialog : public QDialog {
        Q_OBJECT
        
    private:
        QRegExpValidator *hexValidator;
        QRegExpValidator *nesValidator;
        QRegExpValidator *snesValidator;
        QRegExpValidator *genesisValidator;
        QRegExpValidator *gbggValidator;
        Ui::MainDialog ui;
        int system;
        bool encoding, decoding;        
        
        /**
         * Resets the controls.
         */
        void reset();
        
        /**
         * Encodes the value, address, and compare into a game genie code.
         */
        void encode();
        
        /**
         * Decodes the game genie code into value, address, and compare
         * components.
         */
        void decode();
    public:
        /**
         * Creates a new GenieDialog.
         */
        GenieDialog();
        
        /**
         * Destructor for a GenieDialog.
         */
        ~GenieDialog();
    private slots:
        /**
         * Called when the NES radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_nesRadio_toggled(bool checked);
        
        /**
         * Called when the SNES radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_snesRadio_toggled(bool checked);
        
        /**
         * Called when the Genesis radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_genesisRadio_toggled(bool checked);
        
        /**
         * Called when the Game Boy / Game Gear radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_gbggRadio_toggled(bool checked);
        
        /**
         * Called when the value box is edited.
         *
         * @param text The new text.
         */
        void on_valueEdit_textEdited(const QString &text);
        
        /**
         * Called when the address box is edited.
         * 
         * @param text The new text.
         */
        void on_addressEdit_textEdited(const QString &text);
        
        /**
         * Called when the compare box is edited.
         * 
         * @param text The new text.
         */
        void on_compareEdit_textEdited(const QString &text);
        
        /**
         * Called when the game genie box is edited.
         * 
         * @param text The new text.
         */
        void on_gamegenieEdit_textEdited(const QString &text);
    };
}

#endif

