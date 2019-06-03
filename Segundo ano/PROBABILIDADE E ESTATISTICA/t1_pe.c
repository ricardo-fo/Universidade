/* t1_pe.c
 * 1� Trabalho de Probabilidade e Estat�stica.
 * Integrantes do grupo:
 * Nome: Alexandre Saura.
 * Nome: Ricardo Oliveira.
 * Nome: Vitor Kuribara.
 * Prof�.: Jos� Fontebasso Neto.
 * Discplina: Probabilidade e Estat�stica - I.
 * Universidade  Cat�lica de Santos - Maio de 2019.
*/
#include <stdio.h> // uso: inptus e outputs.
#include <stdlib.h> // uso: fprintf(); fscanf();
#include <string.h> // uso: strcat(); strcmp(); strrchr(); strtok(); strcpy(); strlen(); strrev();
#include <stdbool.h> // uso: true e false;
#include <math.h> // uso: log10();
#include <ctype.h> // uso: isdigit();

// Op��es do menu
void calcular_arquivo_existente(void);
void criar_arquivo_novo(void);

// Manipula��o dos arquivos
void inserir_nome_arquivo(char []);
int verificar_extensao(const char *, const char *);
int quantidade_valores(FILE *, const char *);
FILE * abrir_arquivo(const char *, const char *);
int coletar_dados(int, double [], double [], FILE *, const char *, const char *, char [][31], char [][31]);
void inserir_dados(FILE *);

// Estat�stica
void tabela_frequencias(int, double [], int);
void encontrar_faixa_valores(double, int, double, double []);
void encontar_ponto_medio(int, double [], float []);
void encontrar_frequencias(int, double [], int, double [], int []);
void encontrar_frequencias_acumuladas(int, int [], int []);
void encontrar_frequencias_relativas(int, int, int [], float []);
void encontrar_frequencias_relativas_acumuladas(int, int, int [], float []);
double media_valores(int, double []);
double media_faixas(int, float [], int []);
void moda_valores(int, double [], double [], int *);
double moda_faixas(int, double [], int []);

// Ferramentas
int maior_valor(int, double []);
int menor_valor(int, double []);
int quantidade_casas_decimais(int, char [][31]);
double arredondar(double, int);
bool is_number(const char token[]);
double soma_simples_double(int, double []);
int soma_simples_int(int, int []);
float soma_produtos(int, float [], int []);
int particao(double [], int, int);
void quick_sort(double [], int, int);
void troca(double *, double *);

int main()
{
    char opcao, buffer;

    printf("Bem-vindo(a).\n");
    printf("\nEste programa coleta dados de um arquivo .txt e, em seguida, baseados nos dados, calcula ou informa:");
    printf("\n* A frequencia de cada conjunto de dados;");
    printf("\n* A estimativa da moda;");
    printf("\n* A estimativa da media;");
    printf("\n* O desvio padrao;");
    printf("\n* A estimativa dos valores do box-plot;");
    printf("\n* Os coeficientes de Pearson e da reta de minimos quadrados.");
    printf("\n------------------------------------------------------------------------------------------------------\n");

    // Menu principal
    do{
        printf("\nInforme o numero de uma das opcoes abaixo para fazer a acao desejada:");
        printf("\n<1> Inserir nome de arquivo que possua os dados;");
        printf("\n<2> Criar arquivo e seus dados;");
        printf("\n<0> Sair.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        while((getchar()) != '\n'); // limpeza do buffer

        switch(opcao){
            case '1':
                printf("\n......................................................................................................\n");
                calcular_arquivo_existente();
                printf("\n......................................................................................................\n");
                break;
            case '2':
                printf("\n......................................................................................................\n");
                criar_arquivo_novo();
                printf("\n......................................................................................................\n");
            case '0':
                break;
            default:
                printf("\n******************************************************************************************************");
                fprintf(stderr, "\nErro: Opcao '%c' invalida. Digite apenas opcoes validas.", opcao);
                printf("\n******************************************************************************************************");
        } // Fecha switch(opcao)
    } while(opcao != '0'); // fecha menu

    printf("\n");

    return 0;
}

/* OP��ES DO MENU ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void calcular_arquivo_existente()
{
    /* Este procedimento executa um submenu para coletar os dados do arquivo e, em seguida, fazer todas as tarefas pedidas. */

    char buffer; // para limpar o teclado.
    char separador[2]; // divisor/delimitador dos conjuntos do arquivo.
    char nome_arquivo[101];
    inserir_nome_arquivo(nome_arquivo);
    if(verificar_extensao(nome_arquivo, ".txt") != 0){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: '%s' nao pode ser aberto, nao e' um arquivo de texto", nome_arquivo);
        printf("\n******************************************************************************************************");
        return;
    }
    FILE * p_arquivo = abrir_arquivo(nome_arquivo, "r");
    if(p_arquivo == NULL) return; // caso o arquivo falhe na abertura.

    // leitura do divisor dos conjuntos do arquivo.
    printf("\nSeparador: ");
    scanf(" %1s", separador);
    while((buffer = getchar()) != '\n'); // limpeza do buffer do teclado.

    int aux;
    int size = quantidade_valores(p_arquivo, separador);// quantidade de valores que tem em um conjunto, pegos do arquivo.
    double vetor_a[size]; // vetor para armazenar os valores do primeiro conjunto/coluna.
    double vetor_b[size]; // vetor para armazenar os valores da segundo conjunto/coluna.
    char vetor_string_a[size][31]; // vetor para armazenar os valores do primeiro conjunto/coluna em formato de string.
    char vetor_string_b[size][31]; // vetor para armazenar os valores da segundo conjunto/coluna em formato de string.
    // NOTA: os vetores que armazenam os valores em string s�o necess�rio para fazer o arredondamento da amplitude das faixas.

    if(coletar_dados(size, vetor_a, vetor_b, p_arquivo, nome_arquivo, separador, vetor_string_a, vetor_string_b) != 0){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: algo esta errado com algum dado de '%s'", nome_arquivo);
        printf("\n******************************************************************************************************");
        fclose(p_arquivo);
        return;
    } // coleta dos dados do arquivo e passagem para os vetores.
    fclose(p_arquivo);

    printf("\n============================================================\n");

    int casas_decimais = quantidade_casas_decimais(size, vetor_string_a); // quantidade de casas ap�s a v�rgula que � usado na primeira coluna.
    printf("\nSobre os dados do primeiro conjunto:");
    tabela_frequencias(size, vetor_a, casas_decimais);

    casas_decimais = quantidade_casas_decimais(size, vetor_string_b); // quantidade de casas ap�s a v�rgula que � usado na segunda coluna.
    printf("\n\nSobre os dados do segundo conjunto:");
    tabela_frequencias(size, vetor_b, casas_decimais);
    printf("\n============================================================\n");
}

void criar_arquivo_novo()
{
    char novo_arquivo[101];
    inserir_nome_arquivo(novo_arquivo);
    char * extensao;
    if(verificar_extensao(novo_arquivo, ".txt") != 0){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: '%s' nao e' do tipo texto.", novo_arquivo);
        printf("\n******************************************************************************************************");
        return;
    }
    FILE * p_arquivo = abrir_arquivo(novo_arquivo, "w");

    inserir_dados(p_arquivo);
    fclose(p_arquivo);

    printf("\nSeu arquivo foi criado com sucesso.\n");
}
/* FIM OP��ES DO MENU -----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* MANIPULA��O DE ARQUIVOS ------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void inserir_nome_arquivo(char nome_arquivo[])
{
    /* Este procedimento l� o nome de um arquivo e evita erros de execu��o.
     * Param�tro: char nome_arquivo[] => string para armazenar o nome do arquivo. */

    char buffer;
    printf("\nInforme o nome do arquivo junto a sua extensao.");
    printf("\nExemplo: meu_arquivo.txt\n");
    printf("\nNome do arquivo: ");
    scanf(" %100[^\n]", nome_arquivo);
    while((buffer = getchar() != '\n')); // limpeza do buffer.
}

int verificar_extensao(const char * nome_arquivo, const char * tipo)
{
    char * extensao = strrchr(nome_arquivo, '.');
    if(extensao == NULL){
        return 1;
    } else {
        if(strcmp(extensao, tipo) != 0){
            return 1;
        }
        return 0;
    }
}

FILE * abrir_arquivo(const char * nome_arquivo, const char * tipo)
{
    /* Esta fun��o verifica se � poss�vel abrir o arquivo passado.
     * Param�tros: const char * nome_arquivo => string constante com o nome do arquivo a ser aberto.
                   const char * tipo => string constante com o tipo de abertura, i.e. [r, a, w, r+, ...]
     * Retorno: o ponteiro do arquivo caso a abertura seja bem sucedida; caso contr�rio, NULL. */

    FILE * p_arquivo; // stream do arquivo.
    if((p_arquivo = fopen(nome_arquivo, tipo)) == NULL){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: Arquivo '%s' nao foi encontrado ou nao pode ser aberto.", nome_arquivo);
        printf("\n******************************************************************************************************");
        fclose(p_arquivo);
        return NULL;
    }
    return p_arquivo;
}

void inserir_dados(FILE * p_arquivo)
{
    char buffer;
    char separador;
    int qntdd_dados, i;
    double dado_a, dado_b;

    printf("\nSeu arquivo deve possuir duas colunas de dados numericos.");
    printf("\nQuantidade de dados a ser inserido: ");
    while((scanf("%d", &qntdd_dados) != 1) || qntdd_dados < 0){
        while((buffer = getchar()) != '\n');
        printf("\nValor invalido.\n");
        printf("\nQuantidade de dados a ser inserido: ");
    }

    printf("\nSimbolo a ser usado: ");
    scanf(" %c", &separador);
    while((buffer = getchar()) != '\n');

    printf("\nInsercao de dados. Utilize espaco para cada coluna. Exemplo:\n2.8 3.7\n4.6 5.5\n1.9 7.3\n. . .\n");
    for(i = 0; i < qntdd_dados/2; i++){
        printf(">>> ");
        scanf("%lf %lf", &dado_a, &dado_b);
        fprintf(p_arquivo, "%lf%c%lf%c", dado_a, separador, dado_b, '\n');
    }
}

int quantidade_valores(FILE * p_arquivo, const char * separador)
{
    int i, contador = 0;
    char linha[51];
    while(fgets(linha, 51, p_arquivo) != NULL){
        if(strpbrk(linha, separador) != NULL){
            contador++;
        }
    }
    return contador;
}

int coletar_dados(int size, double vetor_a[], double vetor_b[], FILE * p_arquivo, const char * nome_arquivo, const char * separador, char vetor_string_a[][31], char vetor_string_b[][31])
{
    char linha[51], * token, aux[51];
    int i = 0, j = 0;
    rewind(p_arquivo);

    while(fgets(linha, 51, p_arquivo) != NULL){
        token = strtok(linha, separador);
        if(token == NULL){
            return 1;
        }
        if(!is_number(token)){
            return 1;
        }
        sprintf(aux, "%lf", atof(token));
        strcpy(vetor_string_a[i], aux);
        vetor_a[i++] = atof(token);
        token = strtok(NULL, separador);
        if(token == NULL){
            return 1;
        }
        if(!is_number(token)){
            return 1;
        }
        sprintf(aux, "%lf", atof(token));
        strcpy(vetor_string_b[i], aux);
        vetor_b[j++] = atof(token);
    }
    return 0;
}
/* FIM MANIPULA��O DE ARQUIVOS ---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* ESTAT�STICA -------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void tabela_frequencias(int size, double vetor[], int casas_decimais)
{
    int qntdd_faixa_valores = ceil(3.3 * log10(size));
    double maior = vetor[maior_valor(size, vetor)];
    double menor = vetor[menor_valor(size, vetor)];
    double amplitude_conjuntos = maior - menor;
    double amplitude_faixas = arredondar(amplitude_conjuntos/qntdd_faixa_valores, casas_decimais);
    double faixa_valores[qntdd_faixa_valores + 1];
    int i;

    encontrar_faixa_valores(menor, qntdd_faixa_valores, amplitude_faixas, faixa_valores);

    float ponto_medio[qntdd_faixa_valores];
    encontar_ponto_medio(qntdd_faixa_valores, faixa_valores, ponto_medio);

    int frequencia[qntdd_faixa_valores];
    encontrar_frequencias(qntdd_faixa_valores + 1, faixa_valores, size, vetor, frequencia);

    int frequencia_acumulada[qntdd_faixa_valores];
    encontrar_frequencias_acumuladas(qntdd_faixa_valores, frequencia, frequencia_acumulada);

    float frequencia_relativa[qntdd_faixa_valores];
    encontrar_frequencias_relativas(qntdd_faixa_valores, size, frequencia, frequencia_relativa);

    float frequencia_relativa_acumulada[qntdd_faixa_valores];
    encontrar_frequencias_relativas_acumuladas(qntdd_faixa_valores, size, frequencia_acumulada, frequencia_relativa_acumulada);

    printf("\nTabela de frequencias:");
    printf("\nFaixa de valores | P.M. | frq | fra | fr.r. | fr.ra |");
    for(i = 0; i < qntdd_faixa_valores; i++){
        printf("\n%.*lf  |---  %.*lf | ", casas_decimais, faixa_valores[i], casas_decimais, faixa_valores[i + 1]);
        printf("%0.*f | ", 2, ponto_medio[i]);
        printf("%0.*d | ", 3, frequencia[i]);
        printf("%0.*d | ", 3, frequencia_acumulada[i]);
        printf("%0.*f | ", 3, frequencia_relativa[i]);
        printf("%0.*f | ", 3, frequencia_relativa_acumulada[i]);
    }
    double moda[size];
    printf("\n\nMedia dos valores do conjunto A: %lf", media_valores(size, vetor));
    printf("\nMedia das faixas de valores do conjunto A: %lf", media_faixas(qntdd_faixa_valores, ponto_medio, frequencia));
    printf("\nModa(s) do vetor A:");
    int qntdd_modas = 0;
    moda_valores(size, vetor, moda, &qntdd_modas);
    for(i = 0; i < qntdd_modas; i++){
        printf("%lf, ", moda[i]);
    }
    printf("\b\b\n");
    //printf("\nModa do vetor A: %lf\n", moda_faixas(size, vetor));
}

void encontrar_faixa_valores(double menor, int size, double amplitude_faixas, double faixa_valores[])
{
    int i;

    faixa_valores[0] = menor;
    for(i = 1; i < size + 1; i++){
        faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;
    }
    faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;
}

void encontar_ponto_medio(int size, double faixa_valores[], float ponto_medio[])
{
    int i;

    for(i = 0; i < size; i++){
        ponto_medio[i] = (float)(faixa_valores[i] + faixa_valores[i + 1]) / 2;
    }
}

void encontrar_frequencias(int size_faixa, double faixa_valores[], int size_vetor, double vetor[], int frequencia[])
{
    int i, j, contador;

    for(i = 0; i < size_faixa; i++){
        contador = 0;
        for(j = 0; j < size_vetor; j++){
            if(((float)vetor[j] >= (float)faixa_valores[i]) && ((float)vetor[j] < (float)faixa_valores[i + 1])){
                contador++;
            }
        }
        frequencia[i] = contador;
    }
}

void encontrar_frequencias_acumuladas(int size, int frequencia[], int frequencia_acumulada[])
{
    int i;

    frequencia_acumulada[0] = frequencia[0];
    for(i = 1; i < size; i++){
        frequencia_acumulada[i] = frequencia_acumulada[i - 1] +  frequencia[i];
    }
}

void encontrar_frequencias_relativas(int size_faixas, int size_valores, int frequencia[], float frequencia_relativa[])
{
    int i;

    for(i = 0; i < size_faixas; i++){
        frequencia_relativa[i] = frequencia[i] / (float)size_valores;
    }
}

void encontrar_frequencias_relativas_acumuladas(int size_faixas, int size, int frequencia_acumulada[], float frequencia_relativa_acumulada[])
{
    int i;

    for(i = 0; i < size_faixas; i++){
        frequencia_relativa_acumulada[i] = frequencia_acumulada[i] / (float)size;
    }
}

double media_valores(int size, double vetor[])
{
    return (soma_simples_double(size, vetor)/size);
}

double media_faixas(int size, float ponto_medio[], int frequencias[])
{
    int i;

    return(soma_produtos(size, ponto_medio, frequencias)/soma_simples_int(size, frequencias));
}

void moda_valores(int size, double vetor[], double moda[], int * qntdd_modas)
{
    int i, j, contador, maior_repeticao = 0, quantidade_repeticoes[size];

    for(i = 0; i < size; i++){
        contador = 0;
        for(j = 0; j < size; j++){
            if(vetor[i] == vetor[j]){
                contador++;
            }
        }
        quantidade_repeticoes[i] = contador;
    }

    for(i = 0; i < size; i++){
        if(quantidade_repeticoes[i] > quantidade_repeticoes[maior_repeticao]){
            maior_repeticao = i;
        }
    }

    int k = 0;
    bool ja_esta;

    for(i = 0; i < size; i++){
        if(quantidade_repeticoes[maior_repeticao] == quantidade_repeticoes[i]){
            ja_esta = false;
            for(j = 0; j < size; j++){
                if(moda[j] == vetor[i]){
                    ja_esta = true;
                    break;
                }
            }
            if(!ja_esta){
                moda[k++] = vetor[i];
            }
        }
    }
    //quick_sort(moda, 0, k);
    *qntdd_modas = k;
}

/*double moda_faixas()
{

}*/
/* FIM ESTAT�STICA ----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* FERRAMENTAS --------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
double arredondar(double valor, int casas)
{
    return ( ceil(valor * pow(10, casas)) / pow(10, casas) );
}

int quantidade_casas_decimais(int size, char vetor_string[][31])
{
    int i, j, contador, maior = 0;
    char str_aux[31];

    for(i = 0; i < size; i++){
        contador = 0;
        j = 0;
        strcpy(str_aux, vetor_string[i]);
        strrev(str_aux);
        while(str_aux[j] == '0' && j < strlen(str_aux)){
            contador++;
            j++;
        }
        if(contador > maior){
            maior = contador;
        }
    }
    if(contador == 0) {
        return 0;
    }else{
        return (7 - maior);
    }
}

bool is_number(const char token[])
{
    int i;
    bool dot = true;

    for(i = 0; i < strlen(token) - 1; i++){
        if(isdigit(token[i] == 0)){
            if(token[i] == '.' && dot){
                dot = false;
            } else {
                return false;
            }
        }
    }
    return true;
}

int maior_valor(int size, double vetor[])
{
    int i, maior = 0;

    for(i = 0; i < size; i++){
        if(vetor[i] > vetor[maior]){
            maior = i;
        }
    }

    return maior;
}

int menor_valor(int size, double vetor[])
{
    int i, menor = 0;

    for(i = 0; i < size; i++){
        if(vetor[i] < vetor[menor]){
            menor = i;
        }
    }

    return menor;
}

double soma_simples_double(int size, double vetor[])
{
    int i;
    double soma = 0;

    for(i = 0; i < size; i++){
        soma += vetor[i];
    }

    return soma;
}

int soma_simples_int(int size, int vetor[])
{
    int i, soma = 0;

    for(i = 0; i < size; i++){
        soma += vetor[i];
    }

    return soma;
}

float soma_produtos(int size, float vetor_a[], int vetor_b[])
{
    int i;
    float soma = 0;

    for(i = 0; i < size; i++){
        soma += (vetor_a[i] * vetor_b[i]);
    }

    return soma;
}

int particao(double vetor[], int e, int d)
{
    double pivo = vetor[d];
    int j, i = (e - 1);

    for(j = e; j <= d - 1; j++){
        if(vetor[j] <= pivo){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[d]);
    return (i + 1);
}

void troca(double * a, double * b)
{
    double aux = *a;
    *a = *b;
    *b = aux;
}

void quick_sort(double vetor[], int e, int d)
{
    if(e < d){
        int pi = particao(vetor, e, d);

        quick_sort(vetor, e, pi - 1);
        quick_sort(vetor, pi + 1, d);
    }
}
/* FIM FERRAMENTAS ----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/******************************************************************************************************
 * Sobre o programa:
 * Funcionalidade:
 * 1. Leia dois conjuntos de dados num�ricos a partir de um arquivo-texto que, se n�o existir, permita que
 * o usu�rio o crie e insira dados nele.
 *     1.1. Caso o arquivo exista, ele deve ter duas colunas separadas por v�rgula, ponto e v�rgula,
 *     tabula��o, ou outro s�mbolo definido pelo usu�rio.
 *
 * 2. Elabore a tabela de frequ�ncias com cada conjunto de dados deste arquivo, sendo que a tabela deve
 * conter as faixas de valores, o ponto m�dio, a frequ�ncia, a frequ�ncia acumulada e as respectivas
 * frequ�ncias relativas;
 *
 * 3. Estime a moda, m�dia e o desvio padr�o dos dados usando tanto os valores do arquivo, quanto a
 * tabela de frequ�ncias;
 *
 * 4. Estime os valores para o box-plot indicando os outliers para cada um dos conjuntos de dados, caso
 * existam;
 *
 * 5. Calcule o coeficiente de correla��o de Pearson e os coeficientes da reta de m�nimos quadrados.
 ********************************************************************************************************/
