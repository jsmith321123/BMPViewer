#define __USE_MINGW_ANSI_STDIO 0

#include "ImageScene.h"
#include "../image_handling/Image.cpp"

#include <iostream>
#include <QGraphicsLineItem>
#include <QColor>
#include <QPen>

using namespace std;

ImageScene::ImageScene(string filename) {
	view->setScene(this);
	drawImage(filename);
}

void ImageScene::drawImage(string filename) {
	//get the image
	Image* image = new Image(filename);

	view->setSceneRect(0, 0, image->width, image->height);

	QPen pen;

	cout << image->pixels[10]->alpha << endl;

	for (int i = 0; i < image->pixels.size(); i++) {
		//current x is i % width
		//current y is height - (i - x)/width
		Pixel* curr_pix = image->pixels[i];

		QColor rgb = QColor::fromRgb(curr_pix->red, curr_pix->green, curr_pix->blue);
		rgb.setAlpha(curr_pix->alpha);

		pen.setColor(rgb);

		QGraphicsLineItem* curr = addLine(i % image->width, image->height - (i-i % image->width)/image->width, i % image->width, image->height - (i-i % image->width)/image->width);
		curr->setPen(pen);
	}
}