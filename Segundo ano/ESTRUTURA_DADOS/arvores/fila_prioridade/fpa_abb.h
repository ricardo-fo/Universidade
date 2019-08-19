/*
 * fpa_ab.h
 * 
 * Definição do TAD fila de prioridade ascendente representada utilizando árvore binária de busca (FPAABB) e protótipos de suas operações.
 * 
 * Autor: Ricardo de F. Oliveira.
 * 
 * Data: 17/08/2019
*/

#ifndef _FPA_ABB_H
#define _FPA_ABB_H

typedef int tree_info;
typedef struct no_arvbin * arvbin;
struct no_arvbin {
    arvbin esq;
    tree_info dado;
    arvbin dir;
};

/* Inicializa a FPAABB */
void FPInit(arvbin *);

/* Insere um elemento na FPAABB */
void FPInserir(arvbin *, tree_info);

/* Remove o menor elemento da FPAABB */
tree_info FPRemoverMin(arvbin *);

#endif