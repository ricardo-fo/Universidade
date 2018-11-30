/* AUTOR: RICARDO DE FREITAS OLIVEIRA
 * CURSO: CIÊNCIA DA COMPUTAÇÃO
 * ALGORITMOS II - 2018
 10)Faça um programa para ler o arquivo gerado pela questão 6 e
 uma função que ordene o mesmo e grave em um arquivo binário
 chamado SortInsertion.bin. Grave o tempo de execução do processo
 em um arquivo texto timeInsert.txt
 */

#include <stdio.h>
#include <time.h>

#define MAX 100000

void insertion_sort(void);
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
	insertion_sort();
	end = clock();
	cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
	grava(cpu_time);

	return 0;
}

void insertion_sort()
{
	register int i, j, key;

	for(i = 0; i < MAX - 1; i++){
		key = vet[i];
		j = i - 1;
		while(j >= 0 && vet[j] > key){
			vet[j + 1] = vet[j];
			j--;
		}
		vet[j+1] = key;
	}
}

void grava(double duracao)
{
	FILE * pin;

	if((pin = fopen("SortInsertion.bin", "wb")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'SortInsertion.bin'!\n");
		return;
	}
	fwrite(vet, sizeof(int), MAX, pin);
	fclose(pin);

	if((pin = fopen("timeInsert.txt", "w")) == NULL){
		fprintf(stderr, "Erro ao abrir o arquivo 'timeInsert.txt'!\n");
		return;
	}
	fprintf(pin, "Tempo de execucao: %lf\n", duracao);
	fclose(pin);
	printf("Arquivos criados com sucesso!\n");
}
