    /****************************************************************************
    **
    ** Copyright (C) 2004-2005 Trolltech AS. All rights reserved.
    **
    ** This file is part of the documentation of the Qt Toolkit.
    **
    ** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
    **
    ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
    ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
    **
    ****************************************************************************/

    #ifndef TETRIXPIECE_H
    #define TETRIXPIECE_H

    enum TetrixShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
                       LShape, MirroredLShape, SingleBlock, UShape, Donut, 
		       Pyramid, YourMom, Troll};

    class TetrixPiece
    {
    public:
        TetrixPiece() { setShape(NoShape); }

        void setRandomShape();
        void setShape(TetrixShape shape);

        TetrixShape shape() const { return pieceShape; }
        int x(int index) const { return coords[index][0]; }
        int y(int index) const { return coords[index][1]; }
        int minX() const;
        int maxX() const;
        int minY() const;
        int maxY() const;
        TetrixPiece rotatedLeft() const;
        TetrixPiece rotatedRight() const;

    private:
        void setX(int index, int x) { coords[index][0] = x; }
        void setY(int index, int y) { coords[index][1] = y; }

        TetrixShape pieceShape;
        int coords[9][2];
    };

    #endif
