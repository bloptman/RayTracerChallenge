#include "Tuple.h"
#include <iostream>

struct Projectile
{
	Tuple m_position;
	Tuple m_velocity;

	Projectile(Tuple p, Tuple v) : m_position(p), m_velocity(v) {};
};

struct Enviornment
{
	Tuple m_gravity;
	Tuple m_wind;

	Enviornment(Tuple g, Tuple w) : m_gravity(g), m_wind(w) {};
};

void Tick(Enviornment env, Projectile& proj)
{
	proj.m_position = proj.m_position + proj.m_velocity;
	proj.m_velocity = proj.m_velocity + env.m_gravity + env.m_wind;
}


int main()
{
	Tuple initalPosition = Point(0, 1, 0);
	Tuple initalVelocity = Vector(1, 1, 0).Normalize();

	Tuple gravity = Vector(0, -0.1, 0);
	Tuple wind = Vector(-0.01, 0, 0);

	Projectile p(initalPosition, initalVelocity);
	Enviornment e(gravity, wind);

	while (p.m_position.Y() > 0)
	{
		Tick(e, p);

		std::cout << "X: " << p.m_position.X() << std::endl;
		std::cout << "Y: " << p.m_position.Y() << std::endl;
		std::cout << "Z: " << p.m_position.Y() << std::endl;

		std::cout << std::endl;
	}

	return 0;
}