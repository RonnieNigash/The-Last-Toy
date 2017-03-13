#include "objects.h"

void copyVector( Vector *fromVec, Vector *toVec );
Vector *setupReturnVec( Vector *fromVec );

void initVector( Vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
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

Vector *normalizeVector( Vector *vec1 )
{
	Vector *returnVec = setupReturnVec(vec1);

	double x, y, z, magnitude;
	x = returnVec->x;
	y = returnVec->y;
	z = returnVec->z;
	magnitude = sqrt(fabs(x*x + y*y + z*z));
	returnVec->x /= magnitude;
	returnVec->y /= magnitude;
	returnVec->z /= magnitude;
	return returnVec;
}
