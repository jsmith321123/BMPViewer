#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <fstream>
#include <math.h>
#include "Image.h"

using namespace std;

Image::Image (string f) {
	filename = f;

	Populate();
}

void Image::Populate() {
	//read from file
	ifstream image_file(filename, ios::binary);

	//read into byte array
	image_file.seekg(0, ios::end);
	size_t len = image_file.tellg();
	unsigned char* image_bytes = new unsigned char[len];
	image_file.seekg(0, ios::beg);
	image_file.read((char*)image_bytes, len);
	image_file.close();

	//check if file is valid, ie first two chars are BM
	if (int(image_bytes[0]) == 66 && int(image_bytes[1]) == 77) {
		cout << "valid image" << endl;
	} else {
		cout << "invalid image" << endl;
		return;
	}

	//get image width from 18, 19, 20, 21
	width = image_bytes[19]*pow(16, 2) + image_bytes[18];

	//get image height from 22, 23, 24, 25
	height = image_bytes[23]*pow(16, 2) + image_bytes[22];

	//get image array location stored at 10
	array_index = image_bytes[10];

	//get the colour depth from loc 28
	colour_depth = image_bytes[28];

	//calculate offset required to locate each pixel
	//this is equal to colour_depth/8 rounded up
	//this is the amount of bytes required to store
	//each pixel
	int pixel_offset = ceil(colour_depth/8);

	//calculate how large the image should be
	int expected_size = width * height * pixel_offset;

	//get the actualy size from the byte array
	int actual_size = image_bytes[34] + image_bytes[35]*pow(16, 2) +
					  image_bytes[36]*pow(16, 4) + image_bytes[37]*pow(16, 6);

	//calculate difference between actual and expected
	int size_diff = actual_size - expected_size;

	//find how many extra bytes are use per line for padding
	padding_bytes = size_diff/height;

	//populate the pixels vector with pixel objects
	//note, this starts in the bottom left not the top lef

	//store the last pixel at which padding had to be
	//accounted for (begining of new row)
	int last_padding = 0;

	//store the amount that the first byte of the pixel
	//will vary from the expected value, e.g. if 3 bytes
	//are used for padding the start of the pixel will be
	//3 bytes ahead of where it is expected, for each time
	//padding is accounted for
	int padding_offset = 0;

	for (int i = 0; i < width * height; i++) {
		//get the index of the first byte of the pixel
		//this is the blue value
		int start_byte = i * pixel_offset + array_index + padding_offset;

		int a = -1;

		//get alpha if applicable
		if (pixel_offset == 4) {
			a = image_bytes[start_byte + 3];
		} else
			a = NULL;

		//if the difference between the last pixel
		//that required padding to be accounted for
		//and this pixel is equal to the width the
		//offset that is needed for the begining of
		//each pixel is incremented by the amount of
		//bytes used for padding
		if (last_padding == i - width && i != 0) {
			last_padding = i;
			
			padding_offset += padding_bytes;
		}

		pixels.push_back(
			new Pixel(
				image_bytes[start_byte + 2],
				image_bytes[start_byte + 1],
				image_bytes[start_byte],
				a
			)
		);
		

		//cout << last_padding << endl;
		//cout << i << endl;

		
	}
}