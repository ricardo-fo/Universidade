#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
	int copas[14];
	int ouros[14];
	int paus[14];
	int espadas[14];
}cartas;

void Ordenar(cartas *);
void Mostrar(const cartas * );
void CriaAuto(cartas *);
void CriaManu(cartas *);
void Aleatorio(int *);
void Preenche(int *, int *);
int Verificar(int *);
void Adicionar(int *, const int *);
void PorNaipe(const int *);
void Selection(int *, int);
void Swap(int *, int *);

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
				CriaAuto(&baralho);
				break;
			case 2:
				CriaManu(&baralho);
				break;
			case 3:
				Ordenar(&baralho);
				break;
			case 4:
				Mostrar(&baralho);
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

void Ordenar(cartas * baralho)
{
	Selection(baralho->copas, 14);
	Selection(baralho->ouros, 14);
	Selection(baralho->paus, 14);
	Selection(baralho->espadas, 14);

	printf("\n>>> BARALHO ORDENADO COM SUCESSO <<<\n");
}

void Selection(int * carta, int max)
{
	register int i, j, min_idx;

	for(i = 0; i < max-1; ++i){
		min_idx = i;
		for(j = i+1; j < max; ++j){
			if(carta[j] > carta[min_idx]){
				min_idx = j;
			}
			Swap(&carta[min_idx], &carta[i]);
		}
	}
}

void Swap(int * one, int * two)
{
    int three = *one;
    *one = *two;
    *two = three;
}

void Mostrar(const cartas * baralho)
{
	register int i;
	char naipes[4][8] = {"Copas", "Ouros", "Paus", "Espadas"};

	printf("\nCopas:\n");
	PorNaipe(baralho->copas);
	printf("\nOuros:\n");
	PorNaipe(baralho->ouros);
	printf("\nPaus:\n");
	PorNaipe(baralho->paus);
	printf("\nEspadas:\n");
	PorNaipe(baralho->espadas);
}

void PorNaipe(const int * naipe)
{
	register int i;

	for(i = 0; i < 14; ++i){
		/*if(naipe[i] >= 10){
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
		}*/
		printf(" %d\n", naipe[i]);
	}
}

void CriaAuto(cartas * baralho)
{
	int vet[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

	Aleatorio(vet);
	Preenche(baralho->copas, vet);
	Aleatorio(vet);
	Preenche(baralho->ouros, vet);
	Aleatorio(vet);
	Preenche(baralho->paus, vet);
	Aleatorio(vet);
	Preenche(baralho->espadas, vet);
	printf("\n>>> BARALHO ALEATORIO CRIADO COM SUCESSO <<<\n");
}

void Aleatorio(int * vet)
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

void Preenche(int * naipes, int * vet)
{
	register int i;

	for(i = 0; i < 14; ++i){
		naipes[i] = vet[i];
	}
}

void CriaManu(cartas * baralho)
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
		if(Verificar(confimar)){
			switch(i){
				case 0:
					Adicionar(baralho->copas, confimar);
					break;
				case 1:
					Adicionar(baralho->ouros, confimar);
					break;
				case 2:
					Adicionar(baralho->paus, confimar);
					break;
				case 3:
					Adicionar(baralho->espadas, confimar);
					break;
			}
			continue;
		}
		fprintf(stderr, "Algo em suas cartas esta incorreto!\n");
		return;
	}
}

int Verificar(int * confimar)
{
	register int i;

	Selection(confimar, 14);
	for(i = 0; i < 14; ++i){
		printf("confirmar[%d](%d) != %d+1\n", i, confimar[i], i);
		if(confimar[i] != i+1)
			return 0;
	}
	return 1;

}

void Adicionar(int * naipe, const int * confimar)
{
	register int i;

	for(i = 0; i < 14; ++i){
		naipe[i] = confimar[i];
	}
}
