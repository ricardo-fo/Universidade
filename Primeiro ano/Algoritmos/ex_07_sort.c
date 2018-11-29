/*7)Faça um programa para ler o arquivo gerado pela questão 6 e uma
função que ordene o mesmo e grave em um arquivo binário chamado
QuickSort.bin. Use o algoritmo Quick Sort. Grave o tempo de execução
do processo em um arquivo texto timeQuick.txt*/

#include <stdio.h>
#include <time.h>

#define MAX 100000

int vet[MAX];

void quick_sort(int, int);
int partition(int, int);
void swap(int *, int *);
int novo_bin(void);

int main()
{
	FILE * p;
	register int i;
	clock_t start, end;
	double cpu_time;

	if((p = fopen("storage.dat", "rb")) == NULL){
		return 1;
	}
	fread(vet, sizeof(int), MAX, p);
	fclose(p);

	start = clock();
	quick_sort(0, sizeof(vet)/sizeof(vet[0]));
	end = clock();
	cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
	fprintf(stdout, "%s!\n", novo_bin() == 1? "Problemas ao criar o arquivo" : "Arquivo criado com sucesso");

	if((p = fopen("timeQuick.txt", "w")) == NULL){
		fprintf(stderr, "Erro ao criar o arquivo 'timeQuick.txt'!\n");
		return 1;
	}
	fprintf(p, "Tempo de execucao: %lf\n", cpu_time);
	fclose(p);

	return 0;
}

void quick_sort(int low, int high)
{
	if(low < high){
		int pi = partition(low, high);
		quick_sort(low, pi - 1);
		quick_sort(pi + 1, high);
	}
}

int partition(int low, int high)
{
	int pivot = vet[high];
	register int j, i = (low - 1);

	for (j = low; j <= high- 1; j++)
    {
        if (vet[j] <= pivot)
       {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[high]);
    return (i + 1);
}

void swap(int * one, int * two)
{
	int aux = *one;
	*one = *two;
	*two = aux;
}

int novo_bin()
{
	FILE * pin;
	char arquivo[] = "QuickSort.bin";

	if((pin = fopen(arquivo, "wb")) == NULL){
		return 1;
	}
	fwrite(vet, sizeof(int), MAX, pin);
	fclose(pin);
	return 0;
}
