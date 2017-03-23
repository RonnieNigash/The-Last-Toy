#include <stdlib.h>

#include "objects.h"
#include "intensity.h"

int main( int argc, char *argv[] ) {

	// initialize camera
	Vector *position = initVector(50, 50, 300);
	Vector *direction= initVector(0, 0, -1);
	Ray *camera = initRay(position, direction);

	// initialize array for the image
	int width = 1680, height = 1050;

	int samples = 8; 

	if (argc == 2) {
		samples = atoi(argv[1])/4;
	}	


	// for each pixel
	// 	split into 2x2 sub pixels
	// 	average the intensity samples
	// 	set values to the image array
	
	// write the image file




	exit(0);
}
