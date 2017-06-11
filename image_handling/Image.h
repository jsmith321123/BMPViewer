#define __USE_MINGW_ANSI_STDIO 0

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>

#include "Pixel.h"

using namespace std;

class Image {
public:
	Image (string f);

	void print();

	vector<Pixel*> pixels;

	int width;
 	int height;
 	int padding_bytes;

private:
	void Populate();

 	string filename;

 	int array_index;
 	int colour_depth;
};

#endif //IMAGE_H