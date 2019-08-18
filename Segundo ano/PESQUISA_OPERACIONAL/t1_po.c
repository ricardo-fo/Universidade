/*
 * 1º Trabalho de Pesquisa Operacional.
 * Integrantes do grupo:
 * Nome: Alexandre Saura.
 * Nome: Fábio Thomaz.
 * Nome: Ricardo Oliveira.
 * Profº.: José Fontebasso Neto.
 * Disciplina: Pesquisa Operacional - I.
 * Universidade  Católica de Santos - Maio de 2019.
*/

#include <stdio.h> // uso: inputs e outputs.
#include <string.h> // uso: strcmp();
#include <ctype.h> // uso: tolower();
#include <stdlib.h>
#include <stdbool.h>

#define PRECISAO 100000

int inicializar_valor_inteiro(char *);
void receber_tipo_problema(char *);
void inicializar_objetivo(double *, char *);
void inicializar_matriz(double[][*], double *, double *);
void print_matriz(double[][*], double *, double *, int *);
void print_solucao(double *, int *);

void simplex(double[][*], double *, double *, int *);
void tornar_viavel(double[][*], double *, double *, int *);
void otimizar_resultado(double[][*], double *, double *, int *);
void pivotamento(double[][*], double *, double *, int *, int, int);

void analizar_recursos(double[][*], double *, double *);
void analizar_objetivos(double[][*], double *, double *, int *);

int qntdd_var, qntdd_rest;
int larg_matriz, comp_matriz, larg_real, comp_real;
double solucao_objetivo;

int main()
{
	int i,j;
	char problema[4];

	qntdd_var = inicializar_valor_inteiro("variaveis"); // quantidade de variaveis
	qntdd_rest = inicializar_valor_inteiro("restricoes"); // quantidade de restrições

	larg_matriz = qntdd_rest; // largura da matriz
	comp_matriz = qntdd_rest + qntdd_var; // comprimento da matriz

	// aumento o tamanho da matriz caso alguma restrição seja "==" não precisa recriar a matriz
	larg_real = larg_matriz * 2; // largura real da matriz
	comp_real = comp_matriz + larg_matriz; // comprimento real da matriz

	double objetivos[comp_real]; // vetor que armazena todos os valores da linha do Z com exeção da solução
	for(i = 0; i < comp_real; i++) objetivos[i] = 0; // zera o vetor objetivos

	double solucoes[larg_real]; // vetor que armazena todas as soluções com exeção da linha do Z
	for(i = 0; i < larg_real; i++) solucoes[i] = 0; // zera o vetor solucoes

	double matriz[larg_real][comp_real]; // inicia a matriz com a largura real e comprimento real
	for(i = 0; i < larg_real; i++) {
		for(j = 0; j < comp_real; j++) matriz[i][j] = 0; // zera a matriz
	}

	int indices[comp_real]; // vetor indice que armazena as posições dos elemento da base
	for(i = 0; i < comp_real; i++) indices[i] = i + qntdd_var; // zera o vetor inidice

	solucao_objetivo = 0; // variavel que contem a intercessão da linha do Z com a coluna da Solução

	receber_tipo_problema(problema); // recebe qual vai ser o tipo do problema (max ou min)

	inicializar_objetivo(objetivos, problema); // inicializa os dados dos objetivos

	inicializar_matriz(matriz, objetivos, solucoes); //inicializa os dados da matriz

	// realiza backup dos valores dos objetivos iniciais
	double objetivos_iniciais[comp_real];
	for(i = 0; i < comp_real; i++) objetivos_iniciais[i] = objetivos[i];

	// realiza backup dos valores das soluções iniciais
	double solucoes_iniciais[larg_real];
	for(i = 0; i < larg_real; i++) solucoes_iniciais[i] = solucoes[i];

	// imprime a tabela inicial
	printf("\nQuadro inicial\n");
	print_matriz(matriz, objetivos, solucoes, indices);

	// realiza o simplex
	simplex(matriz, objetivos, solucoes, indices);

	// imprime a solução do método simple
	print_solucao(solucoes, indices);

	printf("\nAnalise de Sensibilidade\n");
	analizar_recursos(matriz, solucoes, solucoes_iniciais); // realiza a analise de recursos
	analizar_objetivos(matriz, objetivos, objetivos_iniciais, indices); // realiza a analise de objetivos

	return 0;
}

int inicializar_valor_inteiro(char * msg) {
	int valor;
	char buffer;
	do {
		printf("Informe a quantidade de %s (maximo 20): ", msg);
		if (scanf("%d", &valor) != 1) // recebe o valor
		{
			while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
			fprintf(stderr, "ERRO: input passado nao corresponde a um numero inteiro.\n\n");
			continue;
		}
	} while (valor <= 0 || valor > 20); // se o valor for menor que 0 ou maior que 20 continua no while

	return valor;
}

void receber_tipo_problema(char * problema) {
	int i;
	char buffer;
	/* Input do tipo de problema */
	printf("\n");
	do {
		printf("Tipo de problema (max/min): ");
		scanf(" %3[a-xA-X]", problema); // fomatação para leitura de apenas letras minusculas.
		while (getchar() != '\n'); // limpeza do buffer do teclado.

		for (i = 0; i < 4; i++) { // conversão para letras minusculas.
			problema[i] = tolower(problema[i]);
		}
	} while (strcmp(problema, "max") != 0 && strcmp(problema, "min") != 0);
}

void inicializar_objetivo(double * objetivos, char * problema) {
	int i;
	char buffer;
	/* Input da função objetivo */
	printf("\nFuncao objetivo\n");
	for (i = 0; i < qntdd_var; i++) {
		printf("Coeficiente da variavel x%d: ", i);
		while (scanf("%lf", &objetivos[i]) != 1) {
			while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
			fprintf(stderr, "ERRO: input passado nao corresponde a um numero real.\n\n");
			printf("Coeficiente da variavel x%d: ", i);
		}
		while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.

		if(strcmp(problema, "max") == 0) {
			objetivos[i] *= -1;
			if(abs((long)(objetivos[i] * PRECISAO)) == 0) objetivos[i] = abs(objetivos[i]);
		}
	}
}

void inicializar_matriz(double matriz[larg_real][comp_real], double * objetivos, double * solucoes) {
	int i, j, k = 0;
	char buffer;
	bool igual_igual = false;
	char tipo_restricao[3];
	/* Input dos dados das restrições */
	for (i = 0; i < qntdd_rest; i++)
	{
		if(!igual_igual) {
			printf("\nRestricao %d:\n", i + 1 - k);

			/* Input dos coeficientes da variavel*/
			for (j = 0; j < qntdd_var; j++)
			{
				printf("Coeficiente da variavel x%d: ", j);
				while (scanf("%lf", &matriz[i][j]) != 1) {
					while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
					fprintf(stderr, "ERRO: input passado nao corresponde a um numero real.\n\n");
					printf("Coeficiente da variavel x%d: ", j);
				}
				while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
			}

			/* Input do tipo de restricao */
			do {
				printf("Opcoes de restricao:\n==\n<=\n>=\n");
				printf("Tipo de restricao: ");
				scanf(" %3s", tipo_restricao);
				while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
			} while (strcmp(tipo_restricao, "==") != 0 && strcmp(tipo_restricao, "<=") != 0 && strcmp(tipo_restricao, ">=") != 0);

			/* Input do termo independente */
			printf("Termo independente: ");
			while (scanf("%lf", &solucoes[i]) != 1) {
				while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
				fprintf(stderr, "ERRO: input passado nao corresponde a um numero real.\n\n");
				printf("Termo independente: ");
			}
			while ((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.
		}

		matriz[i][qntdd_var + i] = 1; // coloca o valor 1 na variavel de auxilio correspondente

		if(!igual_igual && strcmp(tipo_restricao, "==") == 0) {
			for (j = 0; j < qntdd_var; j++) matriz[i + 1][j] = matriz[i][j]; // duplica as variaveis para a linha de baixo
			solucoes[i + 1] = solucoes[i]; // duplica a solucao para a linha de baixo

			igual_igual = true;
			larg_matriz++; // aumenta a largura do vetor
			comp_matriz++; // aumenta o comprimento do vetor
			qntdd_rest++; // aumenta as quantidade de restricoes
			k++;
		} else if (igual_igual || strcmp(tipo_restricao, ">=") == 0) {
		    // multiplica todas as variaveis da matriz por -1 com exeção das variaveis de auxilio
			for (j = 0; j < qntdd_var; j++)
			{
				matriz[i][j] *= -1;
				if(abs((long)(matriz[i][j] * PRECISAO)) == 0) matriz[i][j] = abs(matriz[i][j]);
			}
			//multiplica a solução por -1
			solucoes[i] *= -1;
			if(abs((long)(solucoes[i] * PRECISAO)) == 0) solucoes[i] = abs(solucoes[i]);

			igual_igual = false;
		}
	}
}

void print_matriz(double matriz[larg_matriz][comp_real], double * objetivos, double * solucoes, int * indices)
{
	int i, j;

    // imprime a linha da base
	printf("Base\t");
	for (i = 0; i < comp_matriz; i++) printf("x%d\t", i);
	printf("Solucao\n");

    // imprime a linha do Z
	printf("z\t");
	for (i = 0; i < comp_matriz; i++) printf("%.2lf\t", objetivos[i]);
	printf("%.2lf\n", solucao_objetivo);

	// imprime as linhas das restricoes da matriz
	for (i = 0; i < larg_matriz; i++) {
		printf("x%d\t", indices[i]);
		for (j = 0; j < comp_matriz; j++) printf("%.2lf\t", matriz[i][j]);
		printf("%.2lf\n", solucoes[i]);
	}
}

void print_solucao(double * solucoes, int * indices) {
	printf("Solucao: %.2lf\n", solucao_objetivo);
	int i, j;

    // imprime os valores das variaveis que ficaram no simplex em ordem crescente
	for(i = 0; i < qntdd_var; i++) {
		for(j = 0; j < larg_matriz; j++) {
			if(i == indices[j]) {
				printf("x%d: %.2lf\n", i, solucoes[j]);
				break;
			}
		}
	}
}

void simplex(double matriz[larg_matriz][comp_real], double * objetivos, double * solucoes, int * indices)
{
    bool is_solved = false;
    bool continuar;
    int i;

    // continua enquanto não estiver resolvido o simplex
    while(!is_solved) {
        continuar = true;

        // verifica se há algum numero negativo na coluna da Solucao para tornar viavel
        for(i = 0; i < larg_matriz; i++){
            if(solucoes[i] < 0) {
                tornar_viavel(matriz, objetivos, solucoes, indices);
                continuar = false;
                break;
            }
        }
        // caso havia um numero negativo na coluna da Solucao verificar novamente se há outro número negativo
        if(!continuar) continue;

        // verifica se há algum numero negativo na linha do Z para otimizar o resultado
        for(i = 0; i < comp_matriz; i++){
            if(objetivos[i] < 0) {
                otimizar_resultado(matriz, objetivos, solucoes, indices);
                continuar = false;
                break;
            }
        }
        // caso havia um numero negativo na linha do Z verificar novamente se um numero negativo na coluna da Solucao e depois ver se há na linha do Z
        if(!continuar) continue;

        is_solved = true;
    }
}

void tornar_viavel(double matriz[larg_matriz][comp_real], double * objetivos, double * solucoes, int * indices) {
    int i;
    int menor_larg = 0;
    for(i = 1; i < larg_matriz; i++) {
        if(solucoes[i] < solucoes[menor_larg]) menor_larg = i; // pega o valor negativo na coluna da Solução
    }

    // procura o numero a coluna com menor resultado final diferente de 0
    int menor_comp = -1;
    for(i = 0; i < comp_matriz; i++) {
        if(abs((long)(matriz[menor_larg][i] * PRECISAO)) != 0 && abs((long)((objetivos[i] / matriz[menor_larg][i]) * PRECISAO)) != 0) {
            if(menor_comp == -1) menor_comp = i;
            else if(objetivos[i] / matriz[i][menor_comp] < objetivos[menor_comp] / matriz[menor_larg][menor_comp]) menor_comp = i;
        }
    }

    pivotamento(matriz, objetivos, solucoes, indices, menor_larg, menor_comp); // realiza a troca da linha pela coluna
}

void otimizar_resultado(double matriz[larg_matriz][comp_real], double * objetivos, double * solucoes, int * indices) {
    int i;
    int menor_comp = 0;
    for(i = 1; i < comp_matriz; i++) {
        if(objetivos[i] < objetivos[menor_comp]) menor_comp = i; // pega o valor negativo na linha do Z
    }

    // procura o numero a linha com menor resultado final maior de 0
    int menor_larg = -1;
    for(i = 0; i < larg_matriz; i++) {
        if(abs((long)(matriz[i][menor_comp] * PRECISAO)) != 0 && (long)((solucoes[i] / matriz[i][menor_comp]) * PRECISAO) > 0) {
            if(menor_larg == -1) menor_larg = i;
			else if(solucoes[i] / matriz[i][menor_comp] < solucoes[menor_larg] / matriz[menor_larg][menor_comp]) menor_larg = i;
        }
    }

    pivotamento(matriz, objetivos, solucoes, indices, menor_larg, menor_comp); // realiza a troca da linha pela coluna
}

void pivotamento(double matriz[larg_matriz][comp_real], double * objetivos, double * solucoes, int * indices, int x, int y) {
    static int interacao = 1;
    int i, j;
	double pivo, multiplicar;

	// se o valor da linha ou coluna for negativa afirma que não há solução para a matriz
	if(x == -1 || y == -1) {
		fprintf(stderr, "ERRO: Matriz sem solucao.\n\n");
		exit(1);
	}

    // imprime qual interação esta sendo realizada e os valores das linhas e colunas que estam trocando
	printf("Interacao %d: sai x%d, entra x%d\n", interacao++, indices[x], y);

	indices[x] = y; // troca o indice pelo novo valor da coluna
    pivo = matriz[x][y]; // pega o valor do pivo

    for(i = 0; i < comp_matriz; i++) matriz[x][i] /= pivo; // divide a linha do pivo por ele
    solucoes[x] /= pivo; // divide a solucao do pivo pelo pivo

    multiplicar = objetivos[y]; // recebe o numero a se multiplicar da linha do pivo pela linha
    // soma o objetivo inicial com a multiplicacao do valor do objetivo com a linha do pivo e armazena denovo no objetivo
    for(i = 0; i < comp_matriz; i++) {
        objetivos[i] += multiplicar * matriz[x][i] * (-1);
		if(abs((long)(objetivos[i] * PRECISAO)) == 0) objetivos[i] = abs(objetivos[i]);
    }
    // soma a solucao do objetivo inicial com a multiplicacao do valor do objetivo com a linha do pivo e armazena denovo na solucao do objetivo
    solucao_objetivo += multiplicar * solucoes[x] * (-1);
	if(abs((long)(solucao_objetivo * PRECISAO)) == 0) solucao_objetivo = abs(solucao_objetivo);

    for(i = 0; i < larg_matriz; i++) {
        if(x == i) continue;

        multiplicar = matriz[i][y]; // recebe o numero a se multiplicar
        // soma a matriz com a multiplicacao do valor do matriz com a linha do pivo e armazena denovo na matriz
        for(j = 0; j < comp_matriz; j++) {
            matriz[i][j] += multiplicar * matriz[x][j] * (-1);
			if(abs((long)(matriz[i][j] * PRECISAO)) == 0) matriz[i][j] = abs(matriz[i][j]);
        }
        // soma a solucao com a multiplicacao do valor da matriz com a linha do pivo e armazena denovo na solucao
        solucoes[i] += multiplicar * solucoes[x] * (-1);
		if(abs((long)(solucoes[i] * PRECISAO)) == 0) solucoes[i] = abs(solucoes[i]);
    }

	print_matriz(matriz, objetivos, solucoes, indices); // imprime a matriz
}

void analizar_recursos(double matriz[larg_matriz][comp_real], double * solucoes, double * solucoes_iniciais) {
	double valor;
	int i, j;

	printf("\nRecursos\n\n");

	for(j = qntdd_var; j < comp_matriz; j++) {
		for(i = 0; i < larg_matriz; i++) {
			if(abs((long)(matriz[i][j] * PRECISAO)) != 0) { // verifica se não ira fazer uma divisao por 0
				valor = solucoes[i] / matriz[i][j] * (-1); // descobre o valor da solucao dividido pela matriz e multiplicada por -1
				valor += solucoes_iniciais[j - qntdd_var]; // soma o valor descoberto pelo valor inicial

				// imprime a faixa de valores
				if(matriz[i][j] > 0) printf("   |x%d >= %.2lf", j, valor);
				else printf("   |x%d <= %.2lf", j, valor);
			}
		}
		printf("\n");
	}
}

void analizar_objetivos(double matriz[larg_matriz][comp_real], double * objetivos, double * objetivos_iniciais, int * indices) {
	double valor;
	int i, j;

	printf("\nCoeficientes do Objetivo\n\n");

	for(i = 0; i < larg_matriz; i++) {
		if(indices[i] < qntdd_var) {
			for(j = qntdd_var; j < comp_matriz; j++) {

				if(abs((long)(matriz[i][j] * PRECISAO)) != 0) { // verifica se não ira fazer uma divisao por 0
					valor = objetivos[j] / matriz[i][j] * (-1); // descobre o valor da solucao dividido pela matriz e multiplicada por -1
					valor += objetivos_iniciais[indices[i]] * (-1); // soma o valor descoberto pelo valor inicial

					// imprime a faixa de valores
					if(matriz[i][j] > 0) printf("   |c%d >= %.2lf", indices[i], valor);
					else printf("   |c%d <= %.2lf", indices[i], valor);
				}
			}
			printf("\n");
		}
	}
}
