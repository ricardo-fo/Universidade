/* retangulo.h
 * TAD para representar um retangulo*/

#ifndef _RETANGULO_H
#define _RETANGULO_H

#include <stdbool.h>
#include "ponto.h"
/* Definição do tipo retangulo*/
typedef struct {
	ponto pto;
	int alt;
	int cmp;	
} retangulo;

/* Função que inicializa as coordenadas do ponto que representa o vértice superior esquerdo do retângulo e sua altura e comprimento;*/
void ret_init(retangulo *, int, int, int, int);

/* Função que devolve a área do retângulo*/
int ret_area(retangulo);

/* Função que verifica se um ponto está dentro de um retângulo*/
bool ret_contains(retangulo, ponto);

#endif

