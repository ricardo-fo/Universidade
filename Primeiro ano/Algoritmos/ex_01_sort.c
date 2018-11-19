#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define MAX 10000

int busca(int, const int *, double *);
void quickSort(int arr[], int, int);
int partition (int arr[], int, int);
void printArray(int arr[], int);
void swap(int *, int *);

int main()
{
	//int vet[10000];
	time_t t;
	int num, vet[MAX], iteracao;
	register int i;
    double tempo;

    srand((unsigned)time(&t));
    do{
        printf("\nInforme o numero inteiro que deseja buscar(-1 para sair):\n>>> ");
        scanf("%d", &num);

        for(i = 0; i < MAX; ++i){
            vet[i] = rand() % 99999;
        }

        printf("Numero-Alvo: %d\n", num);
        printf("Busca nao ordenada======\n");
        printf("Posicao: %d\n", busca(num, vet, &tempo));
        printf("Total de Iteracoes: %d\n", busca(num, vet, &tempo));
        printf("Tempo de Execucao: %lf\n", tempo);

        int n = sizeof(vet)/sizeof(vet[0]);
        quickSort(vet, 0, n-1);
        printf("\nNumero-Alvo: %d\n", num);
        printf("Busca ordenada======\n");
        printf("Posicao: %d\n", busca(num, vet, &tempo));
        printf("Total de Iteracoes: %d\n", busca(num, vet, &tempo));
        printf("Tempo de Execucao: %lf\n", tempo);

    }while(num != -1);

	return 0;
}

int busca(int numero, const int * vetor, double * tempo)
{
	register int i;
	clock_t start;
	start = clock();

	for(i = 0; i < MAX; ++i){
		if(numero == vetor[i]){
            *tempo = (double) (clock() - start) / CLOCKS_PER_SEC;
            return i;
		}
	}
	*tempo = (double) (clock() - start) / CLOCKS_PER_SEC;
	return -1;
}

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d\n", arr[i]);
    printf("\n");
}
