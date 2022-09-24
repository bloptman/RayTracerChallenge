#include "pch.h"

TEST(TupleTests, PointBasic)
{
	Tuple t(4.3, -4.2, 3.1, 1.0);

	EXPECT_FLOAT_EQ(t.X(), 4.3);
	EXPECT_FLOAT_EQ(t.Y(), -4.2);
	EXPECT_FLOAT_EQ(t.Z(), 3.1);
	EXPECT_FLOAT_EQ(t.W(), 1.0);

	EXPECT_TRUE(t.IsPoint());
	EXPECT_FALSE(t.IsVector());

}

TEST(TupleTests, VectorBasic)
{
	Tuple t(4.3, -4.2, 3.1, 0.0);

	EXPECT_FLOAT_EQ(t.X(), 4.3);
	EXPECT_FLOAT_EQ(t.Y(), -4.2);
	EXPECT_FLOAT_EQ(t.Z(), 3.1);
	EXPECT_FLOAT_EQ(t.W(), 0.0);

	EXPECT_TRUE(t.IsVector());
	EXPECT_FALSE(t.IsPoint());
}

TEST(TupleTests, TupleEqualityOperator)
{
	Tuple a(1, 2, 3, 4);
	Tuple b(1, 2, 3, 4);

	EXPECT_TRUE(a == b);
}

TEST(TupleTests, CreatePoint)
{
	Tuple p = Point(4, -4, 3);
	Tuple t(4, -4, 3, 1);

	EXPECT_TRUE(p == t);
}

TEST(TupleTests, CreateVector)
{
	Tuple v = Vector(4, -4, 3);
	Tuple t(4, -4, 3, 0);

	EXPECT_TRUE(v == t);
}

TEST(TupleTests, IsPoint)
{
	Tuple p = Point(1, 2, 3);

	EXPECT_TRUE(p.IsPoint());
	EXPECT_FALSE(p.IsVector());
}

TEST(TupleTests, IsVector)
{
	Tuple v = Vector(1, 2, 3);

	EXPECT_TRUE(v.IsVector());
	EXPECT_FALSE(v.IsPoint());
}

TEST(TupleTests, AddTwoTuples)
{
	Tuple a(3, -2, 5, 1);
	Tuple b(-2, 3, 1, 0);

	EXPECT_TRUE(a + b == Tuple(1, 1, 6, 1));
}

TEST(TupleTests, SubtractTwoPoints)
{
	Tuple a = Point(3, 2, 1);
	Tuple b = Point(5, 6, 7);

	EXPECT_TRUE(a - b == Vector(-2, -4, -6));
}

TEST(TupleTests, SubtractVectorFromPoint)
{
	Tuple p = Point(3, 2, 1);
	Tuple v = Vector(5, 6, 7);

	EXPECT_TRUE(p - v == Point(-2, -4, -6));
}

TEST(TupleTests, SubtractTwoVectors)
{
	Tuple a = Vector(3, 2, 1);
	Tuple b = Vector(5, 6, 7);

	EXPECT_TRUE(a - b == Vector(-2, -4, -6));
}

TEST(TupleTests, NegateVectorWithZeroVector)
{
	Tuple zero = Vector(0, 0, 0);
	Tuple v = Vector(1, -2, 3);

	EXPECT_TRUE(zero - v == Vector(-1, 2, -3));
}

TEST(TupleTests, NegateVector)
{
	Tuple a(1, -2, 3, -4);
	Tuple negation = Tuple(-1, 2, -3, 4);

	EXPECT_TRUE(-a == negation);
	EXPECT_TRUE(a.Negate() == negation);
}

TEST(TupleTests, TupleScalarMultiplication)
{
	Tuple a(1, -2, 3, -4);

	EXPECT_TRUE(a * 3.5 == Tuple(3.5, -7, 10.5, -14));
	EXPECT_TRUE(a * 0.5 == Tuple(0.5, -1, 1.5, -2));
}

TEST(TupleTests, TupleScalarDivison)
{
	Tuple a(1, -2, 3, -4);

	EXPECT_TRUE(a / 2 == Tuple(0.5, -1, 1.5, -2));
}

TEST(TupleTests, VectorMagnitude)
{
	Tuple v = Vector(1, 0, 0);
	Tuple u = Vector(0, 0, 1);
	Tuple w = Vector(1, 2, 3);
	Tuple q = Vector(-1, -2, -3);

	EXPECT_FLOAT_EQ(v.Magnitude(), 1);
	EXPECT_FLOAT_EQ(u.Magnitude(), 1);
	EXPECT_FLOAT_EQ(w.Magnitude(), std::sqrt(14));
	EXPECT_FLOAT_EQ(q.Magnitude(), std::sqrt(14));
}

TEST(TupleTests, VectorNormalization)
{
	Tuple v = Vector(4, 0, 0);
	Tuple u = Vector(1, 2, 3);

	EXPECT_TRUE(v.Normalize() == Vector(1, 0, 0));
	EXPECT_TRUE(u.Normalize() == Vector(0.26726, 0.53452, 0.80178));
	EXPECT_FLOAT_EQ((u.Normalize()).Magnitude(), 1);
}

TEST(TupleTests, VectorDotProduct)
{
	Tuple a = Vector(1, 2, 3);
	Tuple b = Vector(2, 3, 4);

	EXPECT_FLOAT_EQ(a.Dot(b), 20);
}

TEST(TupleTests, VectorCrossProdcut)
{
	Tuple a = Vector(1, 2, 3);
	Tuple b = Vector(2, 3, 4);

	EXPECT_TRUE(a.Cross(b) == Vector(-1, 2, -1));
	EXPECT_TRUE(b.Cross(a) == Vector(1, -2, 1));
}