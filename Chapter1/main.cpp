#include "Projectile.h"
#include "Enviornment.h"

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

	int i = 0;
	while (p.IsAirborne())
	{
		Tick(e, p);
		std::cout << "Iteration: " << i << std::endl;
		std::cout << p.m_position << std::endl;
		++i;
	}

	return 0;
}