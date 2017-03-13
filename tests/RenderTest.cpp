#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C" {
#include "objects.h"
}

#define TOL 0.0001 // Tolerance

TEST_GROUP(ObjectsTestGroup)
{
	// run before each test group
	Vector *vecA;
	Vector *vecB;
	void setup()
	{
		vecA = (Vector*)malloc(sizeof(Vector));
		vecB = (Vector*)malloc(sizeof(Vector));
	}

	// run after each test group
	void teardown()
	{
		free(vecA);
		free(vecB);
	}
};

TEST(ObjectsTestGroup, VectorInitTest)
{
	initVector(vecA, 0, 1, 2);
	DOUBLES_EQUAL(vecA->x, 0, TOL);
	DOUBLES_EQUAL(vecA->y, 1, TOL);
	DOUBLES_EQUAL(vecA->z, 2, TOL);
}

TEST(ObjectsTestGroup, VectorAddTest) {
	initVector(vecA, 0, 1, 2);
	initVector(vecB, 0, 1, 2);
	Vector *vecC = addVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 2, TOL);
	DOUBLES_EQUAL(vecC->z, 4, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorSubTest) {
	initVector(vecA, 0, 1, 2);
	initVector(vecB, 0, 1, 2);
	Vector *vecC = subVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 0, TOL);
	DOUBLES_EQUAL(vecC->z, 0, TOL);
	free(vecC);
}

TEST(ObjectsTestGroup, VectorMultiplyTest) {
	initVector(vecA, 0, 1, 2);
	initVector(vecB, 0, 1, 2);
	Vector *vecC = multiplyVectors(vecA, vecB);	
	DOUBLES_EQUAL(vecC->x, 0, TOL);
	DOUBLES_EQUAL(vecC->y, 1, TOL);
	DOUBLES_EQUAL(vecC->z, 4, TOL);
	free(vecC);
}
