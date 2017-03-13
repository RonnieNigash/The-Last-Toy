#include "objects.h"

void initVector( struct Vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

Vector *addVectors( Vector *vec1, Vector *vec2 )
{
	Vector *returnVec = (Vector*)malloc(sizeof(Vector));
	returnVec->x = vec1->x + vec2->x;
	returnVec->y = vec1->y + vec2->y;
	returnVec->z = vec1->z + vec2->z;
	return returnVec;
}
