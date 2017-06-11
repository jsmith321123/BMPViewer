#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>

using namespace std;

class Pixel {
public:
	Pixel (int r, int g, int b, int a);

	int alpha;
	int red;
	int green;
	int blue;

	bool padding;
};