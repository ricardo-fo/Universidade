/*
5)	Faça uma função chamada compara() que recebe duas strings (s1 e s2)
como parâmetros e compara os seus conteúdos. A função deve retornar a
posição onde s2 começa dentro de s1 (caso s2 faça parte de s1) e -1, caso
contrário. Repare que s2 pode estar contida em s2 em qualquer posição. Não
use a função strstr(). Exemplo: se a função recebesse as strings s1 à
“atenciosamente” e s2 à “cio”, a função deveria retornar 4.
*/

//BIBLIOTECAS E OS SEUS PORQUÊS
#include <stdio.h>		//padrão
#include <string.h>		//strlen();
#include <ctype.h>		//tolower();

int compara(char * func_str1, char * func_str2);//PROTÓTIPO DA FUNÇÃO

int main()
{

	char str1[1001], str2[1001];
	int i;

	printf("string 1 >>> ");
	scanf(" %1000[^\n]", str1);
	printf("string 2 >>> ");
	scanf(" %1000[^\n]", str2);

	for(i = 0; str1[i] != '\0'; i++){//DEIXA AS STRINGS EM MINÚSCULO
		str1[i] = tolower(str1[i]);
	}
	for(i = 0; str2[i] != '\0'; i++){
		str2[i] = tolower(str2[i]);
	}


	printf("%d\n", compara(str1, str2));

	return 0;
}

int compara(char * func_str1, char * func_str2)
{
	/*
	A FUNÇÃO RECEBE DOIS ARGUMENTOS, STRINGS, E RETORNA -1 OU SE STR2 NÃO ESTÁ
	EM STR1 OU SE STR2 É MAIOR QUE STR1. RETORNA 0 CASO AS DUAS STRINGS SEJAM
	IGUAIS, OU RETORNA O ÍNDICE DE STR1 ONDE STR2 APARECE.
	*/
	int i, k = 0, lenght = strlen(func_str2), z;

	if(strlen(func_str1) > strlen(func_str2)){//CASO STR2 SEJA MENOR QUE STR1
		for(i = 0; func_str1[i] != '\0'; i++){
			if(func_str1[i] == func_str2[0]){
				z = strncmp(&func_str1[i], func_str2, lenght);//COMPARA A PARTIR DO ENDEREÇO DE MEMÓRIA EM QUE OS ELEMENTOS SÃO IGUAIS NAS DUAS STRINGS, SENDO QUE lenght INDICA ATÉ ONDE STR1 DEVE SER VERIFICADA
				if(!z)//CASO STR2 ESTEJA EM STR1
					return i;
				else{//CASO STR2 NÃO ESTEJA EM STR1
					k = -1;
					continue;
				}
			}
		}
		return k;//CASO STR2 REALMENTE NÃO ESTEJA EM STR1
	}else{
		z = strcmp(func_str1, func_str2);//VERIFICA SE AS STRINGS SÃO IGUAIS
		if(!z)//CASO SEJAM IGUAIS
			return z;
		else//CASO STR2 SEJA MAIOR QUE STR1
			return -1;
	}
}
/*
    NOME: RICARDO DE FREITAS OLIVERIA.
    R.A.: 5934078.
    CURSO: CIÊNCIA DA COMPUTAÇÃO.
*/
