#include <stdio.h>
#include "retangulo.h"
#include "ponto.h"

void ret_init(retangulo * ret, int x, int y, int alt, int cmp)
{
	ret->pto.x = x;
	ret->pto.y = y;
	ret->alt = alt;
	ret->cmp = cmp;	
}

int ret_area(retangulo ret)
{
	return (ret.alt * ret.cmp);
}

bool ret_contains(retangulo ret, ponto pto)
{
	if((pto.x >= ret.pto.x) && (pto.x <= (ret.pto.x + ret.cmp)) && (pto.y <= ret.pto.y) && (pto.y >= (ret.pto.y - ret.alt)))
		return true;
	return false;
}
		
