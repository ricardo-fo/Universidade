#include <stdio.h>
#include "my_math.h"
#include "my_io.h"

int main()
{
	int inteiro;
	double decimal;
	
	printf("Informe um numero natural:\n>>>");
	while(!read_int(&inteiro) || inteiro < 0) {
		printf("Valor invalido. Apenas maior que zero!\n>>>");
	}

	printf("Informe um numero decimal:\n>>>");
	while(!read_double(&decimal)) {
		printf("Valor invalido. Apenas maior ou igual a zero!\n>>>");
	}

	printf("Fatorial de %d: %Ld\n", inteiro, fatorial(inteiro));
	printf("Arredondamento de %lf: %d\n", decimal, arredondarParaInt(decimal));
	
}
