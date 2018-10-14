/*
Criar um caixa eletrônico para sacar um dinheiro informado pelo usuário.
Após o scan do valor à sacar, o usuário deve escolher 2 cédulas diferentes
(2,5,10,20,50 ou 100). Output: A menor quantidade de cédulas para sacar o
valor. Obs: É obrigatório conter as duas cédulas no output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool menu(double *, double *, double *);/*menu de controle*/
int quantas(double, double, double);/*informa quantas notas serão usadas*/
bool valido(double);/*verifica se a cédula informada é váldia*/

int main()
{
	double valor, n1, n2;

	while(menu(&valor, &n1, &n2)){
		quantas(valor, n1, n2);
	}

	return 0;
}

bool menu(double * quantia, double * nota1, double * nota2)
{
	/*Esta função cria um menu amigável. 
	Objetivo: poupar repetir as linhas duas vezes.
	recebe 3 argumentos do tipo ponteiro de double e modifica eles na main();
	*/
	double valor, n1, n2;
	printf("Bem-vindo(a) ao Caixa Eletronico.\n\n");
	printf("Atalhos:\nDigitar uma quantia <= 0 finaliza o programa!\n");
	printf("\nInforme a quantia que deseja sacar:\n>>> R$ ");
	scanf("%lf", &valor);
	if(valor <= 0){return false;}
	while((valor > abs(valor) && valor < (abs(valor) + 1)) || valor < 0){
		printf("\n!!! - Informe apenas quantias inteiras positivas:\n>>> R$ ");
		scanf("%lf", &valor);
	}

	printf("\nInforme as duas notas que deseja sacar:\nCedulas validas - 2, 5, 10, 20, 50, 100:\n\nNota 1 - >>> R$ ");
	scanf("%lf", &n1);
	while(!valido(n1)){
		printf("\n!!! - Informe apenas notas validas:\n1 - >>> R$ ");
		scanf("%lf", &n1);
	}

	printf("\nNota 2 - >>> R$ ");
	scanf("%lf", &n2);
	while(!valido(n2)){
		printf("\n!!! - Informe apenas notas validas:\n2 - >>> R$ ");
		scanf("%lf", &n2);
	}
	*quantia = valor;
	*nota1 = n1;
	*nota2 = n2;
}

bool valido(double verificar)
{
	/*Esta função verifica se o valor informado é uma cédula válida.
	Arg: double
	Return: true, caso a cédula seja válida
	        false, caso a cédula não seja válida
	*/
	int i, cedulas[6] = {2, 5, 10, 20, 50, 100};//cédulas válidas
	for(i = 0; i < 6; i++){
		if(verificar == cedulas[i])
			return true;
	}
	return false;
}
int quantas(double quantia, double nota1, double nota2)
{
	/*Esta função verifica quantas notas serão necessárias para chegar
	no valor informado.
	Recebe 3 argumentos.
	Arg1: double - valor que deseja sacar
	Arg2: double - nota que deseja usar
	Arg3: double - outra nota que deseja usar
	Return: 0 se é possível sacar
	        1 se não é possível sacar
	*/
	double aux;
	char ch;

	if(nota1 < nota2){
		aux = nota1;
		nota1 = nota2;
		nota2 = aux;
	}
	int i, j;
	for(i = 1; i < quantia; i++){
		for(j = 1; j < quantia; j++){
			if((nota2 * i + nota1 * j) == quantia){
				printf("\nNota(s) de R$ %.0f,00: %d\nNota(s) de R$ %.0f,00: %d\n", nota1, j, nota2, i);
				printf("\nTecle algo . . . ");
				ch = getchar();
				ch = getchar();
				system("cls");
				return 0;
			}
		}
	}
	printf("\nImpossivel chegar ao valor passado usando as notas informadas!\n");
	printf("\nTecle algo . . . ");
	ch = getchar();
	ch = getchar();
	system("cls");
	return 1;
}
