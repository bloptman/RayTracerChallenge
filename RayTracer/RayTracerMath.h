#ifndef RAY_TRACER_MATH_H
#define RAY_TRACER_MATH_H

#include <cmath>

// Default precision
const float EPSILON = 0.00001;

// Tests for equality between floating point numbers.
// Floating point numbers are considered equal so long as they are 
// within close enough to each other.
bool IsEqual(float a, float b, float tolerance = EPSILON);


#endif // RAY_TRACER_MATH_H