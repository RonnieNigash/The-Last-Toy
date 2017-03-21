#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C" {
#include "objects.h"
#include "intensity.h"
}

#define TOL 0.0001 // Tolerance

TEST_GROUP(RenderTestGroup)
{
	// run before each test group
	Ray *testRay;
	Vector *vecA;
	Vector *vecB;
	Sphere *arrayOfSpheres[3];
	void setup()
	{
		vecA = initVector( 0, 0, 0 );
		vecB = initVector( 0, 0, 0 );
		testRay = initRay( vecA, vecB );

		int i;
		int numOfSpheres = sizeof(arrayOfSpheres) / sizeof(Sphere);
		for (i = 0; i < numOfSpheres; i++) {
			arrayOfSpheres[i]->position = vecA;
			arrayOfSpheres[i]->radius = i;
		}
	}

	void teardown()
	{
		free(vecA);
		free(vecB);
		free(testRay);
	}
};

TEST(RenderTestGroup, InitTest)
{
	Vector *intensityVec = intensity(arrayOfSpheres, testRay, 1, 1);
	POINTERS_EQUAL(intensityVec, 0);
	free(intensityVec);
}

TEST(RenderTestGroup, RayObjectMissTest)
{
	Vector *intensityVec = intensity(arrayOfSpheres, testRay, 1, 1);
	DOUBLES_EQUAL(intensityVec->x,0,TOL);
	DOUBLES_EQUAL(intensityVec->y,0,TOL);
	DOUBLES_EQUAL(intensityVec->z,0,TOL);
	free(intensityVec);
}
