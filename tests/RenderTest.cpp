#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C" {
#include "objects.h"
}

TEST_GROUP(RenderTest)
{
	// run before each test
	void setup()
	{
	}

	// run after each test
	void teardown()
	{
	}
};

TEST(RenderTest, FirstTest)
{
	Vector *myVec = (Vector*)malloc(sizeof(Vector));
	myVec->x = 5;
	myVec->y = 10;
	myVec->z = 15;
	LONGS_EQUAL(myVec->x, 5);
	LONGS_EQUAL(myVec->y, 10);
	LONGS_EQUAL(myVec->z, 15);
	free(myVec);
}
