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
 
// $Id: geniedialog.hh,v 1.7 2008/12/18 03:23:30 jdratlif Exp $

#ifndef GGENCODER_GENIEDIALOG_HH_
#define GGENCODER_GENIEDIALOG_HH_

#include <QDialog>
#include <QRegExpValidator>

#include "ui_maindialog.h"

namespace ggencoder {
    /**
     * The main dialog for the application.
     */
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
         * Decodes the game genie code into value, address, and compare
         * components.
         */
        void decode();
        
        /**
         * Encodes the value, address, and compare into a game genie code.
         */
        void encode();
        
        /**
         * Resets the controls.
         */
        void reset();
        
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
        
        /**
         * Called when the Game Boy / Game Gear radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_gbggRadio_toggled(bool checked);
        
        /**
         * Called when the Genesis radio button is toggled.
         *
         * @param checked true if it was checked; false otherwise
         */
        void on_genesisRadio_toggled(bool checked);
        
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
         * Called when the value box is edited.
         *
         * @param text The new text.
         */
        void on_valueEdit_textEdited(const QString &text);
    };
}

#endif

