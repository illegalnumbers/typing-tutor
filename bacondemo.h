
    #ifndef BACONDEMO_H
    #define BACONDEMO_H

    #include <QBasicTimer>
    #include <QFrame>
    #include <QPointer>
    #include <QApplication>
    #include <QPalette>
    #include <time.h>
    #include <stdlib.h>
    #include <iostream>

    #include "tetrixpiece.h"
    #include "baconwindow.h"

    class QLabel;

    class BaconDemo : public QFrame
    {
        Q_OBJECT

    public:
      BaconDemo(QWidget *parent = 0);

        QSize sizeHint() const;
        QSize minimumSizeHint() const;

    public slots:
        void start();
        void pause();
	void showInstructions();

    signals:
        void scoreChanged(int score);
        void levelChanged(int level);

    protected:
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void timerEvent(QTimerEvent *event);

    private:
        enum { BoardWidth = 15, BoardHeight = 26 };

	char alphabet[27];
	int random;

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
	int level;
        int score;
        TetrixShape board[BoardWidth * BoardHeight];
    };

    #endif
