/*
Faça um programa com uma função void criar(void) que crie uma matriz 2 x 2
de inteiros e armazene em um arquivo binário chamado matriz.dat. A função
deve ainda receber uma senha de no mínimo 6 caracteres e no máximo 8 que
deve ser guardada em um arquivo binário chamado pwd.bin.

O programa deve ter ainda uma função void girar(void) para recuperar a
matriz e girar a mesma no sentido horário. Contudo a matriz só pode ser
girada se a senha for idêntica à guardada no arquivo pwd.bin.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void criar(void);
void girar(void);

int main()
{
    criar();
    girar();
	return 0;
}

void criar()
{
	FILE * pin;
	int matrix[2][2], i, j;
	char password[9], ch;

	pin = fopen("matriz.dat", "wb");
	srand((unsigned)time(NULL));/*preenchendo a matriz 2x2*/
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			matrix[i][j] = rand() % 101;
		}
	}
	fwrite(matrix, sizeof(int), 4, pin);
	fclose(pin);

	pin = fopen("pwd.bin", "wb");
	printf("Senha:\n>>> ");
	scanf(" %8[^\n]", password);
	while(ch = getchar() != '\n');//Limpeza do buffer do teclado
	while(strlen(password) < 6 || strlen(password) > 8){//Limitação do tamanho da senha
        printf("\nA senha deve ter entre 6 e 8 caracteres!\nPassword:\n>>> ");
		scanf(" %8[^\n]", password);
	}
	fwrite(password, sizeof(char), 9, pin);
	fclose(pin);
}

void girar()
{
	FILE * pout;
	int matrix[2][2], i, j;

	if((pout = fopen("matriz.dat", "rb")) == NULL){
		printf("\nProblemas ao abrir o arquivo 'matriz.dat'\n");
		exit(1);
	}
	fread(matrix, sizeof(int), 4, pout);
	fclose(pout);
	system("cls");
	printf("MATRIZ GERADA ALEATORIAMENTE:\n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	if((pout = fopen("pwd.bin","rb")) == NULL){
		printf("\nProblemas ao abrir o arquivo 'pwd.bin'\n");
		exit(1);
	}
	char password[9];
	fread(password, sizeof(char), 9, pout);
    fclose(pout);

	char acess[9], ch;
	printf("\nInforme a senha:\n>>> ");
	scanf(" %8[^\n]", acess);
	while(ch = getchar() != '\n');//Limpeza do buffer do teclado
	/*COMO O EXERCÍCIO NÃO ESPECIFICA QUANTOS GRAUS A MATRIZ DEVE SER GIRADA, ASSUMO O VALOR DE 90°
		| A  B | > | D  A |
		| D  C | > | C  B |
	Rotação:*/
	//printf("password = %s\nacess = %s\n", password, acess);
	if(!strcmp(password, acess)){
		i = matrix[0][1]; // aux = B
		matrix[0][1] = matrix[0][0]; // (0,1) = A
		j = matrix[1][1]; // auxx = C
		matrix[1][1] = i; // (1,1) = B
		i = matrix[1][0]; // aux = D
		matrix[1][0] = j; // (1,0) = C
		matrix[0][0] = i; // (0,0) = D
		printf("\nMATRIZ ROTACIONADA 90 graus:\n");
		for(i = 0; i < 2; i++){
			for(j = 0; j < 2; j++){
				printf("%d\t", matrix[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	printf("Senhas incompativeis!\n");
	exit(1);
}
/*
Nome: Ricardo de Freitas Olveira.
Curso: Ciência da Computação.
R.A.: 5934078.
Exe.: 06.
*/
