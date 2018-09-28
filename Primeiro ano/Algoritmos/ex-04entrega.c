/*
Faça um programa que receba dois arquivos do usuário, e crie um terceiro
arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro
seguido do conteúdo do segundo).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000

void getExt(const char *, char *);/*Pega o formato da extensão do arquivo*/
void cpyFile(FILE *, FILE *);/*Faz a transferencia do conteúdo do arquivo para o novo arquivo*/
int cpyFileBin(FILE *, FILE *, int *);/*Faz a transferencia do conteúdo de um arquivo binário para o novo arquivo binário. Retorna a quantidade de números adicionados ao arquivo*/

int main()
{
	char file_one[301], file_two[301], ext_one[10], ext_two[10];

	printf("Nome do arquivo 01:\n>>> ");
	scanf(" %300[^\n]", file_one);
	getExt(file_one, ext_one);

	printf("\nNome do arquivo 02:\n>>> ");
	scanf(" %300[^\n]", file_two);
	getExt(file_two, ext_two);

	/*Faz a verificação para saber se é possível gerar um terceiro arquivo*/
	if(strcmp(ext_one, ext_two)){
		printf("Arquivos com extensoes diferentes. Impossivel criar um terceiro arquivo!\n");
		return 1;
	}else{
		FILE * pone, * ptwo;
		int storage[MAX] = {0}, lenght;
		char file_three[21] = "new";
		strcat(file_three, ext_one);/*Cria o nome do novo arquivo e a extensão dele*/

		if(!(strcmp(ext_one, ".bin"))){
			if((pone = fopen(file_one, "rb")) == NULL){
                printf("\nArquivo '%s' vazio ou inexistente!\nImpossivel fazer a gravacao!\n", file_one);
                return 2;
			}
			ptwo = fopen(file_three, "wb");
			lenght = cpyFileBin(pone, ptwo, storage);
			fclose(pone);
			if((pone = fopen(file_two, "rb")) == NULL){
                printf("\nArquivo '%s' vazio ou inexistente!\nImpossivel prosseguir com a gravacao!\n", file_two);
                return 2;
			}
			lenght = cpyFileBin(pone, ptwo, storage);
            fwrite(storage, sizeof(int), lenght, ptwo);/*gravação no arquivo*/
			fclose(pone);
			fclose(ptwo);
		}else{
            if((pone = fopen(file_one, "r")) == NULL){
                printf("\nArquivo '%s' vazio ou inexistente!\nImpossivel fazer a gravacao!\n", file_one);
                return 2;
            }
            ptwo = fopen(file_three,"w");
			cpyFile(pone, ptwo);
			fclose(pone);
			if((pone = fopen(file_two, "r")) == NULL){
                printf("\nArquivo '%s' vazio ou inexistente!\nImpossivel prosseguir com a gravacao!\n", file_two);
                return 2;
			}
			cpyFile(pone, ptwo);
			fclose(pone);
			fclose(ptwo);
		}
	}
    return 0;
}

void getExt(const char * file, char * ext)
{
	/*Obtém o último '.' do nome do arquivo, ou seja, o formato da extensão*/
	int i = strlen(file);
	while(file[i] != '.'){
		i--;
	}
	strcpy(ext, &file[i]);
}

void cpyFile(FILE * pone, FILE * ptwo)
{
	/*Armazena o conteúdo do arquivo passado numa string e grava essa string no novo arquivo*/
	char ch[MAX];
	while((fgets(ch, sizeof(ch), pone)) != NULL){
        fputs(ch, ptwo);
	}
}

int cpyFileBin(FILE * pone, FILE * ptwo, int * arm)
{
    static int i = 0;//i representa a quantidade de números adicionados no arquivo
	/*Grava o conteúdo dos arquivos para o novo arquivo*/
	fread(&arm[i], sizeof(int), MAX, pone);
	while(arm[i] != 0){
        i++;
    }
    return i;
}
/*
Nome: Ricardo de Freitas Olveira.
Curso: Ciência da Computação.
R.A.: 5934078.
Exe.: 04.
*/
