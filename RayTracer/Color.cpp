#include "Color.h"
#include <sstream>

std::string Color::DebugString() const
{
	std::stringstream stream;
	stream << "(" << R() << ", " << G() << ", " << B() << ")";

	return stream.str();
}

Color Color::ScaleColorValue(int maxColorValue)
{
	int rc = ScaleColorComponent(R(), maxColorValue);
	int gc = ScaleColorComponent(G(), maxColorValue);
	int bc = ScaleColorComponent(B(), maxColorValue);

	return Color(rc, gc, bc);
}

std::string Color::CanvasOutputString() const
{
	std::stringstream stream;
	stream << R() << " " << G() << " " << B() << " ";

	return stream.str();
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
	os << c.DebugString();
	return os;
}

float Color::R() const
{
	return X();
}

float Color::G() const
{
	return Y();
}

float Color::B() const
{
	return Z();
}

Color operator*(const Color& lhs, const Color& rhs)
{
	float rc = lhs.R() * rhs.R();
	float gc = lhs.G() * rhs.G();
	float bc = lhs.B() * rhs.B();

	return Color(rc, gc, bc);
}

int ScaleColorComponent(float component, int maxColorValue)
{
	int scaledVal = component * maxColorValue;

	if (scaledVal < 0)
	{
		scaledVal = 0;
	}

	else if (scaledVal > maxColorValue)
	{
		scaledVal = maxColorValue;
	}

	return scaledVal;
}