#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000000

struct manipulacao{
	int numero[15][2];/*numero e votos*/
	double porcentagem[15];/*porcentagem de vitoria*/
};
typedef struct manipulacao candidatos;

void mkFile(const int, char *, const char *);/*arg1 = valor a iterar, arg2 = nome do arquivo, arg3 = extensão do arquivo*/
double manipula(const int, candidatos *);/*arg1 = quantidade de candidadtos, arg2 = registro dos dados dos candidatos*/
void geraUrna(const int, const double, const candidatos *);/*arg1 = quantidade de candidatos, arg2 = parcela de vitoria, arg3 = dados dos favorecidos*/

int main()
{
	int quantos, i;
	printf("Digite quantos candidatos serao favorecidos:\n>>> ");
	scanf("%d", &quantos);

	candidatos eleicao;

	printf("\nInforme o(s) numero(s) do(s) candidato(s) a ser(em) favorecido(s) em ordem de vitoria:\n");
	for(i = 0; i < quantos; i++){
        eleicao.numero[i][1] = 0;
        eleicao.porcentagem[i] = (1.0/pow(3, i + 1)) * 100.0;/*porcentagem padrão*/
		printf("\nFavorecido %02d:\n>>> ", i + 1);
		scanf("%d", &eleicao.numero[i][0]);
	}
    char margem;
	printf("\nDeseja informar a margem de vitoria(s/n)?\nExemplo: candidato X ganhou 40%% dos votos.\n>>> ");
	scanf(" %c", &margem);
	double parcela;

	if(margem == 's' || margem == 'S')
		parcela = manipula(quantos, &eleicao);
	geraUrna(quantos, parcela, &eleicao);

	return 0;
}

void geraUrna(const int quantidade, const double vantagem, const candidatos * favorecidos)
{
	FILE * pin;
	int i, urnas = 24 * ( (int) (ceil(vantagem / 100.0) )), cont, lim = 0, k;
	for(i = 0; i < 1; i++){
		lim = (int) ((*favorecidos).porcentagem[i] * MAX);
		int voto[lim];
		cont = 0;
		for(k = 0; k < lim; k++){
			voto[i] = (*favorecidos).numero[i][0];
			cont++;
		}
		/*char file[11] = "urna";
		mkFile(j, file, ".bin");*/
		pin = fopen("urna.bin", "wb");
		fwrite(voto, sizeof(int), MAX, pin);
		fclose(pin);
		//(*favorecidos).numero[i][1] = cont;
	}
}
void mkFile(const int numero, char * arquivo, const char * extensao)
{
	char buffer[3];
    itoa(numero, buffer, 10);
    strcat(arquivo, buffer);
    strcat(arquivo, extensao);
}

double manipula(const int quantidade, candidatos * func_eleicao)
{
	int i;
	double receberao, total = 100, x;
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
		total -= (*func_eleicao).porcentagem[i];
	}
	printf("Deseja que seus candidatos recebam quantos porcento de todos os votos?\nDigite apenas o numero, sem sinal de %%:\n>>> ");
	scanf("%lf", &receberao);
	return receberao;
}
