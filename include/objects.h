#ifndef D_Objects_H
#define D_Objects_H

#include <math.h>

typedef struct Vector {
	double x;
	double y;
	double z;
} Vector;

typedef struct Sphere {
	Vector position;
	double radius;
} Sphere;

void initVector( struct Vector *vec, double x, double y, double z);

Vector *addVectors( Vector *vec1, Vector *vec2 );
Vector *subVectors( Vector *vec1, Vector *vec2 );
Vector *multiplyVectors( Vector *vec1, Vector *vec2 );
Vector *multiplyVectorScalar( Vector *vec1, double scalar );
Vector *normalizeVector( Vector *vec1 );

#endif // D_OBJECTS_H
