#include <stdio.h>
#include "my_io.h"
#include "retangulo.h"
#include "ponto.h"

int main()
{
	int x, y, alt, cmp;
	
	printf("--- Dados do retangulo ---\n");
	printf("Insira coordenadas de um ponto:\nx >>> ");
	while (!read_int(&x)) {
		printf("Você não informou um número inteiro!\nx >>> ");		
	}
	printf("y >>> ");
	while (!read_int(&y)) {
		printf("Você não informou um número inteiro!\ny >>> ");
	}

	printf("Altura >>> ");
	while(!read_int(&alt)) {
		printf("Você não informou um número inteiro!\naltura >>> ");
	}

	printf("Comprimento >>> ");
	while(!read_int(&cmp)) {
		printf("Você não informou um número inteiro!\n comprimento >>> ");
	}

	retangulo ret;
	ret_init(&ret, x, y, alt, cmp);

	printf("\nÁrea do retângulo: %d u.a.(Unidades de Área)\n", ret_area(ret));

	printf("\nInforme um ponto e saiba se ele está dentro do retângulo:\nx >>> ");
	while (!read_int(&x)) {
		printf("Você não informou um número inteiro!\nx >>> ");
	}
	printf("y >>> ");
	while (!read_int(&y)) {
		printf("Você não informou um número inteiro!\ny >>> ");
	}

	ponto pto;
	pto_init(&pto, x, y);

	if(ret_contains(ret, pto)) {
		printf("Seu ponto está dentro do retângulo!\n");
	} else {
		printf("Seu ponto não está dentro do retângulo!\n");
	}

	return 0;
}

