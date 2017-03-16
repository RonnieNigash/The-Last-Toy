#include "objects.h"

void copyVector( Vector *fromVec, Vector *toVec );
Vector *setupReturnVec( Vector *fromVec );
void copySphere( Sphere *fromSphere, Sphere *toSphere );
Sphere *setupReturnSphere( Sphere *fromSphere );

Vector *initVector( double x, double y, double z )
{
	Vector *vec = (Vector*)malloc(sizeof(Vector));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return vec;
}

Sphere *initSphere( Vector *position, double radius, Radiance_t radiance )
{
	Sphere *sphere = (Sphere*)malloc(sizeof(Sphere));
	sphere->position = position;
	sphere->radius = radius;
	sphere->radiance = radiance;
	return sphere;
}

Ray *initRay( Vector *origin, Vector* destination )
{
	Ray *ray = (Ray*)malloc(sizeof(Ray));
	ray->origin = origin;
	ray->destination = destination;
	return ray;
}

void copyVector( Vector *fromVec, Vector *toVec )
{
	toVec->x = fromVec->x;
	toVec->y = fromVec->y;
	toVec->z = fromVec->z;
}

Vector *setupReturnVec( Vector *fromVec )
{
	Vector *returnVec = (Vector*)malloc(sizeof(Vector));
	copyVector(fromVec, returnVec);
	return returnVec;
}

void copySphere( Sphere*fromSphere, Sphere *toSphere )
{
	toSphere->position = fromSphere->position;
	toSphere->radius = fromSphere->radius;
	toSphere->radiance = fromSphere->radiance;
}

Sphere *setupReturnSphere( Sphere *fromSphere )
{
	Sphere *returnSphere = (Sphere*)malloc(sizeof(Sphere));
	copySphere(fromSphere, returnSphere);
	return returnSphere;
}

Vector *addVectors( Vector *vec1, Vector *vec2 )
{
	Vector *returnVec = setupReturnVec(vec1);

	returnVec->x += vec2->x;
	returnVec->y += vec2->y;
	returnVec->z += vec2->z;
	return returnVec;
}

Vector *subVectors( Vector *vec1, Vector *vec2 )
{
	Vector *returnVec = setupReturnVec(vec1);

	returnVec->x -= vec2->x;
	returnVec->y -= vec2->y;
	returnVec->z -= vec2->z;
	return returnVec;
}

Vector *multiplyVectors( Vector *vec1, Vector *vec2 )
{
	Vector *returnVec = setupReturnVec(vec1);

	returnVec->x *= vec2->x;
	returnVec->y *= vec2->y;
	returnVec->z *= vec2->z;
	return returnVec;
}

Vector *multiplyVectorScalar( Vector *vec1, double scalar )
{
	Vector *returnVec = setupReturnVec(vec1);

	returnVec->x *= scalar;
	returnVec->y *= scalar;
	returnVec->z *= scalar;
	return returnVec;
}

double vectorMagnitude( Vector *vec1 )
{
	double x, y, z;
	x = vec1->x;
	y = vec1->y;
	z = vec1->z;
	return sqrt(fabs(x*x + y*y + z*z));
}

Vector *normalizeVector( Vector *vec1 )
{
	Vector *returnVec = setupReturnVec(vec1);

	double magnitude = vectorMagnitude( returnVec );
	returnVec->x /= magnitude;
	returnVec->y /= magnitude;
	returnVec->z /= magnitude;
	return returnVec;
}

Sphere *scaleSphereRadius( Sphere *sphere, double scalar )
{
	Sphere *returnSphere = setupReturnSphere(sphere);

	returnSphere->radius *= scalar;
	return returnSphere;
}

Sphere *moveSpherePosition( Sphere *sphere, Vector *newPosition )
{
	Sphere *returnSphere = setupReturnSphere(sphere);

	returnSphere->position = newPosition;
	return returnSphere;
}

double rayIntersect( Ray *ray, Sphere *sphere ) // returns distance from ray to sphere, returns 0 if ray doesn't hit
{
	Vector *newVec = subVectors(sphere->position, ray->origin);

	double bound;
	double tolerance=0.0001;

	Vector *testVec = multiplyVectors(newVec, ray->destination);
	free(newVec);

	double mag = vectorMagnitude(testVec);
	mag *= mag; // get dot product of vector with ray's destination vector

	Vector *test2Vec = multiplyVectors(testVec, testVec);
	free(testVec);

	double determinant = (mag*mag) - vectorMagnitude(test2Vec) + (sphere->radius * sphere->radius);
	free(test2Vec);

	// solving: bound^2 * destination^2 + 2* destination of Vec(origin - position) + (origin - position) of Vec(origin - position) - ray ^2 = 0
	if (determinant < 0 ) {
		return 0;
	} else {
		determinant = sqrt(determinant);
	}

	if ( ((bound = mag - determinant) > tolerance) || ((bound = mag + determinant) > tolerance) ) {
		return bound;
	}  else {
		return 0;
	}
}
