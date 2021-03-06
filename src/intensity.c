#include "objects.h"
#include "intensity.h"

bool rayMissObject( Sphere *arrayOfSpheres[], Ray *ray, double *distanceToIntersect, int *objectID );

bool rayMissObject( Sphere *arrayOfSpheres[], Ray *ray, double *distanceToIntersect, int *objectID )
{
	int numSpheres = sizeof(arrayOfSpheres) / sizeof(arrayOfSpheres[0]);	
	double intersect = 0;
	uint32_t infinity = (uint32_t)1e18;

	int id;
	for (id = numSpheres; id >= 0; id--) {
		intersect = rayIntersect( ray, arrayOfSpheres[id] );
		if ( (int)intersect && (intersect < infinity) ) {
			*distanceToIntersect = intersect;
			*objectID = id;
		}
	}

	return *distanceToIntersect < infinity;
}


Vector *intensity(Sphere *arrayOfSpheres[], Ray *ray, uint8_t recursionDepth, uint8_t randomSeed)
{
	// returns vector which estimates the intensity of a ray	
	double distanceToIntersect = 0;
	recursionDepth += recursionDepth;
	randomSeed += randomSeed;

	int objectID = 0;

	if ( rayMissObject(arrayOfSpheres, ray, &distanceToIntersect, &objectID) ) { // if ray and object do not intersect
		printf ( "distanceToIntersect = %f\n", distanceToIntersect );
		return initVector(0,0,0); // return 0 intensity (black)
	}

	Sphere *object = arrayOfSpheres[objectID];

	Vector *scaledDestinationVec = multiplyVectorScalar(ray->destination, distanceToIntersect);

	Vector *vecAdded = addVectors(ray->origin, scaledDestinationVec);

	Vector *vecSubtracted = subVectors(vecAdded, object->position);
	free(vecAdded);

	Vector *vecNormalized = normalizeVector(vecSubtracted);
	free(vecSubtracted);

	Vector *direction = multiplyVectors(vecNormalized, ray->destination);
	
	Vector *newVecNormalized;

	if ( vectorMagnitude(direction) < 0 ) {
		newVecNormalized = vecNormalized;
	} else {
		newVecNormalized = multiplyVectorScalar(vecNormalized, -1);
	}
	free(direction);

	if ( ++recursionDepth > 5 ) { 
	// if max reflectance reached, return max intensity (white)
		return initVector(255,255,255); // return 1 intensity (white)
	}

	if ( object->radiance == DIFFUSE ) {
		// if object is diffusive
		// handle diffusive with Ray Tracing Algorithm
	} else if ( object->radiance == SPECULAR ) {
		// else if object is specular
		// handle specular
	 	// call intensity(...) with specular equation
	}
	
	Vector *scaledVec = multiplyVectorScalar( vecNormalized, 2);
	Vector *firstVec = multiplyVectors(scaledVec, ray->destination);
	Vector *secondVec = multiplyVectors(vecNormalized, firstVec);
	Vector *scaledNewDestinationRay = subVectors(ray->destination, secondVec);	
	Ray *refractedRay = initRay( scaledDestinationVec, scaledNewDestinationRay ); // origin is the destination of incident
	free(scaledVec);
	free(firstVec);
	free(secondVec);
	free(scaledNewDestinationRay);

	Vector *dottedVec = multiplyVectors(vecNormalized, newVecNormalized);
	bool rayIntoObject = vectorMagnitude(dottedVec) > 0; // true if going into, false if going out of object
	free(dottedVec);

	double notClose = 1.0;
	double notIntersection = 1.5;
	double secondIntersection = rayIntoObject ? notClose / notIntersection : notIntersection / notClose;
	Vector *secondDottedVec  = multiplyVectors(ray->destination, newVecNormalized);
	double didNotIntersect = vectorMagnitude(secondDottedVec);
	free(secondDottedVec);

	// if total internal reflection
	// 	call intensity(...) with total internal reflection equation
	

	// if the ray has been reflected numerous times // use the recursionDepth
	// 	determine if the intensity(...) equation should be called again
	// 		// Use random numbers to determine recursion depth

	return NULL; // placeholder for implementation
}
