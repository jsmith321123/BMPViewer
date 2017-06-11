#define __USE_MINGW_ANSI_STDIO 0

#ifndef IMAGESCENE_H
#define IMAGESCENE_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>

using namespace std;

class ImageScene : public QGraphicsScene {
Q_OBJECT

public:
	ImageScene(string filename);
	QGraphicsView* view = new QGraphicsView();

private:
	void drawImage(string filename);
};

#endif //IMAGESCENE_H