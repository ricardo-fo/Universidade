#include <stdio.h>
#include <math.h>

long long fatorial(int numero)
{
	register int i;
	long long aux = 1;

	for(i = numero; i > 0; i--){
		aux *= i;
	}
	
	return aux;
}

int arredondarParaInt(double numero)
{
	//return round(numero);
	return (int) floor(numero + 0.5);
}
