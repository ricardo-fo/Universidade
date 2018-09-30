#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000000

struct manipulacao{
	int numero[15][2];/*numero e votos*/
	float porcentagem[15];/*porcentagem de vitoria*/
};
//typedef struct manipulacao candidatos;
int voto[MAX];
void mkFile(const int, char *, const char *);/*arg1 = valor a iterar, arg2 = nome do arquivo, arg3 = extensão do arquivo*/
void manipula(const int, struct manipulacao *);/*arg1 = quantidade de candidadtos, arg2 = registro dos dados dos candidatos*/
void geraUrna(const int, const float, const struct manipulacao *);/*arg1 = quantidade de candidatos, arg2 = parcela de vitoria, arg3 = dados dos favorecidos*/

int main()
{
	int quantos = 1, i;
	float parcela;
	char margem;
	typedef struct manipulacao candidatos;
	candidatos eleicao;

	printf("Digite quantos candidatos serao favorecidos:\n>>> ");
	scanf("%d", &quantos);
	while(quantos <= 0 || quantos >= 15){
		printf("Valor invalido!\nInforme um valor na faixa de 0 a 15:\n>>> ");
		scanf("%d", &quantos);
		if(quantos == 0){return 0;}
	}
	printf("\nNAO REPITA CANDIDATOS!\nInforme o(s) numero(s) do(s) candidato(s) a ser(em) favorecido(s) em ordem de vitoria:\n");
	for(i = 0; i < quantos; i++){
        	eleicao.numero[i][1] = 0;
        	eleicao.porcentagem[i] = (1.0/pow(3, i)) * 100;/*porcentagem padrão*/
		printf("\nFavorecido %02d:\n>>> ", i + 1);
		scanf("%d", &eleicao.numero[i][0]);
		printf("eleicao.numero = %d\n", eleicao.numero[i][0]);
	}
	printf("\nDeseja informar a margem de vitoria(s/n)?\nExemplo: candidato X ganhou 40%% dos votos.\n>>> ");
	scanf(" %c", &margem);

	if(margem == 's' || margem == 'S')
		manipula(quantos, &eleicao);
	//printf("porcentagem teste: %f\n", eleicao.porcentagem[1]);
	printf("0 tá ok\n");
	geraUrna(quantos, parcela, &eleicao);

	return 0;
}

void geraUrna(const int quantidade, const float vantagem, const struct manipulacao * favorecidos)
{
	int i, j, k, random, num[15] = {1, 2, 12, 13 ,15, 16, 17, 18, 19, 27, 30, 45, 50, 51, 54};
	FILE * pin;
	srand((unsigned)time(NULL));
	for(i = 1; i < 25; i++){
		char arquivo = "urna";
		mkFile(i, arquivo, ".bin");
		pin = fopen(arquivo, "wb");
		for(j = 0; j < MAX; j++){
			random = rand() % 15;
			if(num[random] == favorecidos->numero[j][0]){
				/*A FINALIZAR*/
			}
		}
	}
	/*for(j = 0; j < 15; j++){
		if(j < quantidade){
			for(k = 0; k < favorecidos->porcentagem[j]*10000; k++){
				voto[k] = favorecidos->numero[j][0];
			}
			for(;k < (MAX - (favorecidos->porcentagem[j] * 10000)); k++){
				random = rand() % 15;
				voto[k] = num[random];
			}
			fwrite(voto, sizeof(int), MAX, pin);
			//fclose(pin);
		}else{
			for(k = 0; k < MAX; k++){
				random = rand() % 15;
				voto[k] = num[random];
			}
			fwrite(voto, sizeof(int), MAX, pin);
		}
		printf("Jeitinho brasileiro em andamento. . .\n\n");
	}
	fclose(pin);*/
	
}
void mkFile(const int numero, char * arquivo, const char * extensao)
{
	char buffer[3];
  	itoa(numero, buffer, 10);
    	strcat(arquivo, buffer);
    	strcat(arquivo, extensao);
}

void manipula(const int quantidade, struct manipulacao * func_eleicao)
{
	int i;
	double total = 100, x;
	//float receberao = 0;
	for(i = 0; i < quantidade; i++){
		if(total <= 0){
			printf("Voce usou todos os votos!\n");
			break;
		}
		printf("\nVoce pode usar %0.5lf%% de 100%%.", total);
		printf("\nPorcentagem para o candidato %d:\n>>> ", (*func_eleicao).numero[i][0]);
		scanf("%lf", &x);
		(*func_eleicao).porcentagem[i] = x;
		while((*func_eleicao).porcentagem[i] < 0){
			printf("\nInforme uma porcentagem valida!");
			printf("\nPorcentagem para o candidato %d:\n>>> ", (*func_eleicao).numero[i][0]);
			scanf("%lf", &x);
			(*func_eleicao).porcentagem[i] = x;
		}
		total -= ((*func_eleicao).porcentagem[i]);
	}
	/*printf("Deseja que seus candidatos recebam quantos porcento de todos os votos?\nDigite apenas o numero, sem sinal de %%:\n>>> ");
	scanf("%f", &receberao);
	while(receberao <= 0 || receberao >= 100){
		printf("Valor negativo ou excedente a 100!\nInforme um valor na faixa de 0 a 100:\n>>> ");
		scanf("%f", &receberao);
	}*/
}
