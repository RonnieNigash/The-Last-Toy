#ifndef D_Objects_H
#define D_Objects_H

#include <math.h>

typedef enum Radiance_t { DIFFUSE, SPECULAR, REFRACTIVE } Radiance_t;

typedef struct Vector {
	double x;
	double y;
	double z;
} Vector;

typedef struct Sphere {
	Vector *position;
	double radius;
	Radiance_t radiance;
} Sphere;

typedef struct Ray {
	Vector *origin;
	Vector *destination;
} Ray;

Vector *initVector( double x, double y, double z );
Sphere *initSphere( Vector *position, double radius, Radiance_t radiance );
Ray *initRay( Vector *origin, Vector *destination );

Vector *addVectors( Vector *vec1, Vector *vec2 );
Vector *subVectors( Vector *vec1, Vector *vec2 );
Vector *multiplyVectors( Vector *vec1, Vector *vec2 );
Vector *multiplyVectorScalar( Vector *vec1, double scalar );
double vectorMagnitude( Vector *vec1 );
Vector *normalizeVector( Vector *vec1 );

Sphere *scaleSphereRadius( Sphere *sphere, double scalar );
Sphere *moveSpherePosition( Sphere *sphere, Vector *newPosition );

double rayIntersect( Ray *ray, Sphere *sphere );

#endif // D_OBJECTS_H
