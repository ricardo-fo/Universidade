#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
	int copas[14];
	int ouros[14];
	int paus[14];
	int espadas[14];
}cartas;

void ordenar(cartas *);
void mostrar(const cartas * );
void criaAuto(cartas *);
void criaManu(cartas *);
void aleatorio(int *);
void preenche(int *, int *);
int verificar(int *);
void adicionar(int *, const int *);
void porNaipe(const int *);
void selection(int *, int);
void swap(int *, int *);
void insertion(int *, int);

int main()
{
	cartas baralho;
	float choice = 1;
	time_t t;

	srand((unsigned)time(&t));
	do{
		printf("\nEscolha uma das opcoes:\n--------------------------------------------------\n");
		printf("1 - Criar baralho automaticamente;\n");
		printf("2 - Criar baralho manualmente;\n");
		printf("3 - Ordenar baralho;\n");
		printf("4 - Mostrar baralho;\n");
		printf("0 - Sair.\n>>> ");
		scanf("%f", &choice);
		switch((int)(choice)){
			case 1:
				criaAuto(&baralho);
				break;
			case 2:
				criaManu(&baralho);
				break;
			case 3:
				ordenar(&baralho);
				break;
			case 4:
				mostrar(&baralho);
				break;
			case 0:
				printf("Adeus!\n");
				break;
			default:
				fprintf(stderr, "Oops! Valor invalido. Informe outro");
		}
	}while(choice != 0);

	return 0;
}

void ordenar(cartas * baralho)
{/*
	selection(baralho->copas, 14);
	selection(baralho->ouros, 14);
	selection(baralho->paus, 14);
	selection(baralho->espadas, 14);
*/
	insertion(baralho->copas, 14);
	insertion(baralho->ouros, 14);
	insertion(baralho->paus, 14);
	insertion(baralho->espadas, 14);
	printf("\n>>> BARALHO ORDENADO COM SUCESSO <<<\n");
}

void selection(int * carta, int max)
{
	register int i, j, min_idx;

	for(i = 0; i < max-1; ++i){
		min_idx = i;
		for(j = i+1; j < max; ++j){
			if(carta[j] > carta[min_idx]){
				min_idx = j;
			}
			swap(&carta[min_idx], &carta[i]);
		}
	}
}

void swap(int * one, int * two)
{
    int three = *one;
    *one = *two;
    *two = three;
}

void insertion(int * vet, int max)
{
	register int i, j, key;
	for(i = 1; i < max; i++){
		key = vet[i];
		j = i - 1;
		while(j >= 0 && vet[j] > key){
			vet[j+1] = vet[j];
			j = j - 1;
		}
		vet[j + 1] = key;
	}
}


void mostrar(const cartas * baralho)
{
	printf("\nCopas:\n");
	porNaipe(baralho->copas);
	printf("\nOuros:\n");
	porNaipe(baralho->ouros);
	printf("\nPaus:\n");
	porNaipe(baralho->paus);
	printf("\nEspadas:\n");
	porNaipe(baralho->espadas);
}

void porNaipe(const int * naipe)
{
	register int i;

	for(i = 0; i < 14; ++i){
		if(naipe[i] >= 10){
			switch(naipe[i]){
				case 10:
					printf("%d\n", naipe[i]);
					break;
				case 11:
					printf(" J\n");
					break;
				case 12:
					printf(" Q\n");
					break;
				case 13:
					printf(" K\n");
					break;
			}
			continue;
		}
		printf(" %d\n", naipe[i]);
	}
}

void criaAuto(cartas * baralho)
{
	int vet[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	aleatorio(vet);
	preenche(baralho->copas, vet);
	aleatorio(vet);
	preenche(baralho->ouros, vet);
	aleatorio(vet);
	preenche(baralho->paus, vet);
	aleatorio(vet);
	preenche(baralho->espadas, vet);
	printf("\n>>> BARALHO ALEATORIO CRIADO COM SUCESSO <<<\n");
}

void aleatorio(int * vet)
{
	register int i, j, rnd1, rnd2, aux;

	for(i = 0; i < 10; ++i){
		for(j = 0; j < 14; ++j){
			rnd1 = rand() % 14;
			rnd2 = rand() % 14;
			aux = vet[rnd1];
			vet[rnd1] = vet[rnd2];
			vet[rnd2] = aux;
		}
	}
}

void preenche(int * naipes, int * vet)
{
	register int i;

	for(i = 0; i < 14; ++i){
		naipes[i] = vet[i];
	}
}

void criaManu(cartas * baralho)
{
	int teste, confimar[14] = {0};
	register int i, j;
	char naipes[4][8] = {"Copas", "Ouros", "Paus", "Espadas"};

	for(i = 0; i < 4; ++i){
		printf("\nNaipe: %s\n", naipes[i]);
		int sum = 1;
		for(j = 0; j < 14; ++j){
			printf("Carta %02d: ", sum++);
			scanf("%d", &teste);
			confimar[j] = teste;
		}
		if(verificar(confimar)){
			switch(i){
				case 0:
					adicionar(baralho->copas, confimar);
					break;
				case 1:
					adicionar(baralho->ouros, confimar);
					break;
				case 2:
					adicionar(baralho->paus, confimar);
					break;
				case 3:
					adicionar(baralho->espadas, confimar);
					break;
			}
			continue;
		}
		fprintf(stderr, "Algo em suas cartas esta incorreto!\n");
		return;
	}
}

int verificar(int * confimar)
{
	register int i;

	insertion(confimar, 14);
	for(i = 0; i < 14; ++i){
		if(confimar[i] != i+1)
			return 0;
	}
	return 1;

}

void adicionar(int * naipe, const int * confimar)
{
	register int i;

	for(i = 0; i < 14; ++i){
		naipe[i] = confimar[i];
	}
}
