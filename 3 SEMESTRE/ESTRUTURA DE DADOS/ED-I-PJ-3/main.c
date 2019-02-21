#include <stdio.h>
#include "ponto.h"
#include "my_io.h"
#include "circulo.h"

int main()
{
	int x1, x2, y1, y2;
	ponto p1, p2;

	printf("Informe um ponto de coordenadas x e y:\nx1 >>> ");
	while(!read_int(&x1)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}
	printf("y1 >>> ");
	while(!read_int(&y1)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}

	printf("\nInforme um ponto de coordenadas x e y novamente:\nx2 >>> ");
	while(!read_int(&x2)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}
	printf("y2 >>> ");
	while(!read_int(&y2)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}
	

	pto_init(&p1, x1, y1);
	pto_init(&p2, x2, y2);

	printf("Distancia entre o ponto A(%d, %d) e B(%d, %d) = %.4lf\n", x1, y1, x2, y2, pto_distancia(p1, p2));	
		
	/*Informações sobre o círculo*/
	circulo c;
	ponto p3;
	int x3, y3, x, y;
	double raio;

	printf("\nx3 >>> ");
	while(!read_int(&x3)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}

	printf("y3 >>> ");
	while(!read_int(&y3)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}

	pto_init(&p3, x3, y3);

	printf("\nXc >>> ");
	while(!read_int(&x)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}

	printf("\nyc >>> ");
	while(!read_int(&y)) {
		printf("Valor invalido. Numeros inteiros!\n>>>");
	}
	printf("\nraio >>> ");
	while(!read_double(&raio)) {
		printf("Valor invalido. Numeros double!\n>>>");
	}

	circ_init(&c, x, y, raio);

	printf("\nArea do circulo: %.4lf\n", circ_area(c));

	//printf("O ponto esta' dentro do circulo? (1 = sim, 0 = nao): %d\n", circ_contains(c, p3));

	return 0;
}
