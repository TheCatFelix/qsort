#include "stdio.h"

union pixel_type {

	unsigned int pixel:32;
	struct {
		unsigned int a:8;
		unsigned int b:8;
		unsigned int g:8;
		unsigned int r:8;
	};

};

void main() {

union pixel_type my_pixel;

// Format in memory: 
//                 RRGGBBAA 
my_pixel.pixel = 0xAABBCCDD;

printf("Pixel %x\n\n", my_pixel.pixel);

my_pixel.g = 0x11;

printf("Pixel %x\n\n", my_pixel.pixel);

printf("R %x\n", my_pixel.r);
printf("G %x\n", my_pixel.g);
printf("B %x\n", my_pixel.b);
printf("A %x\n", my_pixel.a);

}
