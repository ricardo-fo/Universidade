/* circulo.h
 * TAD para representar um circulo */ 

#ifndef _CIRCULO_H
#define _CIRCULO_H

/*Incluir o tipo ponto*/
#include "ponto.h"

/* Definição do tipo circulo */
typedef struct {
	ponto centro;
	double raio;
} circulo;

/* Função circ_init
 * Operação que inicializa um círculo c com centro no ponto x,y e raio r*/
void circ_init(circulo *, int, int, double);

/* Função circ_area
 * Operação que calcula e devolve a área do círculo c (πR²)*/
double circ_area(circulo c);

/* Função circ_contains
 * Operação que verifica se um ponto p está dentro do círculo c (a distância do ponto ao centro do círculo é menor ou igual a seu raio)*/
bool circ_contains(circulo c, ponto p)
#endif

