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
		printf("Arquivo vazio ou inexistente!\n");
		return 1;
	}
	int cont = 0, i;
	char ch[10001];

	while(!feof(pin)){
        fscanf(pin, "%s", ch);
        for(i = 0; ch[i] != '\0'; i++){
            if(!strncmp(&ch[i], word, strlen(word)))
                cont++;
        }
	}
    fclose(pin);
	printf("Ocorrencia da palavra no arquivo: %d\n", cont);
	return 0;
}
/*
Nome: Ricardo de Freitas Olveira.
Curso: Ciência da Computação.
R.A.: 5934078.
Exe.: 05.
*/
