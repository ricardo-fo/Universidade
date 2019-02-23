#include "lista.h"
#include <stdio.h>

int main()
{
	lista l;
	int k, op;
	lst_info val;
	
	lst_init(&l);	
	do {
		printf("\n\nLISTA LINEAR\n");
		printf("<1> Inserir\n");
		printf("<2> Remover\n");
		printf("<3> Acessar\n");
		printf("<4> Alterar\n");
		printf("<5> Mostrar tudo\n");
		printf("<6> Buscar\n");
		printf("<7> Inserir com ordenação\n");
		printf("<8> Inserir final\n");
		printf("<9> Inserir início\n");
		printf("<10> Remover final\n");
		printf("<11> Remover início\n");
		printf("<12> Gerar lista\n");
		printf("<13> Ordenada?\n");
		printf("<14> Remover menores\n");
		printf("<0> Sair\n");
		printf("Opção: ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("\n\nInserir um novo nó\n");
				printf("Posição: ");
				scanf("%d", &k);
				printf("Valor: ");
				scanf("%d", &val);
				if (lst_inserir(&l, k, val)) {
					printf("Inserção realizada com sucesso!\n");
				}
				else {
					printf("Erro: posição inválida ou lista cheia!\n");
				}
				break;
			case 2:
				printf("\n\nRemover um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				if (lst_remover(&l, k, &val)) {
					printf("%d removido da lista\n", val);
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 3:
				printf("\n\nAcessar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				if (lst_acessar(l, k, &val)) {
					printf("Valor da posição %d = %d\n", k, val);
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 4:
				printf("\n\nAlterar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				printf("Valor: ");
				scanf("%d", &val);
				if (lst_alterar(&l, k, val)) {
					printf("Alteração realizada com sucesso!\n");
				}
				else {
					printf("Erro: posição inválida ou lista vazia!\n");
				}
				break;
			case 5:
				lst_imprimir(l);
				break;
			case 6:
				printf("Valor: ");
				scanf("%d", &val);
				if((k = lst_procurar(l, val)) != -1){
					printf("\nElemento encontrado!\nPosição: %d\nValor: %d\n", k, val);
					break;
				} else {
					printf("\nElemento não encontrado!\n");
				}
				break;
			case 7:
				printf("Valor: ");
				scanf("%d", &val);
				if((k = lst_ins_ordenado(&l, val))){
					printf("\nElemento inserido com sucesso!\n");
				} else {
					printf("\nErro: elemento não inserido!\n");
				}
				break;
			case 8:
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_inserir_final(&l, val)) {
					printf("Elemento inserido com sucesso!\n");
				} else {
					printf("\nErro: elemento não inserido!\n");
				}
				break;
			case 9:
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_inserir_inicio(&l, val)) {
					printf("Elemento inserido com sucesso!\n");
				} else {
					printf("\nErro: elemento não inserido!\n");	
				}
				break;
			case 10:
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_remover_final(&l, &val)){
					printf("Último elemento removido com sucesso!\n");
				} else {
					printf("Falha ao remover último elemento!\n");
				}	
				break;
			case 11:
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_remover_inicio(&l, &val)){
					printf("Primeiro elemento removido com sucesso!\n");
				} else {
					printf("Falha ao remover primeiro elemento!\n");
				}
				break;
			case 12:
				printf("Quantidade de nós: ");
				scanf("%d", &k);
				printf("Valor máximo: ");
				scanf("%d", &val);
				if(lst_gerar(&l, k, val)){
					printf("Lista gerada com sucesso!\n");
				} else {
					printf("Falha ao gerar a lista!\n");
				}
				break;
			case 13:
				if(lst_ordenada(l)) {
					printf("A lista está ordenada!\n");
				} else {
					printf("A lista não está ordenada!\n");
				}
				break;
			case 14:
				printf("Valor: ");
				scanf("%d", &val);
				printf("Itens removidos: %d\n", lst_remover_menores(&l, val));
				break;
			case 0:
				break;
			default:
				printf("\nErro: opção inválida!\n");
				break;
		}		
	} while (op != 0);
	
	return 0;
}
