#include <stdio.h>
#include "lista.h"

int main()
{
	lista l;
	int k, op;
	lst_info val;

	do {
		printf("\n\nLISTA LINEAR\n");
		printf("<1> Inserir\n");
		printf("<2> Remover\n");
		printf("<3> Acessar\n");
		printf("<4> Inserir\n");
		printf("<0> Inserir\n");
		scanf("%d", &op);

		switch(op) {
			case 1:
				printf("\n\nInserir um novo nó\n");
				printf("Posição: ");
				scanf("%d", &k);
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_inserir(&l, k, val)) {
					printf("Inserção realizada com sucesso!\n");
				} else {
					printf("Erro: posição inválida ou lista cheia!\n");
				}
				break;
			case 2:
				printf("\n\nRemover um nó da lista\n");
				printf("Posição:");
				scanf("%d", &k);
				if(lst_remover(&l, k, &val)) {
					printf("%d removido com sucesso!\n", k);
				} else {
					printf("Erro: ao excluir o item!\n");				
				}
				break;
			case 3:
				printf("\n\nAcessar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				if(lst_acessar(l, k, &val)) {
					printf("Valor da posição %d: %d\n", k, val);
				} else {
					printf("Erro: posição inválida ou inexistente!\n");
				}
				break;
			case 4:
				printf("\n\nAlterar um nó da lista\n");
				printf("Posição: ");
				scanf("%d", &k);
				printf("Valor: ");
				scanf("%d", &val);
				if(lst_alterar(&l, k, val)) {
					printf("Item alterado com sucesso!\n");
				} else {
					printf("Erro: posição inválida ou inexistente!\n");
				}
				break;
			case 0:
				printf("\nAdeus!\n");
				break;
			default:
				fprintf(stderr, "\nTá errado isso ae mano\n");
		}
	} while(op != 0);
	return 0;
}
