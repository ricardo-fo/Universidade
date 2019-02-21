#include <math.h>
#include <stdbool.h>
#include "circulo.h"

void circ_init(circulo * c, int x, int y, double r)
{
	pto_init(&c->centro, x, y);
	c->raio = r;
}

double circ_area(circulo c)
{
	return (M_PI * pow(c.raio, 2));
}

bool circ_contains(circulo c, ponto p)
{
	return pto_distancia(c.centro, p) <= c.raio;
}
