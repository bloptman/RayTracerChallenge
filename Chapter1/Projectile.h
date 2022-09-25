#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Tuple.h"

struct Projectile
{
	Projectile(const Tuple& p, const Tuple& v) : m_position(p), m_velocity(v) {};
	bool IsAirborne() const { return m_position.Y() > 0; }
	Tuple m_position;
	Tuple m_velocity;
};

#endif // PROJECTILE_H