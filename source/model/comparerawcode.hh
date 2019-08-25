/*
 * Game Genie Encoder/Decoder
 * Copyright (C) 2004-2006 emuWorks
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
 
// $Id: comparerawcode.hh,v 1.5 2006/08/18 22:17:24 technoplaza Exp $

#ifndef _COMPARERAWCODE_HH
#define _COMPARERAWCODE_HH

namespace emuWorks {
    /**
     * A raw code interface with a compare value.
     */
    class CompareRawCode {
    protected:
        int compare;
        
    public:
        /**
         * Checks if this CompareRawCode uses a compare value.
         *
         * @return true if a compare is used; false otherwise.
         */
        bool hasCompare() const;
    
        /**
         * Gets the compare value of this CompareRawCode.
         *
         * @return The compare value.
         */
        int getCompare() const;
        
        /**
         * Sets the compare value of this CompareRawCode.
         *
         * @param compare The new compare value.
         */
        void setCompare(int compare);
    };
    
    inline bool CompareRawCode::hasCompare() const
        { return (compare != -1); }
    inline int CompareRawCode::getCompare() const
        { return compare; }
    inline void CompareRawCode::setCompare(int compare)
        { this->compare = (compare & 0xFF); };
}

#endif

