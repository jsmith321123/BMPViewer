#define __USE_MINGW_ANSI_STDIO 0

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QVBoxLayout>
#include <QWidget>

#include "ImageScene.h"

//qt
#include <QMainWindow>


class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow();

private:
	QVBoxLayout layout;
	QWidget central_widget;

	ImageScene* is = new ImageScene("test.bmp");
};


#endif //MAINWINDOW_H
