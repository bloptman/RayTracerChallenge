#include "RayTracerMath.h"
#include <cassert>

bool IsEqual(float a, float b, float tolerance)
{
	// Only tolerance values greater than zero make sense.
	assert(tolerance > 0);
	return abs(a - b) < tolerance;
}