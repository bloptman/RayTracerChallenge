#include "Projectile.h"
#include "Enviornment.h"
#include "Canvas.h"
#include "Color.h"

void Tick(Enviornment env, Projectile& proj)
{
	proj.m_position = proj.m_position + proj.m_velocity;
	proj.m_velocity = proj.m_velocity + env.m_gravity + env.m_wind;
}

unsigned int ConvertWorldToCanvas(const Canvas& c, float y)
{
	return c.Height() - y;
}

int main()
{
	Tuple initalPosition = Point(0, 1, 0);
	Tuple initalVelocity = Vector(1, 1.8, 0).Normalize() * 11.25;

	Tuple gravity = Vector(0, -0.1, 0);
	Tuple wind = Vector(-0.01, 0, 0);

	Projectile p(initalPosition, initalVelocity);
	Enviornment e(gravity, wind);

	int width = 900;
	int height = 500;

	Canvas c(width, height);

	// Some preset colors
	Color red(1, 0, 0);
	Color green(0, 1, 0);
	Color blue(0, 0, 1);

	int numColors = 3;
	Color colors[] = { red, green, blue };

	// Number of iterations for the loop
	int i = 0;

	// Keeping track of the x and y positions of the projectile
	// Note that the pixels on the Cavas must have integer values!
	int x = 0;
	int y = 0;

	while (p.IsAirborne())
	{
		Tick(e, p);

		x = p.m_position.X();
		y = ConvertWorldToCanvas(c, p.m_position.Y());

		c.WritePixel(x, y, colors[i % numColors]);

		std::cout << "Iteration: " << i << std::endl;
		std::cout << p.m_position << std::endl;
		++i;
	}

	Export(c, "Trajectory.ppm");

	return 0;
}