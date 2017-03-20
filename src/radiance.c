#include "radiance.h"

bool rayMissObject( Ray *ray, double *distanceToIntersect, int *objectID );

bool rayMissObject( Ray *ray, double *distanceToIntersect, int *objectID )
{
	int numSpheres = sizeof(arrayOfSpheres) / sizeof(Sphere);	
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

	Sphere *object = arrayOfSpheres[*objectID];

	Vector *scaledDestinationVec = multiplyVectorScalar(ray->destination, *distanceToIntersect);

	Vector *vecAdded = addVectors(ray->origin, scaledDesinationVec);

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

	if ( ++depth > 5 ) { 
	// if max reflectance reached, return max intensity (white)
		return initVector(255,255,255); // return 1 intensity (white)
	}

	if ( object->Radiance_t == DIFFUSE ) {
		// if object is diffusive
		// handle diffusive with Ray Tracing Algorithm
	} else if ( object->Radiance_t == SPECULAR ) {
		// else if object is specular
		// handle specular
	 	// call intensity(...) with specular equation
	}
	
	Vector *scaledVec = multiplyVectorScalar( vecNormalized, 2);
	Vector *firstVec = multiplyVectors(scaledVec, ray->destination);
	Vector *secondVec = multiplyVectors(vecNormalized, firstVec);
	Vector *scaledNewDestinationRay = subVectors(ray->destination, secondVec);	
	Ray *refractedRay = initRay( scaledDestinationRay, scaledNewDestinationRay ); // origin is the destination of incident
	free(scaledVec);
	free(firstVec);
	free(secondVec);
	free(scaledNewDestinationRay);

	Vector *dottedVec = multiplyVectors(vecNormalized, newVecNormalized);
	bool rayIntoObject = vectorMagnitude(dottedVec) > 0; // true if going into, false if going out of object
	free(dottedVec);

	// if total internal reflection
	// 	call intensity(...) with total internal reflection equation
	// if the ray has been reflected numerous times // use the recursionDepth
	// 	determine if the intensity(...) equation should be called again
	// 		// Use random numbers to determine recursion depth

	return NULL; // placeholder for implementation
}
