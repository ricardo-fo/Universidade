/*
Criar um caixa eletrônico para sacar um dinheiro informado pelo usuário.
Após o scan do valor à sacar, o usuário deve escolher 2 cédulas diferentes
(2,5,10,20,50 ou 100). Output: A menor quantidade de cédulas para sacar o
valor. Obs: É obrigatório conter as duas cédulas no output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quantas(const int *, float, float, float);
bool valido(float, const int *);

int main()
{
	int cedulas[6] = {2, 5, 10, 20, 50, 100};
	float valor, n1, n2;
	bool z;

	printf("Informe a quantia que deseja sacar:\n>>> R$ ");
	scanf("%f", &valor);
	while((valor > abs(valor) && valor < (abs(valor) + 1)) || valor <= 0){
		printf("\n!!! - Informe apenas quantias inteiras positivas:\n>>> R$ ");
		scanf("%f", &valor);
	}
	printf("\nInforme as duas notas que deseja sacar.\nCedulas validas - 2, 5, 10, 20, 50, 100:\n1 - >>> R$ ");
	scanf("%f", &n1);
	while(!valido(n1, cedulas)){
		printf("\n!!! - Informe apenas notas validas:\n1 - >>> R$ ");
		scanf("%f", &n1);
	}
	printf("\n2 - >>> R$ ");
	scanf("%f", &n2);
	while(!valido(n2, cedulas)){
		printf("\n!!! - Informe apenas notas validas:\n2 - >>> R$ ");
		scanf("%f", &n2);
	}
	quantas(cedulas, valor, n1, n2);

	return 0;
}

bool valido(float verificar, const int * valores)
{
	int i;
	for(i = 0; i < 6; i++){
		if(verificar == valores[i])
			return true;
	}
	return false;
}
void quantas(const int * notas, float quantia, float nota1, float nota2)
{
	float aux, n1 = nota1, n2 = nota2, a = quantia;

	if(nota1 < nota2){
		aux = nota1;
		nota1 = nota2;
		nota2 = aux;
	}
	int i, j;
	for(i = 1; i < quantia; i++){
		for(j = 1; j < quantia; j++){
			if((nota2 * i + nota1 * j) == quantia){
				printf("\nnota(s) de R$ %.0f,00: %d\nnota(s) de R$ %.0f,00: %d\n", nota1, j, nota2, i);
				exit(1);
			}
		}
	}
	printf("\nImpossivel chegar ao valor passado usando as notas informadas!\n");

}
