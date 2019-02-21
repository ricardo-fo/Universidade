/* lista.h*/

#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#define LST_MAX 100 // número máximo de itens da lista
typedef int lst_info; // tipo de dado aceito na lista
typedef struct { // declaração da lista
	lst_info itens[LST_MAX]; // itens da lista
	int n; // tamanho da lista
} lista;

/* Função list_init: inicia uma lista*/
void lst_init(lista *);

/* Função lst_acessar: acessa o k-ésimo nó da lista e sinaliza o
 * sucesso ou falha da operação*/
bool lst_acessar(lista, int, lst_info *);

/* Função lst_alterar: altera o valor do k-ésimo nó da lista e 
 * sinaliza o sucesso ou falha da operação*/
bool lst_alterar(lista *, int, lst_info);

/* Função lst_inserir: insere um novo nó na k-ésima posição da lista 
 * sinaliza o sucesso ou falha da operação*/
bool lst_inserir(lista *, int, lst_info);

/* Função lst_remover: remove o k-ésimo nó da lista e sinaliza
 * o sucesso ou falha da operação*/
bool lst_remover(lista *, int, lst_info *);

#endif

