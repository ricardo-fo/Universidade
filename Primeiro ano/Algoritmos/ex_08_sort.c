/* AUTOR: RICARDO DE FREITAS OLIVEIRA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS II - 2018
 8)Faça um programa para ler o arquivo gerado pela questão 6 e uma
 função que ordene o mesmo e grave em um arquivo binário chamado
 SortSelection.bin. Use o algoritmo Seleção. Grave o tempo de execução
 do processo em um arquivo texto timeSelection.txt
 */

#include <stdio.h>
#include <time.h>

#define MAX 100000

void swap(int *, int *);
void selection_sort(void);
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
	selection_sort();
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

void selection_sort()
{
	register int i, j, min_idx;
	for(i = 0; i < MAX - 1; i++){
		min_idx = i;
		for(j = i + 1; j < MAX; j++){
			if(vet[j] < vet[min_idx])
				min_idx = j;
		}
		swap(&vet[min_idx], &vet[i]);
	}
}

void grava(double duracao)
{
	FILE * pin;

	if((pin = fopen("SortSelection.bin", "wb")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'SortSelection.bin'!\n");
		return;
	}
	fwrite(vet, sizeof(int), MAX, pin);
	fclose(pin);

	if((pin = fopen("timeSelection.txt", "w")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'timeSelection.txt'!\n");
		return;
	}
	fprintf(pin, "Tempo de execucao: %lf\n", duracao);
	fclose(pin);
	printf("Arquivos criados com sucesso!\n");
}
