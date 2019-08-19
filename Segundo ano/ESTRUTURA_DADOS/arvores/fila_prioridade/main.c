/*
 * main.c
 * 
 * Programa para testes do TAD FPAAB. Este programa permite criar um árvore binária representando uma fila de prioridade
 * ascendente, inserir e remover elementos da mesma.
 * 
 * Autor: Ricardo de F. Oliveira.
 * 
 * Data: 17/08/2019
*/

#include <stdio.h>
#include "fpa_abb.h"

int main(){
    arvbin t;
    tree_info valor;
    int op;

    FPInit(&t);

    do{
        printf("\n\t<0> Sair\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover menor valor\n");
        printf(">>> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nValor: ");
                scanf("%d", &valor);
                FPInserir(&t, valor);
                break;
            case 2:
                printf("\nValor removido: %d\n", FPRemoverMin(&t));
            case 0:
                break;
            default:
                fprintf(stderr, "\nInforme apenas opcoes validas!\n");
        }
    } while(op != 0);
}