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

    #ifndef TETRIXBOARD_H
    #define TETRIXBOARD_H

    #include <QBasicTimer>
    #include <QFrame>
    #include <QPointer>
    #include <QApplication>
    #include <QPalette>

    #include "tetrixpiece.h"
    #include "baconwindow.h"

    class QLabel;

    class TetrixBoard : public QFrame
    {
        Q_OBJECT

    public:
      TetrixBoard(QWidget *parent = 0);

        void setNextPieceLabel(QLabel *label);
        QSize sizeHint() const;
        QSize minimumSizeHint() const;

    public slots:
        void start();
        void pause();
	void showInstructions();

    signals:
        void scoreChanged(int score);
        void levelChanged(int level);
        void linesRemovedChanged(int numLines);

    protected:
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void timerEvent(QTimerEvent *event);

    private:
        enum { BoardWidth = 15, BoardHeight = 26 };

        TetrixShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
        int timeoutTime() { return 1000 / (1 + level); }
        int squareWidth() { return contentsRect().width() / BoardWidth; }
        int squareHeight() { return contentsRect().height() / BoardHeight; }
        void clearBoard();
        void dropDown();
        void oneLineDown();
        void pieceDropped(int dropHeight);
        void removeFullLines();
        void newPiece();
        void showNextPiece();
        bool tryMove(const TetrixPiece &newPiece, int newX, int newY);
        void drawSquare(QPainter &painter, int x, int y, TetrixShape shape);

        QBasicTimer timer;
        QPointer<QLabel> nextPieceLabel;
        bool isStarted;
        bool isPaused;
        bool isWaitingAfterLine;
        TetrixPiece curPiece;
        TetrixPiece nextPiece;
        int curX;
        int curY;
        int numLinesRemoved;
        int numPiecesDropped;
        int score;
        int level;
        TetrixShape board[BoardWidth * BoardHeight];
    };

    #endif
