#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Color {
	uint8_t R;
	uint8_t G;
	uint8_t B;
} Color;

typedef struct Image {
	Color** image;
	uint32_t rows;
	uint32_t cols;
} Image;

/** Opens a .ppm P3 image file, and constructs an Image object. */
extern Image* readData(char* filename);

/** Writes an image to stdout. */
extern void writeData(Image* image);

/** Frees an image and all its associated data. */
extern void freeImage(Image* image);
