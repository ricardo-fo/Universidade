/* ponto.c
 * Implementa as operações que manipulam o TAD ponto*/

#include <math.h>
#include "ponto.h"

void pto_init(ponto * p, int x, int y)
{
	p->x = x;
	p->y = y;
}

