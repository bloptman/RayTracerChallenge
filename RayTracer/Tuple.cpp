#include "RayTracerMath.h"
#include "Tuple.h"
#include <sstream>

bool Tuple::IsPoint() const
{
	return m_w == 1.0f;
}

bool Tuple::IsVector() const
{
	return m_w == 0.0f;
}

float Tuple::X() const
{
	return m_x;
}

float Tuple::Y() const
{
	return m_y;
}

float Tuple::Z() const
{
	return m_z;
}

float Tuple::W() const
{
	return m_w;
}

void Tuple::SetW(float w)
{
	m_w = w;
}

Tuple Tuple::Negate() const
{
	return (*this) * -1;
}

float Tuple::Magnitude() const
{
	// Compute the square of each component 
	float xc = m_x * m_x;
	float yc = m_y * m_y;
	float zc = m_z * m_z;
	float wc = m_w * m_w;

	return std::sqrt(xc + yc + zc + wc);
}

Tuple Tuple::Normalize() const
{
	float mag = Magnitude();
	return Tuple(m_x/mag, m_y/mag, m_z/mag, m_w/mag);
}

float Tuple::Dot(const Tuple& rhs) const
{
	// Compute the component wise products
	float xc = m_x * rhs.m_x;
	float yc = m_y * rhs.m_y;
	float zc = m_z * rhs.m_z;
	float wc = m_w * rhs.m_w;

	return xc + yc + zc + wc;
}

Tuple Tuple::Cross(const Tuple& rhs) const
{
	// Compute each component of resulting Vector
	float xc = (m_y * rhs.m_z) - (m_z * rhs.m_y);
	float yc = (m_z * rhs.m_x) - (m_x * rhs.m_z);
	float zc = (m_x * rhs.m_y) - (m_y * rhs.m_x);

	return Vector(xc, yc, zc);
}

bool operator==(const Tuple& lhs, const Tuple& rhs)
{
	// Check for equality for each component
	bool xc = IsEqual(lhs.X(), rhs.X());
	bool yc = IsEqual(lhs.Y(), rhs.Y());
	bool zc = IsEqual(lhs.Z(), rhs.Z());
	bool wc = IsEqual(lhs.W(), rhs.W());

	return xc && yc && zc && wc;
}

Tuple operator+(const Tuple& lhs, const Tuple& rhs)
{
	// Compute each component
	float xc = lhs.X() + rhs.X();
	float yc = lhs.Y() + rhs.Y();
	float zc = lhs.Z() + rhs.Z();
	float wc = lhs.W() + rhs.W();

	return Tuple(xc, yc, zc, wc);
}

Tuple operator-(const Tuple& lhs, const Tuple& rhs)
{
	// Compute each component
	float xc = lhs.X() - rhs.X();
	float yc = lhs.Y() - rhs.Y();
	float zc = lhs.Z() - rhs.Z();
	float wc = lhs.W() - rhs.W();

	return Tuple(xc, yc, zc, wc);
}

Tuple operator-(const Tuple& neg)
{
	return Tuple(-neg.X(), -neg.Y(), -neg.Z(), -neg.W());
}

Tuple operator*(const Tuple& rhs, float c)
{
	float xc = c * rhs.X();
	float yc = c * rhs.Y();
	float zc = c * rhs.Z();
	float wc = c * rhs.W();

	return Tuple(xc, yc, zc, wc);
}

Tuple operator/(const Tuple& lhs, float c)
{
	float xc = lhs.X() / c;
	float yc = lhs.Y() / c;
	float zc = lhs.Z() / c;
	float wc = lhs.W() / c;

	return Tuple(xc, yc, zc, wc);
}

std::string Tuple::DebugString() const
{
	std::stringstream stream;

	stream << "<" << m_x << ", " << m_y << ", " << m_z << ", " << m_w << ">";
	return stream.str();
}

std::ostream& operator<<(std::ostream& os, const Tuple& t)
{
	os << t.DebugString();
	return os;
}

Tuple Point(float x, float y, float z)
{
	return Tuple(x, y, z, 1.0f);
}

Tuple Vector(float x, float y, float z)
{
	return Tuple(x, y, z, 0-.0f);
}