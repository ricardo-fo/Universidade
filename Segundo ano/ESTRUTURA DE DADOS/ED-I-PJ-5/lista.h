/* lista.h */

#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#define LST_MAX 100 // número de elementos do vetor
typedef int lst_info; // tipo de dado da lista
typedef struct {
	lst_info itens[LST_MAX]; // vetor p/ os nós da lista
	int n; // número de nós da lista
} lista;

/* função que inicializa a lista */
void lst_init(lista *);

/* função que acessa o k-ésimo nó da lista e sinaliza o
   sucesso ou falha da operação */
bool lst_acessar(lista, int, lst_info *);

/* função que altera o valor do k-ésimo nó da lista e
   sinaliza o sucesso ou falha da operação */
bool lst_alterar(lista *, int, lst_info);

/* função que insere um novo nó na k-ésima posição da
   lista e sinaliza o sucesso ou falha da operação */
bool lst_inserir(lista *, int, lst_info);   

/* função que remove o k-ésimo nó da lista e sinaliza
   o sucesso ou falha da operação */
bool lst_remover(lista *, int, lst_info *);

/* função que imprime todos os elementos de uma lista */ 
void lst_imprimir(lista);

/* função que procura um determinado elemento em uma lista */
int lst_procurar(lista, lst_info);

/* função que insere um elemento na lista de forma que ela 
   continue ordenada */
bool lst_ins_ordenado(lista *, lst_info);

/* função que ordena os elementos de uma lista linear */
void lst_ordenar(lista *);

/* função que insere um número no final da lista e devolve 
   verdadeiro para indicar o sucesso da operação, ou falso, 
   para indicar a falha (lista cheia) */
bool lst_inserir_final(lista *, lst_info);

/* função que insere um número no início da lista e devolve
   verdadeiro para indicar o sucesso da operação, ou falso,
   para indicar a falha (lista cheia) */
bool lst_inserir_inicio(lista *, lst_info);

/* função que remove o valor do final da lista, guarda seu
   valor em uma variável e devolve verdadeiro para indicar
   o sucesso da operação, ou falso, para indicar falha (lista
   cheia) */
bool lst_remover_final(lista *, lst_info *);

/* função que remove o valor do início da lista, guarda seu
   valor em uma variável e devolve verdadeiro para indicar
   o sucesso da operação, ou falso, para indicar falha (lista
   cheia) */
bool lst_remover_inicio(lista *, lst_info *);

/* função que gera aleatoriamente, usando rand(), o conteúdo
   da lista com n nós contendo valores entre 1 e max e devolve
   verdadeiro para indicar o sucesso da operação, ou falso, para
   indicar falha (n é maior que o tamanho do vetor). l[n] = {x E int 
   | 1 <= x <= max} */
bool lst_gerar(lista *, int, int);

/* função que devolve verdadeiro se a lista está em ordem crescente */
bool lst_ordenada(lista);

/* função que remove todos os nós de uma lista cujo valor for menor
   que uma variável e devolve o número de nós removidos */
int lst_remover_menores(lista *, lst_info);

#endif
