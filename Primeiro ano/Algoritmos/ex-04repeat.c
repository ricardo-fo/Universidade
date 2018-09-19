/*
4)Crie uma função que retira todas os caracteres repetidos de uma string.
*/

//BIBLIOTECAS E OS SEUS PORQUÊS
#include <stdio.h>	    //padrão
#include <string.h>		//strlen(); e strcpy();
#include <ctype.h>		//tolower();

void repeat(char * str);//PROTÓTIPO DA FUNÇÃO

int main()
{
	char str[1001];
	int i;

	printf("string >>> ");
	scanf(" %1000[^\n]", str);
	for(i = 0; str[i] != '\0'; i++){//CONVERTE A STRING PARA MINÚSCULO
		str[i] = tolower(str[i]);
	}
	repeat(str);
	printf("\n%s\n", str);

	return 0;
}

void repeat(char * func_str)
{
	/*
	A FUNÇÃO RECEBE COMO ARGUMENTO 1 STRING E IMPRIME ESSA STRING SEM CARACTERES
	REPETIDOS.
	FUNCIONAMENTO: A STRING É COMPARADA COM UMA STRING AUXILIAR, ESTA ARMAZENA
	OS CARACTERES NÃO REPETIDOS. COMO O PRIMEIRO CARACTERE NÃO ESTÁ NA AUXILIAR,
	ENTÃO A AUXILIAR RECEBE COMO ÍNDICE 0 O CARACTERE DE ÍNDICE 0 DA STRING.
	A STRING É VARRIDA E CADA CARACTERE DELA É VERIFICADO SE ELE JÁ ESTÁ NA
	AUXILIAR, CASO ESTEJA, break; É CHAMADO PARA QUE O PRÓXIMO CARACTERE DA STRING
	SEJA ANALISADO. CASO NÃO ESTEJA, O CARACTERE É ADICIONADO À AUXILIAR.
	*/
	char no_repeat[strlen(func_str)];
	int controle = 0, k = 1, i, j;//k COMEÇA APÓS O PRIMEIRO CARACTERE
	no_repeat[0] = func_str[0];//O PRIMEIRO CARACTERE NUNCA É REPETIDO
	no_repeat[1] = '\0';

	for(i = 0; func_str[i] != '\0'; i++){
		controle = 0;
		for(j = 0; no_repeat[j] != '\0'; j++){
			if(func_str[i] == no_repeat[j]){//CASO O CARACTERE DA STRING ESTEJA NA AUXILIAR, O CONTROLE VIRA FALSO
				controle = 0;
				break;//CHAMA A PRÓXIMA ANÁLISE CASO O CARACTERE SE REPITA
			}else
				controle = 1;
		}
		if(controle)//CASO O CONTROLE SEJA SEMPRE VERDADEIRO
			no_repeat[k++] = func_str[i];
	}
	no_repeat[k] = '\0';
	//printf("\n%s\n", no_repeat);
	strcpy(func_str, no_repeat);
}
/*
    NOME: RICARDO DE FREITAS OLIVERIA.
    R.A.: 5934078.
    CURSO: CIÊNCIA DA COMPUTAÇÃO.
*/
