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

    #include <QtCore>

    #include <stdlib.h>

    #include "tetrixpiece.h"

    void TetrixPiece::setRandomShape()
    {
        setShape(TetrixShape(rand() % 13 + 1));
    }

    void TetrixPiece::setShape(TetrixShape shape)
    {
        static const int coordsTable[14][9][2] = {
	  { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } ,  { 0, 0 }},
	  { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 },{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } ,  { 0, 0 }},
          { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
          { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 }, { 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { 0, 0 },  { 0, 0 },  { 0, 0 },   { 0, 0 },{ 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { -1, -1 },  { 0, 0 },  { 1, 0 },   { 2, -1 },{ 0, 0 }, { 0, 0 }, { 0, 0 },   { 0, 0 } ,  { 0, 0 }},
	  { { 0, -1 },  { -1, 0 },  { 1, -1 },   { 0, 1 },{ 1, 1 }, { 2, 0 }, { 2, 0 },   { 2, 0 } ,  { 2, 0 }},
	  { { -2, 1 },  { -1, 1 },  { 0, 1 },   { 1, 1 },{ 2, 1 }, { -1, 0 }, { 0, 0 },   { 1, 0 } ,  { 0, -1 }},
	  { { -2, 0 },  { -1, -1 },  { -1, 1 },   { 0, -2 },{ 0, 2 }, { 1, -2 }, { 1, 0 },   { 2, -1 } ,  { 3, 0 }},
	  { { 0, 0 },  { -6, 0 },  { -2, 0 },   { -3, 0 },{ -4, 0 }, { -5, 0 }, { 3, 0 },   { 1, 0 } ,  { 2, 0 }}
        };

        for (int i = 0; i < 9 ; i++) {
            for (int j = 0; j < 2; ++j)
                coords[i][j] = coordsTable[shape][i][j];
        }
        pieceShape = shape;
    }

    int TetrixPiece::minX() const
    {
        int min = coords[0][0];
        for (int i = 1; i < 9; ++i)
            min = qMin(min, coords[i][0]);
        return min;
    }

    int TetrixPiece::maxX() const
    {
        int max = coords[0][0];
        for (int i = 1; i < 9; ++i)
            max = qMax(max, coords[i][0]);
        return max;
    }

    int TetrixPiece::minY() const
    {
        int min = coords[0][1];
        for (int i = 1; i < 9; ++i)
            min = qMin(min, coords[i][1]);
        return min;
    }

    int TetrixPiece::maxY() const
    {
        int max = coords[0][1];
        for (int i = 1; i < 9; ++i)
            max = qMax(max, coords[i][1]);
        return max;
    }

    TetrixPiece TetrixPiece::rotatedLeft() const
    {
        if (pieceShape == SquareShape)
            return *this;

        TetrixPiece result;
        result.pieceShape = pieceShape;
        for (int i = 0; i < 9; ++i) {
            result.setX(i, y(i));
            result.setY(i, -x(i));
        }
        return result;
    }

    TetrixPiece TetrixPiece::rotatedRight() const
    {
        if (pieceShape == SquareShape)
            return *this;

        TetrixPiece result;
        result.pieceShape = pieceShape;
        for (int i = 0; i < 9; ++i) {
            result.setX(i, -y(i));
            result.setY(i, x(i));
        }
        return result;
    }
