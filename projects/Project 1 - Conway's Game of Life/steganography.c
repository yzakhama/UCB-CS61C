/************************************************************************
**
** NAME:        steganography.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**				Justin Yokota - Starter Code
**				YOUR NAME HERE
**
** DATE:        2020-08-23
**
**************************************************************************/

#include "imageloader.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

unsigned get_bit(unsigned x, unsigned n) {
	return ((1 << n) & x) >> n;
}

// Determines what color the cell at the given row/col should be. This should
// not affect Image, and should allocate space for a new Color.
Color* evaluateOnePixel(Image* image, int row, int col) {
	uint8_t b = image->image[row][col].B;
	if (get_bit(b, 0)) {
		Color* white = malloc(sizeof(Color));
		white->R = white->G = white->B = 255;
		return white;

	} else {
		Color* black = malloc(sizeof(Color));
		black->R = black->G = black->B = 0;
		return black;
	}
}

// Given an image, creates a new image extracting the LSB of the B channel.
Image* steganography(Image* image) {
	Image* new_image = malloc(sizeof(Image));
	new_image->cols = image->cols;
	new_image->rows = image->rows;
	new_image->image = malloc(image->rows * sizeof(Color*));
	for (int i = 0; i < image->rows; ++i) {
		new_image->image[i] = malloc(image->cols * sizeof(Color));

		for (int j = 0; j < image->cols; ++j) {
			Color* color = evaluateOnePixel(image, i, j);
			new_image->image[i][j] = *color;
			free(color);
		}
	}
	return new_image;
}

/*
Loads a file of ppm P3 format from a file, and prints to stdout (e.g. with
printf) a new image, where each pixel is black if the LSB of the B channel is 0,
and white if the LSB of the B channel is 1.

argc stores the number of arguments.
argv stores a list of arguments. Here is the expected input:
argv[0] will store the name of the program (this happens automatically).
argv[1] should contain a filename, containing a file of ppm P3 format (not
necessarily with .ppm file extension). If the input is not correct, a malloc
fails, or any other error occurs, you should exit with code -1. Otherwise, you
should return from main with code 0. Make sure to free all memory before
returning!
*/
int main(int argc, char** argv) {
	Image* image = readData(argv[1]);
	Image* decoded_image = steganography(image);
	writeData(decoded_image);
	freeImage(image);
	freeImage(decoded_image);
	return 0;
}
