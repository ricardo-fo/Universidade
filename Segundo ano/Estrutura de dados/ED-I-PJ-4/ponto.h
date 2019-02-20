/* ponto.h
 * TAD para representar um ponot no R²*/

#ifndef _PONTO_H
#define _PONTO_H

/* Definição do tipo ponto*/
typedef struct {
	int x;
	int y;
} ponto;

/* Função pto_init
 * Inicializa as coordenadas x e y de um ponto*/

void pto_init(ponto *, int, int);

#endif

