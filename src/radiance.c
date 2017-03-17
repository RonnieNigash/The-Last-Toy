#include "radiance.h"

Vector *intensity(Ray *ray, uint8_t recursionDdepth, uint8_t randomSeed)
{
	// returns vector which estimates the intensity of a ray	
	double distanceToIntersect;

	int objectID = 0;

	// if ray and object do not intersect
	// 	return 0 intensity (black)
	// if max reflectance reached, return max intensity (white)
	// if object is diffusive
	// 	Implement Ray Tracing Algorithm
	// else if object is specular
	// 	call intensity(...) with specular equation
	// if total internal reflection
	// 	call intensity(...) with total internal reflection equation
	// if the ray has been reflected numerous times // use the recursionDepth
	// 	determine if the intensity(...) equation should be called again
	// 		// Use random numbers to determine recursion depth
	
	return initVector(0, 0, 0); // placeholder for implementation
}
