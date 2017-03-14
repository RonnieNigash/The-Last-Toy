#include "objects.h"

void copyVector( Vector *fromVec, Vector *toVec );
Vector *setupReturnVec( Vector *fromVec );

void initVector( Vector *vec, double x, double y, double z )
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void initSphere( Sphere *sphere, Vector *position, double radius )
{
	sphere->position = position;
	sphere->radius = radius;
}

void copyVector( Vector *fromVec, Vector *toVec )
{
	toVec->x = fromVec->x;
	toVec->y = fromVec->y;
	toVec->z = fromVec->z;
}

Vector *setupReturnVec( Vector *fromVec )
{
	Vector *returnVec = malloc(sizeof(Vector));
	copyVector(fromVec, returnVec);
	return returnVec;
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

