#include "pch.h"

TEST(ColorTests, ColorTuple)
{
	Color c(-0.5, 0.4, 1.7);

	EXPECT_FLOAT_EQ(c.R(), -0.5);
	EXPECT_FLOAT_EQ(c.G(), 0.4);
	EXPECT_FLOAT_EQ(c.B(), 1.7);
}

TEST(ColorTets, AddTwoColors)
{
	Color c1(0.9, 0.6, 0.75);
	Color c2(0.7, 0.1, 0.25);

	EXPECT_TRUE(c1 + c2 == Color(1.6, 0.7, 1.0));
}

TEST(ColorTests, SubtractTwoColors)
{
	Color c1(0.9, 0.6, 0.75);
	Color c2(0.7, 0.1, 0.25);

	EXPECT_TRUE(c1 - c2 == Color(0.2, 0.5, 0.5));
}

TEST(ColorTests, MultiplyColorByScalar)
{
	Color c(0.2, 0.3, 0.4);
	
	EXPECT_TRUE(c * 2 == Color(0.4, 0.6, 0.8));
}

TEST(ColorTests, HadamardProduct)
{
	Color c1(1, 0.2, 0.4);
	Color c2(0.9, 1, 0.1);

	EXPECT_TRUE(c1 * c2 == Color(0.9, 0.2, 0.04));
}