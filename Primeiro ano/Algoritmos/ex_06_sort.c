/*6)Tomando como base os arquivos EscritaVetoresBin.c e ordenação.c
disponíveis na pasta “Soluções--> Ordenação-->Lista Ordenação” no
Moodle, faça uma função para gerar um vetor aleatório de 100000
posições e gravar em um arquivo binário;*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void preenche(void);
int grava_bin(void);

int vet[MAX];

int main()
{
	time_t t;
	srand((unsigned)time(&t));
	preenche();
	fprintf(stdout, "%s!\n", grava_bin() == 1? "Problemas ao criar o arquivo" : "Arquivo criado com sucesso");

    return 0;
}

void preenche()
{
	register int i;

	for(i = 0; i < MAX; i++){
		vet[i] = rand() % MAX;
	}
}


int grava_bin()
{
	FILE * pin;
	char arquivo[] = "storage.dat";

	if((pin = fopen(arquivo, "wb")) == NULL){
		return 1;
	}
	fwrite(vet, sizeof(int), MAX, pin);
	fclose(pin);
	return 0;
}
