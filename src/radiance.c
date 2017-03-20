#include "radiance.h"

bool rayMissObject( Ray *ray, double *distanceToIntersect, int *objectID );

bool rayMissObject( Ray *ray, double *distanceToIntersect, int *objectID )
{
	int numSpheres = sizeof(arrayOfSpheres) / sizeof(Sphere);	
	double intersect = 0;
	uint32_t infinity = (uint32_t)1e18;

	int id;
	for (id = numSpheres; id >= 0; id--) {
		Sphere *mySphere = arrayOfSpheres[id];
//		intersect = rayIntersect( ray, arrayOfSpheres[id] );
		intersect = rayIntersect( ray, mySphere );
		if ( (int)intersect && (intersect < infinity) ) {
			*distanceToIntersect = intersect;
			*objectID = id;
		}
	}

	return *distanceToIntersect < infinity;
}


Vector *intensity(Ray *ray, uint8_t recursionDepth, uint8_t randomSeed)
{
	// returns vector which estimates the intensity of a ray	
	double *distanceToIntersect = NULL;
	recursionDepth += recursionDepth;
	randomSeed += randomSeed;

	int *objectID = 0;

	if ( rayMissObject(ray, distanceToIntersect, objectID) ) { // if ray and object do not intersect
		printf ( "distanceToIntersect = %f\n", *distanceToIntersect );
		return initVector(0,0,0); // return 0 intensity (black)
	}

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

	return NULL; // placeholder for implementation
}
