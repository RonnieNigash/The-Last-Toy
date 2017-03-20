#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C" {
#include "objects.h"
}

#define TOL 0.0001 // Tolerance

TEST_GROUP(ObjectsTestGroup)
{
	// run before each test group
	Sphere *testSphere;
	Vector *vecA;
	Vector *vecB;
	Ray *testRay;
	Sphere *arrayOfSpheres[3];
	void setup()
	{
		vecA = initVector( 0, 1, 2 );
		vecB = initVector( 0, 2, 1 );
		testSphere = initSphere( vecA, 1, REFRACTIVE );
		testRay = initRay( vecA, vecB );

		int i;
		int numOfSpheres = sizeof(arrayOfSpheres) / sizeof(Sphere);
		for (i = 0; i < numOfSpheres; i++) {
			arrayOfSpheres[i]->position = vecA;
			arrayOfSpheres[i]->radius = i;
		}
	}

	// run after each test group
	void teardown()
	{
		free(testSphere);
		free(testRay);
		free(vecA);
		free(vecB);
	}
};

TEST(ObjectsTestGroup, VectorInitTest)
{
	DOUBLES_EQUAL(vecA->x, 0, TOL);
	DOUBLES_EQUAL(vecA->y, 1, TOL);
	DOUBLES_EQUAL(vecA->z, 2, TOL);
}

TEST(ObjectsTestGroup, VectorAddTest)
{
	Vector *vecC = addVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 3, TOL);
	DOUBLES_EQUAL(vecC->z, 3, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorSubTest)
{
	Vector *vecC = subVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, -1, TOL);
	DOUBLES_EQUAL(vecC->z, 1, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorMultiplyTest)
{
	Vector *vecC = multiplyVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 2, TOL);
	DOUBLES_EQUAL(vecC->z, 2, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorMultiplyScalarTest)
{
	Vector *vecC = multiplyVectorScalar(vecA, 3);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 3, TOL);
	DOUBLES_EQUAL(vecC->z, 6, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorNormalizeTest)
{
	Vector *vecC = normalizeVector(vecA);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 0.4472, TOL); // 1/sqrt(5)
	DOUBLES_EQUAL(vecC->z, 0.8944, TOL); // 2/sqrt(5)
	free(vecC);
}

TEST(ObjectsTestGroup, VectorMagnitudeTest)
{
	double vecAMag = vectorMagnitude( vecA );
	DOUBLES_EQUAL( vecAMag, 2.2361, TOL); // 2.2361 = sqrt(5)
}

TEST(ObjectsTestGroup, SphereInitTest)
{
	POINTERS_EQUAL(testSphere->position, vecA);
	DOUBLES_EQUAL(testSphere->radius, 1, TOL);
}

TEST(ObjectsTestGroup, SphereScaleTest)
{
	Sphere *newSphere = scaleSphereRadius(testSphere, 2);
	
	POINTERS_EQUAL(newSphere->position, vecA);
	DOUBLES_EQUAL(newSphere->radius, 2, TOL);
	free(newSphere);
}

TEST(ObjectsTestGroup, SphereMoveTest)
{
	Sphere *newSphere = moveSpherePosition(testSphere, vecB);
	
	POINTERS_EQUAL(newSphere->position, vecB);
	DOUBLES_EQUAL(newSphere->radius, 1, TOL);
	free(newSphere);
}

TEST(ObjectsTestGroup, RayInitTest)
{
	POINTERS_EQUAL(testRay->origin, vecA);
	POINTERS_EQUAL(testRay->destination, vecB);
}

TEST(ObjectsTestGroup, RayIntersectTest)
{
	double distance = rayIntersect(testRay, testSphere);
	
	CHECK_TRUE(distance > 0 || distance < 0 );
	POINTERS_EQUAL(testRay->origin, vecA);
	POINTERS_EQUAL(testRay->destination, vecB);
}

TEST(ObjectsTestGroup, ArrayOfSpheresTest)
{
	int i;
	int numOfSpheres = sizeof(arrayOfSpheres) / sizeof(Sphere);
	for (i = 0; i < numOfSpheres; i++) {
		POINTERS_EQUAL(arrayOfSpheres[i]->position, vecA);
		DOUBLES_EQUAL(arrayOfSpheres[i]->radius, (double)i, TOL);
	}
}

TEST(ObjectsTestGroup, ObjectIlluminanceTypeTest)
{
	BYTES_EQUAL(testSphere->radiance, REFRACTIVE);	
}
