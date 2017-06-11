#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>

#include "qt_classes/MainWindow.h"

#include <QtCore>
#include <QApplication>

#include "image_handling/Image.h"

using namespace std;

int main(int argc, char **argv) {
	QApplication app (argc, argv);

	MainWindow* mw = new MainWindow();

	mw->show();
	app.exec();

	return 0;
}