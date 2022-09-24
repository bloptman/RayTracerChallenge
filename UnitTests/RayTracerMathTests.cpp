#include "pch.h"

TEST(IsEqualTests, SameNumbers)
{
	EXPECT_TRUE(IsEqual(1.0f, 1.0f));
}

TEST(IsEqualTests, DifferentNumbers)
{
	EXPECT_FALSE(IsEqual(1.0f, 2.0f));
}

TEST(IsEqualTests, DefaultTolerance)
{
	EXPECT_TRUE(IsEqual(1.0f, 1.000001f));
	EXPECT_FALSE(IsEqual(1.0f, 1.01f));
}

TEST(IsEqualTests, LargeTolerance)
{
	float tol = 10.0f; 
	EXPECT_TRUE(IsEqual(1.0f, 5.0f, tol));
	EXPECT_FALSE(IsEqual(1.0f, 11.0f, tol));
}
