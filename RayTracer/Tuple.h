#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

class Tuple
{
public:
	Tuple():m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) {};
	Tuple(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) {};
	~Tuple() = default;

	bool IsPoint() const;
	bool IsVector() const;

	//Getters
	float X() const;
	float Y() const;
	float Z() const;
	float W() const;

	// Setter
	void SetW(float w);

	//Tuple functions
	Tuple Negate() const;
	float Magnitude() const;
	Tuple Normalize() const;
	float Dot(const Tuple& rhs) const;
	Tuple Cross(const Tuple& rhs) const;

private:
	// Tuple components
	float m_x;
	float m_y;
	float m_z;
	float m_w;
};

// Operations on Tuples
bool operator==(const Tuple& lhs, const Tuple& rhs);
Tuple operator+(const Tuple& lhs, const Tuple& rhs);
Tuple operator-(const Tuple& lhs, const Tuple& rhs);
Tuple operator-(const Tuple& neg);
Tuple operator*(const Tuple& t, float c);
Tuple operator/(const Tuple& t, float c);

// Functions for creating particular types of Tuples
Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif // TUPLE_H