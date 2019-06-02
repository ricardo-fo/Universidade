/* t1_pe.c
 * 1º Trabalho de Probabilidade e Estatística.
 * Integrantes do grupo:
 * Nome: Alexandre Saura.
 * Nome: Ricardo Oliveira.
 * Nome: Vitor Kuribara.
 * Profº.: José Fontebasso Neto.
 * Discplina: Probabilidade e Estatística - I.
 * Universidade  Católica de Santos - Maio de 2019.
*/
#include <stdio.h> // uso: inptus e outputs.
#include <stdlib.h> // uso: fprintf(); fscanf();
#include <string.h> // uso: strcat(); strcmp(); strrchr(); strtok(); strcpy(); strlen(); strrev();
#include <stdbool.h> // uso: true e false;
#include <math.h> // uso: log10();

// Opções do menu
void calcular_arquivo_existente(void);
void criar_arquivo_novo(void);

// Manipulação dos arquivos
int quantidade_valores(FILE *, const char *);
void inserir_nome_arquivo(char []);
FILE * abrir_arquivo(const char *, const char *);
void coletar_dados(int, double [], double [], FILE *, const char *, const char *, char [][*], char [][*]);
void validar_extensao(char *, const char *);
void inserir_dados(FILE *);

// Estatística
double media(int, double []);
double moda(int, double []);
void tabela_frequencias(int, double [], int);
void encontrar_frequencias(int, double [], int, double [], int []);

// Ferramentas
int maior_valor(int, double []);
int menor_valor(int, double []);
int quantidade_casas_decimais(int, char [][21]);
double arredondar(double, int);

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

    // Menu principal.
    do{
        printf("\nInforme o numero de uma das opcoes abaixo para fazer a acao desejada:");
        printf("\n<1> Inserir nome de arquivo que possua os dados;");
        printf("\n<2> Criar arquivo e seus dados;");
        printf("\n<0> Sair.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        while((getchar()) != '\n'); // Eliminação de digitos em excesso (limpar o buffer).

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

void calcular_arquivo_existente()
{
    char buffer;
    char separador[2];
    char nome_arquivo[101];
    inserir_nome_arquivo(nome_arquivo);
    FILE * p_arquivo = abrir_arquivo(nome_arquivo, "r");

    printf("\nSeparador: ");
    scanf(" %1s", separador);
    while((buffer = getchar()) != '\n');

    printf("\n============================================================\n");

    int aux;
    int size = quantidade_valores(p_arquivo, separador);
    double vetor_a[size];
    double vetor_b[size];
    char vetor_string_a[size][21];
    char vetor_string_b[size][21];

    coletar_dados(size, vetor_a, vetor_b, p_arquivo, nome_arquivo, separador, vetor_string_a, vetor_string_b);
    fclose(p_arquivo);

    printf("Media dos valores do vetor A: %lf\n", media(size, vetor_a));
    printf("Moda do vetor A: %lf\n", moda(size, vetor_a));

    int casas_decimais = quantidade_casas_decimais(size, vetor_string_a);
    tabela_frequencias(size, vetor_a, casas_decimais);
    /*if((aux = quantidade_casas_decimais(size, vetor_string_b)) > casas_decimais){
        casas_decimais = aux;
    }

    calcular_faixa_valores(size, vetor_b, casas_decimais);*/
    printf("\n============================================================\n");
}

void inserir_nome_arquivo(char nome_arquivo[])
{
    char buffer;
    printf("\nInforme o nome do arquivo junto a sua extensao.");
    printf("\nExemplo: meu_arquivo.txt\n");
    printf("\nNome do arquivo: ");
    scanf(" %100[^\n]", nome_arquivo);
    while((buffer = getchar() != '\n'));
}

FILE * abrir_arquivo(const char * nome_arquivo, const char * tipo)
{
    FILE * p_arquivo;
    if((p_arquivo = fopen(nome_arquivo, tipo)) == NULL){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: Arquivo '%s' nao foi encontrado ou nao pode ser aberto.", nome_arquivo);
        printf("\n******************************************************************************************************");
        fclose(p_arquivo);
    }
    return p_arquivo;
}

int quantidade_valores(FILE * p_arquivo, const char * separador)
{
    int i, contador = 0;
    char linha[22];
    while(fgets(linha, 22, p_arquivo) != NULL){
        if(strpbrk(linha, separador) != NULL){
            contador++;
        }
    }
    return contador;
}

void coletar_dados(int size, double vetor_a[], double vetor_b[], FILE * p_arquivo, const char * nome_arquivo, const char * separador, char vetor_string_a[][21], char vetor_string_b[][21])
{
    char linha[22], * token;
    int i = 0, j = 0;
    rewind(p_arquivo);

    while(fgets(linha, 22, p_arquivo) != NULL){
        token = strtok(linha, separador);
        if(token == NULL){
            fprintf(stderr, "\nERRO: '%s' usa mais de um tipo de delimitador ou o delimitador passado nao corresponde aos do arquivo.\n", nome_arquivo);
            exit(1);
        }
        strcpy(vetor_string_a[i], token);
        vetor_a[i++] = atof(token);
        token = strtok(NULL, separador);
        if(token == NULL){
            fprintf(stderr, "\nERRO: '%s' usa mais de um tipo de delimitador ou o delimitador passado nao corresponde aos do arquivo.\n", nome_arquivo);
            exit(1);
        }
        strcpy(vetor_string_b[j], token);
        vetor_b[j++] = atof(token);
    }
}

void criar_arquivo_novo()
{
    char novo_arquivo[101];
    inserir_nome_arquivo(novo_arquivo);
    char * extensao;
    validar_extensao(novo_arquivo, extensao);
    FILE * p_arquivo = abrir_arquivo(novo_arquivo, "w");

    inserir_dados(p_arquivo);

    fclose(p_arquivo);

    printf("\nSeu arquivo foi criado com sucesso.\n");
}

void validar_extensao(char * nome_arquivo, const char * extensao)
{
    extensao = strrchr(nome_arquivo, '.');
    if(extensao == NULL){
        strcat(nome_arquivo, ".txt");
    } else {
        if(strcmp(extensao, ".txt") != 0){
            strcat(nome_arquivo, ".txt");
        }
    }
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

double media(int size, double vetor[])
{
    int i;
    double soma = 0;

    for(i = 0; i < size; i++){
        soma += vetor[i];
    }
    return (soma/size);
}

double moda(int size, double vetor[])
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
    return vetor[maior_repeticao];
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

void tabela_frequencias(int size, double vetor[], int casas_decimais)
{
    int qntdd_faixa_valores = ceil(3.3 * log10(size));
    double maior = vetor[maior_valor(size, vetor)];
    double menor = vetor[menor_valor(size, vetor)];
    double amplitude_conjuntos = maior - menor;
    double amplitude_faixas = arredondar(amplitude_conjuntos/qntdd_faixa_valores, casas_decimais);
    double faixa_valores[qntdd_faixa_valores + 1];
    int i;

    faixa_valores[0] = menor;
    for(i = 1; i < qntdd_faixa_valores + 1; i++){
        faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;
    }
    faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;

    int frequencia[qntdd_faixa_valores];
    encontrar_frequencias(qntdd_faixa_valores + 1, faixa_valores, size, vetor, frequencia);

    printf("\nTabela de frequencias:");
    for(i = 0; i < qntdd_faixa_valores; i++){
        printf("\n%.*lf  |---  %.*lf | %d", casas_decimais, faixa_valores[i], casas_decimais, faixa_valores[i + 1], frequencia[i]);
    }
}

double arredondar(double valor, int casas)
{
    return ( ceil(valor * pow(10, casas)) / ((double)pow(10, casas)) );
}

int quantidade_casas_decimais(int size, char vetor_string[][21])
{
    int i, j, contador, maior = 0;
    char str_aux[21];

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
    return (7 - maior);
}

void encontrar_frequencias(int size_faixa, double faixa_valores[], int size_vetor, double vetor[], int frequencia[])
{
    int i, j, contador;

    for(i = 0; i < size_faixa; i++){
        contador = 0;
        for(j = 0; j < size_vetor; j++){
            if((vetor[j] >= faixa_valores[i]) && (vetor[j] < faixa_valores[i + 1])){
                printf("\nvetor[%d](%lf) >= faixa[%d](%lf) && vetor[%d](%lf) < faixa[%d + 1](%lf)",j, vetor[j], i, faixa_valores[i], j, vetor[j], i, faixa_valores[i+1]);
                contador++;
            }
        }
        frequencia[i] = contador;
        printf("\n%d: %d", i, frequencia[i]);
    }
}

/*
 ******************************************************************************************************
 * Sobre o programa:
 * Arquivo: trabalho_01_probabilidade_estatistica.c
 * Funcionalidade:
 * 1. Leia dois conjuntos de dados numéricos a partir de um arquivo-texto que, se não existir, permita que
 * o usuário o crie e insira dados nele.
 *     1.1. Caso o arquivo exista, ele deve ter duas colunas separadas por vírgula, ponto e vírgula,
 *     tabulação, ou outro símbolo definido pelo usuário.
 *
 * 2. Elabore a tabela de frequências com cada conjunto de dados deste arquivo, sendo que a tabela deve
 * conter as faixas de valores, o ponto médio, a frequência, a frequência acumulada e as respectivas
 * frequências relativas;
 *
 * 3. Estime a moda, média e o desvio padrão dos dados usando tanto os valores do arquivo, quanto a
 * tabela de frequências;
 *
 * 4. Estime os valores para o box-plot indicando os outliers para cada um dos conjuntos de dados, caso
 * existam;
 *
 * 5. Calcule o coeficiente de correlação de Pearson e os coeficientes da reta de mínimos quadrados.
 *******************************************************************************************************
 */
