    /****************************************************************************
    **
    ** Copyright (C) 2011 Bacon Industries. All rights reserved.
    ** You can copy this as long as we get money
    ** Written By: Team Amurica Spring 2011
    **
    ****************************************************************************/

    #include <QtGui>
    #include <QPalette>

    #include "bacondemo.h"
    #include "baconwindow.h"

    BaconWindow::BaconWindow()
    {
        //initialize the default modulus, mayne
        board = new BaconDemo;

	//initialize the keyboard
        keyboardLabel = new QLabel;
        keyboardLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
        keyboardLabel->setAlignment(Qt::AlignCenter);

	//Set the background color of the keyboard widget
	QPalette Pal(keyboardLabel->palette());
	Pal.setColor(QPalette::Window, Qt::blue);
	keyboardLabel->setPalette(Pal);

	//Display the keyboard 
        //board->setNextPieceLabel(keyboardLabel);

	//initialize the number displays
        scoreLcd = new QLCDNumber(3);
        scoreLcd->setSegmentStyle(QLCDNumber::Flat);
        timeLcd = new QLCDNumber(8);
        timeLcd->setSegmentStyle(QLCDNumber::Flat);

	//initialize the buttons (with labels on them)
        startButton = new QPushButton(tr("&Start"));
        startButton->setFocusPolicy(Qt::NoFocus);
        quitButton = new QPushButton(tr("&Quit"));
        quitButton->setFocusPolicy(Qt::NoFocus);
	//	instructionsButton = new QPushButton(tr("&Show Instructions"));
	//instructionsButton->setFocusPolicy(Qt::NoFocus);
	loadModButton = new QPushButton(tr("&Load Module"));

	//connect the button and displays to methods in the modulus
        connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
        connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(loadModButton, SIGNAL(clicked()), board, SLOT(pause()));
        connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
        connect(board, SIGNAL(levelChanged(int)), timeLcd, SLOT(display(int)));

	//	connect(instructionsButton, SIGNAL(clicked()), board, SLOT(showInstructions()));

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(keyboardLabel, 4, 0); //add the keyboard

	//add the score and time windows, with labels
        layout->addWidget(scoreLcd, 1, 3);
	layout->addWidget(createLabel(tr("Score")), 1, 3);
	layout->addWidget(timeLcd, 0, 3);
	layout->addWidget(createLabel(tr("Time Left")), 0, 3);
        
	//add the buttons
	layout->addWidget(startButton, 4, 3);
	layout->addWidget(quitButton, 5, 3);
	//	layout->addWidget(instructionsButton, 6, 3);
	layout->addWidget(loadModButton, 7, 3);
        
	//main modulus window
	layout->addWidget(board, 0, 0, 2, 2);
        
        setLayout(layout);

        setWindowTitle(tr("Mavis Bacon"));
        resize(2000, 800); //we want the window to be full screen
    }

    QLabel *BaconWindow::createLabel(const QString &text)
    {
        QLabel *lbl = new QLabel(text);
        lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
        return lbl;
    }
