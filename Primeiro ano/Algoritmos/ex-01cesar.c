/*
1)	O código de Cesar é uma das técnicas de criptografia mais simples e
conhecidas. É um tipo de substituição no qual cada letra do texto é
substituída por outra, que se apresenta n posições após ela no alfabeto.
Por exemplo, com uma troca de três posições a letra A seria substituída
por D, B se tornaria E e assim por diante. Escreva um programa que faça
uso da função void cesar(char[], int posicoes) . Entre com uma string, gere
uma nova string e imprima uma string codificada. Exemplo:

String: a ligeira raposa marrom saltou sobre o cachorro cansado

Nova String: d oljhlud udsrvd pduurp vdowrx vreuh r fdfkruur fdqvdgr
*/

//BIBLIOTECAS E OS SEUS PORQUÊS
#include <stdio.h>     /*padrão*/
#include <ctype.h>     /*tolower();*/

void cesar(char * str, int desloc);//PROTÓTIPO DA FUNÇÃO

int main()
{
	int desloc, i;
	char str[1001];

	printf("string >>>> ");
	scanf(" %1000[^\n]", str);
	printf("deslocamento >>> ");
	scanf("%d", &desloc);



	for(i = 0; str[i] != '\0'; i++){//DEIXA A STRING EM MINÚSCULO
		str[i] = tolower(str[i]);
	}
	printf("\n");
	cesar(str, desloc);

	return 0;
}

void cesar(char * func_str, int func_desloc)
{
	/*
	:A FUNÇÃO VARRE A STRING, CASO ACHE O CARACTERE ESPAÇO, É PRINTADO UM ESPAÇO
	E O LAÇO É ITERADO.
	:CASO O CARACTERE NÃO SEJA UM ESPAÇO, O VALOR DE DESLOCAMENTO É ACRESCENTADO
	À STRING.
	:CASO ESSE VALOR PASSE DO LIMITE DOS CARACTERES MINÚSCULOS, UM LAÇO
	while É INICIADO PARA QUE O VALOR PASSADO SEJA DIMINUIDO ATÉ QUE ATINJA UM
	VALOR DENTRO DOS LIMITES.
	*/
	int i, j;

	for(i = 0; func_str[i] != '\0'; i++){
		if(func_str[i] == ' ') {
			printf(" ");
			continue;
		}

		int valor = func_desloc + func_str[i];
        while(valor > 122){//CONTROLE DOS LIMITES
            valor -= 26;
        }
        printf("%c", valor);
	}
	printf("\n");
}

/*
    NOME: RICARDO DE FREITAS OLIVERIA.
    R.A.: 5934078.
    CURSO: CIÊNCIA DA COMPUTAÇÃO.
*/
