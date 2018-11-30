/* AUTOR: RICARDO DE FREITAS OLIVEIRA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS II - 2018
 9)Faça um programa para ler o arquivo gerado pela questão 6 e
 uma função que ordene o mesmo e grave em um arquivo binário
 chamado BubbleSort.bin. Grave o tempo de execução do processo
 em um arquivo texto timeBubble.txt */

#include <stdio.h>
#include <time.h>

#define MAX 100000

void swap(int *, int *);
void bubble_sort(void);
void grava(double);

int vet[MAX];

int main()
{
	FILE * pout;
	clock_t start, end;
	double cpu_time;

	if((pout = fopen("storage.dat", "wb")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'storage.dat'!\n");
		return 1;
	}
	fread(vet, sizeof(int), MAX, pout);
	fclose(pout);
	start = clock();
	bubble_sort();
	end = clock();
	cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
	grava(cpu_time);

	return 0;
}

void swap(int * a, int * b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void bubble_sort()
{
	register int i, j, min_idx;
	for(i = 0; i < MAX - 1; i++){
		for(j = 0; j < MAX - i - 1; j++){
			if(vet[j] > vet[j+1])
				swap(&vet[j], &vet[j+1]);
		}
	}
}

void grava(double duracao)
{
	FILE * pin;

	if((pin = fopen("BubbleSort.bin", "wb")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'BubbleSort.bin'!\n");
		return;
	}
	fwrite(vet, sizeof(int), MAX, pin);
	fclose(pin);

	if((pin = fopen("timeBubble.txt", "w")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'timeBubble.txt'!\n");
		return;
	}
	fprintf(pin, "Tempo de execucao: %lf\n", duracao);
	fclose(pin);
	printf("Arquivos criados com sucesso!\n");
}
