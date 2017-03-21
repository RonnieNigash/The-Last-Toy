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
	void setup()
	{
		vecA = initVector( 0, 0, 0 );
		vecB = initVector( 0, 0, 0 );
		testRay = initRay( vecA, vecB );
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
	Vector *intensityVec = intensity(testRay, 1, 1);
	POINTERS_EQUAL(intensityVec, 0);
}

TEST(RenderTestGroup, RayObjectMissTest)
{
	Vector *intensityVec = intensity(testRay, 1, 1);
	DOUBLES_EQUAL(intensityVec->x,0,TOL);
	DOUBLES_EQUAL(intensityVec->y,0,TOL);
	DOUBLES_EQUAL(intensityVec->z,0,TOL);
	free(intensityVec);
}
