/* 
Faça um programa que receba dois arquivos do usuário, e crie um terceiro
arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro
seguido do conteúdo do segundo).
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getExt(const char *, char *);/*Pega o formato da extensão do arquivo*/
void cpyFile(FILE *, FILE *);/*Faz a transferencia do conteúdo do arquivo para o novo arquivo*/
void cpyFileBin(FILE *, FILE *);/*Faz a transferencia do conteúdo de um arquivo binário para o novo arquivo binário*/

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
		char file_three[21] = "new";
		strcat(file_three, ext_one);/*Cria o nome do novo arquivo e a extensão dele*/

		if(!(strcmp(ext_one, ".bin"))){
			if((pone = fopen(file_one, "rb")) == NULL){
                printf("Arquivo '%s' vazio ou inexistente!\nImpossivel fazer a gravacao!\n", file_one);
                return 2;
			}
			ptwo = fopen(file_three, "wb");
			cpyFileBin(pone, ptwo);
			fclose(pone);
			if((pone = fopen(file_two, "rb")) == NULL){
                		printf("Arquivo '%s' vazio ou inexistente!\nImpossivel prosseguir com a gravacao!\n", file_two);
                		return 2;
			}
			cpyFileBin(pone, ptwo);
			fclose(pone);
			fclose(ptwo);
			}else{
            			if((pone = fopen(file_one, "r")) == NULL){
                			printf("Arquivo '%s' vazio ou inexistente!\nImpossivel fazer a gravacao!\n", file_one);
                			return 2;
           			}
            			ptwo = fopen(file_three,"w");
				cpyFile(pone, ptwo);
				fclose(pone);
				if((pone = fopen(file_two, "r")) == NULL){
                			printf("Arquivo '%s' vazio ou inexistente!\nImpossivel prosseguir com a gravacao!\n", file_two);
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
	/*Armazena o conteúdo do arquivo passado em uma string e grava essa string no novo arquivo*/
	char ch[1000000];
	while(!feof(pone)){
        fgets(ch, sizeof(ch), pone);
        fputs(ch, ptwo);
	}
}

void cpyFileBin(FILE * pone, FILE * ptwo)
{
    /*Calcula o tamanho do arquivo binário em bytes*/
	long len;
	fseek(pone, 0, SEEK_END);
	len = ftell(pone);
	int v[len/2];
	/*Grava o conteúdo dos arquivos para o novo arquivo*/
	fread(v, sizeof(int), len / 2, pone);
	fwrite(v, sizeof(int), len / 2, ptwo);
}
/*
Nome: Ricardo de Freitas Olveira.
Curso: Ciência da Computação.
R.A.: 5934078.
Exe.: 04.
*/
