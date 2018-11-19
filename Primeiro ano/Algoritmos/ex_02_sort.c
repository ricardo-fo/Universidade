#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int arr[], int, int);
int Particionar(int arr[], int, int);
void Troca(int *, int *);
void Inserir(int vet[], float);

int main()
{
	time_t t;
	int vet[100] = {0}, n = sizeof(vet)/sizeof(vet[0]);
	register int i, a = 20, b = 40, c = 60, d = 80;
	float num = 1;

	srand((unsigned)time(&t));

	for(i = 0; i < 100; ++i){
		vet[i] = (rand() % 999) + 1;
	}
	QuickSort(vet, 0, n-1);

	printf("Informe o numero inteiro a ser colocado na posicao correta: ");
    scanf("%f", &num);
	while((num < 0 || num > 999) || abs(num) < num && abs(num) + 1 > num){
        printf("\nOops! Numero fora do intervalo [0, 999]\nInforme outro numero: ");
        scanf("%f", &num);
	}
	Inserir(vet, num);
	i = 0;
	while(i < 20){
        printf("vet[%03d] = %03d\t\t", i, vet[i]);
        printf("vet[%03d] = %03d\t\t", a, vet[a]);
        printf("vet[%03d] = %03d\t\t", b, vet[b]);
        printf("vet[%03d] = %03d\t\t", c, vet[c]);
        printf("vet[%03d] = %03d\t\n", d, vet[d]);
        a++;
        b++;
        c++;
        d++;
        i++;
	}

	return 0;
}

void QuickSort(int arr[], int low, int high)
{
	if(low < high){
		int pi = Particionar(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int Particionar(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
       {
            i++;
            Troca(&arr[i], &arr[j]);
        }
    }
    Troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Troca(int * a, int * b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Inserir(int arr[], float num)
{
	register int i;

	for(i = 0; arr[i] < num; i++);
	arr[i] = num;
	printf("\nO numero %.0f foi inserido na posicao %d!\n\n", num, i);
}
