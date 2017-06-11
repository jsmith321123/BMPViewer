#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include "Pixel.h"

using namespace std;

Pixel::Pixel(int r, int g, int b, int a) {
	red = r;
	green = g;
	blue = b;

	if (a != NULL)
		alpha = a;
	else
		alpha = 255;
}