/*
3.	Faça um programa em C com duas funções: uma para gravar em um arquivo e outra para
escrever. O programa principal deve conter um menu com as opções: 1- Gravar Pessoa;
2- Exibir Listagem; 3- Sair. Ao escolher Gravar Pessoa, a função void gravar(void) deve
ser chamada; ao escolher Exibir Listagem, o programa deve exibir o conteúdo do arquivo
manipulado em Gravar Pessoa; O nome do arquivo deve ser parametrizado em uma variável
global.

void gravarPessoa(void):

A função permite o usuário informar o nome de uma pessoa e o ano de nascimento. Deve ser
criada uma linha no arquivo com a seguinte característica:

[nome                                                                ][anonascimento]\n

Onde deve ser preenchido com espaços após o nome até que se atinja um total de 50 caracteres
para nome, seguido de 4 caracteres para o ano de nascimento. Exemplo:

Fernando..........................................1977

(Na linha acima cada ponto corresponde a um espaço. Neste caso como a string Fernando
possui 8 caracteres, são concatenados 42 espaços para que atinja 50)

void exibirListagem(void):

A função deverá ler o arquivo de entrada e imprimir na tela cada linha. O programa deve
calcular a idade a partir do ano de nascimento, e colocar ao lado do nascimento uma
mensagem conforme a regra a seguir:

Se a idade for menor do que 18 anos, escrever:  <18
Se a idade for maior ou igual que 18 anos, escrever  OK

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gravarPessoa(void);
void exibirListagem(void);

char file[] = "macedo.txt";

int main()
{
	FILE * prime;
	int choice, a = 1;
	if((prime = fopen(file, "r")) == NULL)
		prime = fopen(file, "w");
	fclose(prime);
	while(a){
		printf("\nEscolha uma das opcoes abaixo:\n1- Gravar Pessoa;\n2- Exibir Listagem;\n3- Sair\n>>> ");
		scanf("%d", &choice);
		switch(choice){
				case 1:
				gravarPessoa();
				break;
			case 2:
				exibirListagem();
				break;
			default:
				a = 0;
		}
	}
	return 0;
}

void gravarPessoa()
{
	FILE * pin;
	char name[51], born[5];

	printf("\nInforme o nome:\n>>> ");
	scanf(" %50[^\n]", name);
	printf("\nInforme o ano de nascimento:\n>>> ");
	scanf(" %4s", born);
	char dots[51] = "                                                  ";

	if((pin = fopen(file,"a")) == NULL){
        printf("\nArquivo vazio ou inexistente!\n");
        exit(1);
	}
	fprintf(pin,"%s",name);
	fprintf(pin,"%s",&dots[strlen(name)]);
	fprintf(pin,"%s",born);
	if((2018 - atoi(born)) >=18)
		fprintf(pin,"%s", " OK");
	else
		fprintf(pin,"%s"," <18");
	fprintf(pin,"%c",'\n');
	fclose(pin);
}

void exibirListagem()
{
	FILE * pout;
	char show;

	pout = fopen(file,"r");
	while(!(feof(pout))){
		show = fgetc(pout);
		printf("%c", show);
	}
	fclose(pout);

}
/*
Nome: Ricardo de Freitas Olveira.
Curso: Ciência da Computação.
R.A.: 5934078.
Exe.: 03.
*/
