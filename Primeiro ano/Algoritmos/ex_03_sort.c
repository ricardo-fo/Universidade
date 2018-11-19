#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int arr[], int, int);
int Particionar(int arr[], int, int);
void Troca(int *, int *);
void Inserir(int vet[], float);
void insercao (int, int *);

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
    insercao(n, vet);
    printf("Insercao em ordem decrescente:\n");
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


void insercao (int n, int v[]) 
{
	register int i, j, x;
	for (j = 1; j < n; ++j) {
		x = v[j];
		for (i = j-1; i >= 0 && v[i] < x; --i){
            v[i+1] = v[i];
		}
		v[i+1] = x;
	}
}
