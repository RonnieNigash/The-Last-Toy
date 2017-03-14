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
	void setup()
	{
		testSphere = (Sphere*)malloc(sizeof(Sphere));
		vecA = (Vector*)malloc(sizeof(Vector));
		vecB = (Vector*)malloc(sizeof(Vector));
		initVector( vecA, 0, 1, 2 );
		initVector( vecB, 0, 1, 2 );
		initSphere( testSphere, vecA, 5 );
	}

	// run after each test group
	void teardown()
	{
		free(testSphere);
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
	DOUBLES_EQUAL(vecC->y, 2, TOL);
	DOUBLES_EQUAL(vecC->z, 4, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorSubTest)
{
	Vector *vecC = subVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 0, TOL);
	DOUBLES_EQUAL(vecC->z, 0, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorMultiplyTest)
{
	Vector *vecC = multiplyVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 1, TOL);
	DOUBLES_EQUAL(vecC->z, 4, TOL);
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
	DOUBLES_EQUAL(testSphere->radius, 5, TOL);
}

TEST(ObjectsTestGroup, SphereScaleTest)
{
	Sphere *newSphere = scaleSphereRadius(testSphere, 2);
	
	POINTERS_EQUAL(newSphere->position, vecA);
	DOUBLES_EQUAL(newSphere->radius, 10, TOL);
	free(newSphere);
}

TEST(ObjectsTestGroup, SphereMoveTest)
{
	Sphere *newSphere = moveSpherePosition(testSphere, vecB);
	
	POINTERS_EQUAL(newSphere->position, vecB);
	DOUBLES_EQUAL(newSphere->radius, 5, TOL);
	free(newSphere);
}
