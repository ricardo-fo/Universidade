/*
3)Crie uma função que recebe uma string e um caractere, e apague todas as
ocorrências desses caractere na string.
*/

//BIBLIOTECAS E OS SEUS PORQUÊS
#include <stdio.h>	   //padrão
#include <string.h>	   //strlen(); e strcpy();
#include <ctype.h>	   //tolower();

void delete(char * str, char ch);//PROTÓTIPO

int main()
{
	char str[1001], ch;
	int i;

	printf("string >>> ");
	scanf(" %1000[^\n]", str);
	printf("caractere >>> ");
	scanf(" %c", &ch);
	for(i = 0; str[i] != '\0'; i++){//DEIXA A STRING EM MINÚSCULOS
		str[i] = tolower(str[i]);
	}
	ch = tolower(ch);

	delete(str, ch);
	printf("\n%s\n", str);

	return 0;
}

void delete(char * func_str, char func_ch)
{
	/*
	A FUNÇÃO PEDE DOIS ARGUMENTOS, UMA STRING E UM CARACTERE. APÓS ISSO, A
	FUNÇÃO IMPRIME A STRING SEM O CARACTERE QUE FOI PASSADO.
	NOTA: ELA NÃO RETORNA A STRING SEM OS CARACTERES.
	*/
	char no_char[strlen(func_str)];
	int i, j = 0;

	for(i = 0; func_str[i] != '\0'; i++){
		//printf("%c\n", func_str[i]);
		if(func_str[i] != func_ch)//VERIFICA SE O ELEMENTOS ANALISADO É DIFERENTE DO CARACTERE PASSADO.
			no_char[j++] = func_str[i];//ARMAZENA EM UMA STRING AUXILIAR OS CARACTERES DIFERENTES DO ARGUMENTO PASSADO, ch.
	}
	no_char[j] = '\0';//ADIÇÃO DO CARACTERE DE ESCAPE QUE FALTAVA.
	//printf("\n%s\n", no_char);
	strcpy(func_str, no_char);
}
/*
    NOME: RICARDO DE FREITAS OLIVERIA.
    R.A.: 5934078.
    CURSO: CIÊNCIA DA COMPUTAÇÃO.
*/
