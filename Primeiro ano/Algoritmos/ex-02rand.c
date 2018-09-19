/*
2)Crie uma função que recebe uma string e transforma alguns dos caracteres
em maiúsculos e outros em minúsculos. Faça sorteios com a função rand()
para gerar números aleatórios em C, que serão usados para escolher os
índices dos caracteres que serão alterados. Como parâmetro deve ser
recebida a quantidade de sorteios que devem ser executados.

void transforma(char [], int qtde_sorteios);
------------------------------------------------------------------------
A FUNÇÃO USADA CONSIDERA O ESPAÇO EM BRANCO COMO CARACTERE.O EXERCÍCIO PEDE
A TRANSFORMAÇÃO DE CARACTERES, SEM LIMITAR A APENAS ÀS LETRAS DO ALFABETO.
ELA, TAMBÉM, PODE SORTEAR O MESMO NÚMEROS n VEZES.
*/

//BIBLIOTECAS E OS SEUS PORQUÊS
#include <stdio.h>    /*padrão*/
#include <string.h>   /*strcpy(); e strlen();*/
#include <stdlib.h>   /*rand(); e srand();*/
#include <ctype.h>    /*tolower(); e toupper();*/
#include <time.h>     /*rand(); e srand();*/

void transforma(char * func_str, int fun_lucky);//PROTÓTIPO DA FUNÇÃO

int main()
{
	char str[1001];
	int lucky;

	printf("string >>> ");
	scanf(" %1000[^\n]", str);
	printf("sorteio >>> ");
	scanf("%d", &lucky);

	transforma(str, lucky);
	printf("\n%s\n", str);

	return 0;
}

void transforma(char * func_str, int func_lucky)
{
	/*
	:A FUNÇÃO USA UMA STRING AUXILIAR PARA SER MANIPULADA AO INVÉS DA ORIGINAL.
	:SÃO GERADOS NÚMEROS ALEATÓRIOS POR srand(); E ESSE VALOR GERADO É LIMITADO
	PARA QUE SEJA APLICADO À STRING AUXILIAR, OU SEJA, FICA NO INTERVALOR DE 0
	E O TAMANHO MÁXIMO DA STRING. ESSE VALOR QUE É LIMITADO VIRA, ENTÃO, O ÍNDICE
	DO CARACTERE QUE SERÁ ALTERADO.
	:PARA DECIDIR SE UMA LETRA FICA MINÚSCULA OU MAIÚSCULA É FEITA UMA ANÁLISE,
	APÓS ISSO O "case sensitive" É ALTERADO PARA O OPOSTO.
	*/
	int i, random, lenght = strlen(func_str);
	char copy_str[lenght];

	strcpy(copy_str, func_str);//STRING AUXILIAR
	srand( (unsigned)time(NULL) );//GERA OS NÚMEROS ALEATÓRIOS

	for(i = 0; i < func_lucky; i++){
		random  = rand() % lenght;//LIMITA O ALCANCE DOS NÚMEROS
		//printf("INDICE DO CARACTERE SORTEADO: %d\n", random);//MOSTRA OS NÚMEROS SORTEADOS
		if(copy_str[random] >= 'a' && copy_str[random] <= 'z')
			copy_str[random] = toupper(func_str[random]);
		else
			copy_str[random] = tolower(func_str[random]);
	}
	//printf("\n%s\n", copy_str);
	strcpy(func_str, copy_str);
}
/*
    NOME: RICARDO DE FREITAS OLIVERIA.
    R.A.: 5934078.
    CURSO: CIÊNCIA DA COMPUTAÇÃO.
*/
