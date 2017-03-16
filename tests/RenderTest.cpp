#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C" {
#include "objects.h"
}

#define TOL 0.0001 // Tolerance

TEST_GROUP(RenderTestGroup)
{
	// run before each test group
	void setup()
	{
	}

	// run after each test group
	void teardown()
	{
	}
};

TEST(RenderTestGroup, InitTest)
{
}
