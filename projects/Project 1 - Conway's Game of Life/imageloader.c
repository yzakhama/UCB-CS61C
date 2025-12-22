/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include "imageloader.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Image* readData(char* filename) {
	FILE* file = fopen(filename, "r");
	if (NULL == file) {
		return NULL;
	}

	char* format;
	fscanf(file, "%s", &format);

	printf("%d\n", *format);
	/*for (size_t i = 0; i < 20; i++) {
		printf("%c\n", buffer[i]);
	}*/

	fclose(file);
	return NULL; // TODO: remove
}

// Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the
// image's data.
void writeData(Image* image) {
	// YOUR CODE HERE
}

void freeImage(Image* image) {
}
