#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char nome[101];
	int numero;
	float nota;
} data;

void Auto(data *, int);
void Selection(data *, int);
void Swap(float *, float *);

int main()
{
	register int i;
	float n = 1;
	time_t t;

	printf("Informe a quantidade de alunos: ");
	scanf("%f", &n);
	while(abs(n) < n && (abs(n)+1) > n){
		fprintf(stderr, "\n\aValor invalido!\nInforme a quantidade de alunos: ");
		scanf("%f", &n);
	}

	data alunos[(int)(n)];
	char nome[101];
	float numero = 0, nota = 0;

	srand((unsigned)time(&t));
	Auto(alunos, (int)(n));
	Selection(alunos, (int)(n));
	/*
	for(i = 0; i < n; ++i){
		printf("\nNome [%d]: ", i+1);
		scanf(" %100[^\n]", nome);
		printf("Numero [%d]: ", i+1);
		scanf("%f", &numero);
		while(abs(numero) < numero && (abs(numero)+1) > numero){
			fprintf(stderr, "\n\aValor invalido!\nNumero [%d]: ", i+1);
			scanf("%f", &numero);
		}
		printf("Nota [%d]: ", i+1);
		scanf("%f", &nota);

		strcpy(alunos[i].nome, nome);
		alunos[i].numero = numero;
		alunos[i].nota = nota;
	}*/
	for(i = 0; i < n; ++i){
		printf("\nNome:\t%s", alunos[i].nome);
		printf("\nNumero:\t%d", alunos[i].numero);
		printf("\nNota:\t%.2f\n", alunos[i].nota);
	}

	return 0;
}

void Auto(data * alunos, int max)
{
	char nomes[10][31] = {"Ana", "Bia", "Carlos", "Daniel", "Fabiana", "Gabriela", "Heitor", "Igor", "Jair", "Karla"};
	char sobrenomes[10][21] = {" Pereira", " da Silva", " Oliveira", " da Luz", " Laranjeira", " Souza", " Santos", " Rocha", " Tomaz", " Garcia"};
	char ultimos[10][21] = {" Gouveia", " Macedo", " Trindade", " di Pinto", " Abrantes", " Mascarenhas", " Silveira", " de Freitas", " D'Avila", " Gomes"};
	register int i;

	for(i = 0; i < max; ++i){
		strcpy(alunos[i].nome, nomes[rand()%10]);
		strcat(alunos[i].nome, ((rand()%3)+1 % 2 == 0)? sobrenomes[rand()%10] : ultimos[rand()%10]);
		strcat(alunos[i].nome, ((rand()%3)+1 % 2 == 0)? ultimos[rand()%10] : sobrenomes[rand()%10]);
		alunos[i].numero = i+1;
		alunos[i].nota = (((rand()%10)-1.15) / 1.0125) + 2.05;
	}
}

void Selection(data * alunos, int max)
{
	register int i, j, min_idx;

	for(i = 0; i < max-1; ++i){
		min_idx = i;
		for(j = i+1; j < max; ++j){
			if(alunos[j].nota < alunos[min_idx].nota){
				min_idx = j;
			}
			Swap(&alunos[min_idx].nota, &alunos[i].nota);
		}
	}
}

void Swap(float * one, float * two)
{
    float three = *one;
    *one = *two;
    *two = three;
}
