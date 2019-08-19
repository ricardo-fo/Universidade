/*
 * fpa_ab.c
 * 
 * Implementação das operações da TAD FPAAB.
 * 
 * Autor: Ricardo de F. Oliveira.
 * 
 * Data: 17/08/2019
*/

#include "fpa_abb.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa a FPAABB */
void FPInit(arvbin * t){
    *t = NULL;
}

/* Insere um elemento na FPAABB */
void FPInserir(arvbin * t, tree_info valor){
    if(*t == NULL) {
        if((*t = (arvbin) malloc(sizeof(struct no_arvbin))) == NULL) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            exit(1);
        }
        (*t)->dado = valor;
        (*t)->esq = (*t)->dir = NULL;
    }
    else
        if (valor < (*t)->dado) FPInserir(&(*t)->esq, valor);
        else FPInserir(&(*t)->dir, valor);
}

/* Remove o menor elemento da FPAABB */
tree_info FPRemoverMin(arvbin * t){
    if(*t != NULL){
        if((*t)->esq == NULL) {
            return (*t)->dado;
        } else {
            int valor = FPRemoverMin(&(*t)->esq);
            free(*t);
            return valor;
        }
    }
}