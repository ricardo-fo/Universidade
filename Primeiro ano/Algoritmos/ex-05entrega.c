/*
Faça um programa no qual o usuário informa o nome do arquivo, e uma palavra,
e retorne o número de vezes que aquela palavra aparece no arquivo
*/
#include <stdio.h>
#include <string.h>

int main()
{
	FILE * pin;
	char word[301], file[101];
	printf("Nome do arquivo:\n>>> ");
	scanf(" %100[^\n]", file);
	printf("Palavra:\n>>> ");
	scanf(" %300[^\n]", word);
	if((pin = fopen(file, "r")) == NULL){
		printf("Arquivo vazio!\n");
		return 1;
	}
	int cont = 0;
	char storage[1001];
	while(!(feof(pin))){
		fscanf(pin, "%s", storage);
		if(!strcmp(storage,word))
			cont++;
	}
	printf("%d\n", cont);
	return 0;
}
