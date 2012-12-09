    /****************************************************************************
    **
    ** Copyright (C) 2011 Bacon Industries  AS. All rights reserved.
    ** You can copy this as long as we get money
    **
    ****************************************************************************/

    #include <QApplication>
    #include <QPalette>
    #include <QWidget>

    #include <stdlib.h>
    #include <time.h>

    #include "baconwindow.h"

    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);
	
	QPalette p = app.palette();
	QPixmap px("/home/brenneis/cs3505/Final/images/bacon.jpg");
	p.setBrush(QPalette::Window, QBrush(px));
	app.setPalette(p);

        BaconWindow window;
        window.show();
        srand(time(0));
        return app.exec();
    }
