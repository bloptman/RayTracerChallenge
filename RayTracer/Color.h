#ifndef COLOR_H
#define COLOR_H

#include "Tuple.h"
#include <string>

class Color : public Tuple
{
public:
	Color() : Tuple() {};
	Color(float r, float g, float b) : Tuple(r, g, b, 0.0f) {};
	~Color() = default;

	float R() const;
	float G() const;
	float B() const;

	std::string DebugString() const;
	friend std::ostream& operator<<(std::ostream& os, const Color& c);

private:

};

Color operator*(const Color& lhs, const Color& rhs);



#endif // COLOR_H