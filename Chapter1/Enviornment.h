#ifndef ENVIORNMENT_H
#define ENVIORNMENT_H

#include "Tuple.h"

struct Enviornment
{
	Enviornment(const Tuple& g, const Tuple& w) :m_gravity(g), m_wind(w) {};
	Tuple m_gravity;
	Tuple m_wind;
};

#endif // ENVIORNMENT_H