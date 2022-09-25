#include "Color.h"
#include <sstream>

std::string Color::DebugString() const
{
	std::stringstream stream;
	stream << "(" << R() << ", " << G() << ", " << B() << ")";

	return stream.str();
}

std::ostream& operator<<(std::ostream& os, const Color& c)
{
	os << c.DebugString() << std::endl;
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

