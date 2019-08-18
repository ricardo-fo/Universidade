/* t1_pe.c
 * 1º Trabalho de Probabilidade e Estatística.
 * Integrantes do grupo:
 * Nome: Alexandre Saura.
 * Nome: Ricardo Oliveira.
 * Nome: Vitor Kuribara.
 * Profº.: José Fontebasso Neto.
 * Discplina: Probabilidade e Estatística - I.
 * Universidade Católica de Santos - Maio de 2019.
*/
#include <stdio.h> // uso: inptus e outputs.
#include <stdlib.h> // uso: fprintf(); fscanf();
#include <string.h> // uso: strcat(); strcmp(); strrchr(); strtok(); strcpy(); strlen(); strrev();
#include <stdbool.h> // uso: true e false;
#include <math.h> // uso: log10(); pow(); sqrt();
#include <ctype.h> // uso: isdigit();

// Opções do menu
void calcular_arquivo_existente(void);
void criar_arquivo_novo(void);

// Manipulação dos arquivos
void inserir_nome_arquivo(char []);
int verificar_extensao(const char *, const char *);
int quantidade_valores(FILE *, const char *);
FILE * abrir_arquivo(const char *, const char *);
int coletar_dados(int, double [], double [], FILE *, const char *, const char *, char [][31], char [][31]);
void inserir_dados(FILE *);

// Estatística
void tabela_frequencias(int, double [], int);
void encontrar_faixa_valores(double, int, double, double []);
void encontar_ponto_medio(int, double [], float []);
void encontrar_frequencias(int, double [], int, double [], int []);
void encontrar_frequencias_acumuladas(int, int [], int []);
void encontrar_frequencias_relativas(int, int, int [], float []);
void encontrar_frequencias_relativas_acumuladas(int, int, int [], float []);
double encontrar_media_valores(int, double []);
double encontrar_media_faixas(int, float [], int []);
int encontrar_moda_valores(int, double [], double [], int *);
int encontrar_moda_faixas(int, double [], int [], double, double [], int *);
double encontrar_mediana(int, double []);
double encontrar_quartil_inferior(int, double []);
double encontrar_quartil_superior(int, double []);
void encontrar_box_plot(double, double, double, int, double [], double []);
void encontrar_outliers(double, double, int *, double [], int, double []);
double encontrar_desvio_padrao(int, double, double []);
void encontrar_correlacao_Pearson(int, double [], double []);
void encontrar_regressao_linear(int, double [], double []);

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
        while((buffer = getchar()) != '\n'); // limpeza do buffer

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

/* OPÇÕES DO MENU ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
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
    // NOTA: os vetores que armazenam os valores em string são necessário para fazer o arredondamento da amplitude das faixas.

    if(coletar_dados(size, vetor_a, vetor_b, p_arquivo, nome_arquivo, separador, vetor_string_a, vetor_string_b) != 0){
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: algo esta errado com algum dado de '%s'", nome_arquivo);
        printf("\n******************************************************************************************************");
        fclose(p_arquivo);
        return;
    } // coleta dos dados do arquivo e passagem para os vetores.
    fclose(p_arquivo);

    printf("\n============================================================");
    int casas_decimais = quantidade_casas_decimais(size, vetor_string_a); // quantidade de casas após a vírgula que é usado na primeira coluna.
    printf("\nSobre os dados do primeiro conjunto (coluna da esquerda):");
    tabela_frequencias(size, vetor_a, casas_decimais);

    printf("\n============================================================\n");

    casas_decimais = quantidade_casas_decimais(size, vetor_string_b); // quantidade de casas após a vírgula que é usado na segunda coluna.
    printf("\nSobre os dados do segundo conjunto (coluna da direita):");
    tabela_frequencias(size, vetor_b, casas_decimais);
    printf("\n============================================================\n");

    encontrar_correlacao_Pearson(size, vetor_a, vetor_b);
    encontrar_regressao_linear(size, vetor_a, vetor_b);
}

void criar_arquivo_novo()
{
    /* Este procedimento valida um nome de arquivo, sua extensão e, caso seja tudo
     * permitido, um  arquivo é criado */
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
/* FIM OPÇÕES DO MENU -----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* MANIPULAÇÃO DE ARQUIVOS ------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void inserir_nome_arquivo(char nome_arquivo[])
{
    /* Este procedimento lê o nome de um arquivo e evita erros de execução.
     * Paramêtro: char nome_arquivo[] => string para armazenar o nome do arquivo. */

    char buffer;
    printf("\nInforme o nome do arquivo junto a sua extensao.");
    printf("\nExemplo: meu_arquivo.txt\n");
    printf("\nNome do arquivo: ");
    scanf(" %100[^\n]", nome_arquivo);
    while((buffer = getchar() != '\n')); // limpeza do buffer.
}

int verificar_extensao(const char * nome_arquivo, const char * tipo)
{
    /* Esta função veritifca se é possível criar um arquivo com a extensão passada
     * Caso seja possível, retonra 0, caso contrário, retona 1*/
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
    /* Esta função verifica se é possível abrir o arquivo passado.
     * Paramêtros: const char * nome_arquivo => string constante com o nome do arquivo a ser aberto.
                   const char * tipo => string constante com o tipo de abertura, i.e. [r, a, w, r+, ...]
     * Retorno: o ponteiro do arquivo caso a abertura seja bem sucedida; caso contrário, NULL. */

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
    /* Este procedimento insere dados numa stream passada como parâmetro,
     * verificando se as operações são possíveis de serem feitas */
    char buffer;
    char separador;
    int qntdd_dados, i;
    double dado_a, dado_b;

    printf("\nSeu arquivo deve possuir duas colunas de dados numericos.");
    printf("\nQuantidade de dados a ser inserido: ");
    while((scanf("%d", &qntdd_dados) != 1) || qntdd_dados < 0){ // validação da quantidade de dados (apenas inteiros)
        while((buffer = getchar()) != '\n'); // limpeza do buffer
        printf("\nEntrada invalida.\n");
        printf("\nQuantidade de dados a ser inserido: ");
    }

    printf("\nSimbolo a ser usado: ");
    scanf(" %c", &separador);
    while((buffer = getchar()) != '\n'); // limpeza do buffer

    while(separador == '.' || isdigit(separador) != 0){ // validação e prevenção de erros no separador passado
        printf("\n******************************************************************************************************");
        fprintf(stderr, "\nErro: '%c' nao e' um separador valido. Nao utilize o caractere ponto ou numeros como separador.", separador);
        printf("\n******************************************************************************************************");
        printf("\nSimbolo a ser usado: ");
        scanf(" %c", &separador);
        while((buffer = getchar()) != '\n'); // limpeza do buffer
    }

    printf("\nInsercao de dados. Utilize espaco para cada coluna. Exemplo:\n2.8 3.7\n4.6 5.5\n1.9 7.3\n. . .\n");
    for(i = 0; i < qntdd_dados/2; i++){ // inserção dos dados no arquivo
        printf(">>> ");
        scanf("%lf %lf", &dado_a, &dado_b);
        fprintf(p_arquivo, "%lf%c%lf%c", dado_a, separador, dado_b, '\n');
    }
}

int quantidade_valores(FILE * p_arquivo, const char * separador)
{
    /* Esta função obtém a quantidade de valores em um arquivo, retornando a quantidade de
     * valores armazenado, recebe como argumento a stream do arquivo e o separador usado */
    int i, contador = 0;
    char linha[51];
    while(fgets(linha, 51, p_arquivo) != NULL){ // leitura do arquivo
        if(strpbrk(linha, separador) != NULL){ // busca pelo separador
            contador++;
        }
    }
    return contador;
}

int coletar_dados(int size, double vetor_a[], double vetor_b[], FILE * p_arquivo, const char * nome_arquivo, const char * separador, char vetor_string_a[][31], char vetor_string_b[][31])
{
    /* Esta função coleta dados de um arquivo, recebe como parâmetros a quantidade de dados,
     * um vetor para armazenar os dados da coluna a, outro vetor para armazenar os dados da coluna
     * b, uma stream de arquivo, o nome do arquivo, o separador usado e dois vetores de strings
     * para validar a quantidade de casas decimais presentes nos dados do arquivo */
    char linha[51], * token, aux[51];
    int i = 0, j = 0;
    rewind(p_arquivo); // movimenta o indicador de leitura para o início do arquivo

    while(fgets(linha, 51, p_arquivo) != NULL){ // leitura do arquivo
        token = strtok(linha, separador); // divide o arquivo a partir do separador passado
        if(token == NULL){ // verifica se há o separador na linha analisada
            return 1; // caso não haja o separador, retorna 1
        }
        if(!is_number(token)){ // verifica se a linha lida possui apenas números e o separador
            return 1; // caso haja algo não numérico na linha
        }
        sprintf(aux, "%lf", atof(token)); // atribui a uma string a conversão do dado da linha (string) para um double
        strcpy(vetor_string_a[i], aux); // copia o conteudo de aux para o vetor de strings
        vetor_a[i++] = atof(token); // armazena o dado num vetor de doubles
        token = strtok(NULL, separador); // vai para o próximo dado da linha
        if(token == NULL){ // caso não haja o separador buscado
            return 1;
        }
        if(!is_number(token)){ // repetição das instruções feitas nos dados da coluna A para os dados da coluna B
            return 1;
        }
        sprintf(aux, "%lf", atof(token));
        strcpy(vetor_string_b[i], aux);
        vetor_b[j++] = atof(token);
    }
    return 0; // coleta de dados bem sucedida
}
/* FIM MANIPULAÇÃO DE ARQUIVOS ---------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* ESTATÍSTICA -------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void tabela_frequencias(int size, double vetor[], int casas_decimais)
{
    /* Este procedimento cria a tabela de frequências, tem como paramêtros o tamanho do vetor analisado,
     * o vetor a ser analisado, e a quantidade de casas decimais dos dados  */
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

    // Tabela de frequências
    printf("\nTabela de frequencias:");
    printf("\nFaixa de valores | P.M. | frq | fra | fr.r. | fr.ra |");
    for(i = 0; i < qntdd_faixa_valores; i++){
        printf("\n%05.*lf  |---  %05.*lf | ", casas_decimais, faixa_valores[i], casas_decimais, faixa_valores[i + 1]);
        printf("%0.*f | ", 2, ponto_medio[i]);
        printf("%0.*d | ", 3, frequencia[i]);
        printf("%0.*d | ", 3, frequencia_acumulada[i]);
        printf("%0.*f | ", 3, frequencia_relativa[i]);
        printf("%0.*f | ", 3, frequencia_relativa_acumulada[i]);
    }

    // Média para valores não agrupados
    double media_valores = encontrar_media_valores(size, vetor);
    printf("\n\nMedia dos valores = %lf", media_valores);

    // Média para valores agrupados
    double media_faixas = encontrar_media_faixas(qntdd_faixa_valores, ponto_medio, frequencia);
    printf("\nMedia das faixas de valores = %lf", media_faixas);
    printf("\n");

    // Moda para valores não agrupados
    double moda_valores[size];
    int qntdd_modas = 0;

    if(encontrar_moda_valores(size, vetor, moda_valores, &qntdd_modas) == 0){
        printf("\nNao ha' moda.");
    } else {
        printf("\nModa(s) dos valores: ");
        for(i = 0; i < qntdd_modas; i++){
            printf("%.*lf, ", casas_decimais, moda_valores[i]);
        }
    }

    // Moda para valores agrupados
    double moda_faixas[qntdd_faixa_valores];

    if(encontrar_moda_faixas(qntdd_faixa_valores, faixa_valores, frequencia, amplitude_faixas, moda_faixas, &qntdd_modas) == 0){
        printf("\nNao ha' moda.");
    } else {
        printf("\nModa(s) das faixas de valores: ");
        for(i = 0; i < qntdd_modas; i++){
            moda_faixas[i] = arredondar(moda_faixas[i], casas_decimais);
            printf("%.*lf, ", casas_decimais, moda_faixas[i]);
        }
    }
    printf("\n");

    // Desvio padrão para valores não agrupados
    double desvio_padrao = encontrar_desvio_padrao(size, media_valores, vetor);

    printf("\nDesvio padrao = %.*lf", casas_decimais, desvio_padrao);
    printf("\n");

    // Box-plot
    double mediana = encontrar_mediana(size, vetor);
    double quaritl_inf = encontrar_quartil_inferior(size, vetor);
    double quaritl_sup = encontrar_quartil_superior(size, vetor);
    double box_plot[5];

    encontrar_box_plot(quaritl_inf, mediana, quaritl_sup, size, vetor, box_plot);
    printf("\nBox-Plot:");
    printf("\nLimite inferior = %.*lf", casas_decimais, box_plot[0]);
    printf("\nQuartil inferior = %.*lf", casas_decimais, box_plot[1]);
    printf("\nMediana = %.*lf", casas_decimais, box_plot[2]);
    printf("\nQuartil superior = %.*lf", casas_decimais, box_plot[3]);
    printf("\nLimite superior = %.*lf", casas_decimais, box_plot[4]);

    // Outliers
    int qntdd_outliers;
    double outliers[size];

    encontrar_outliers(box_plot[0], box_plot[4], &qntdd_outliers, vetor, size, outliers);
    if(qntdd_outliers > 0){
        printf("\nOutliers: ");
        for(i = 0; i < qntdd_outliers; i++){
            printf("%.*lf, ", casas_decimais, outliers[i]);
        }
    } else {
        printf("\nNao ha' outliers.");
    }
    printf("\n");
}

void encontrar_faixa_valores(double menor, int size, double amplitude_faixas, double faixa_valores[])
{
    /* Este procedimento encontra as faixas de valores que serão usadas na tabela de frequências.
     * Tem como paramêtros o menor valor, o tamanho do vetor que as faixas serão inseridas,
     * a amplitude das faixas e o vetor para armazenar as faixas de valores. */
    int i;

    faixa_valores[0] = menor;
    for(i = 1; i < size + 1; i++){
        faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;
    }
    faixa_valores[i] = faixa_valores[i - 1] + amplitude_faixas;
}

void encontar_ponto_medio(int size, double faixa_valores[], float ponto_medio[])
{
    /* Este procedimento encontra o ponto médio de um conjunto de dados não agrupados.
     * Tem como paramêtros o tamanho do vetor do ponto médio, o vetor das faixas de valores e o vetor para armazenar os
     * pontos médios. */
    int i;

    for(i = 0; i < size; i++){
        ponto_medio[i] = (float)(faixa_valores[i] + faixa_valores[i + 1]) / 2;
    }
}

void encontrar_frequencias(int size_faixa, double faixa_valores[], int size_vetor, double vetor[], int frequencia[])
{
    /* Este procedimento encontra as frequências de cada faixa de valor, tem como paramêtros o tamanho das faixas de valores,
     * o vetor que armazena as faixas de valores, o tamanho do vetor que contém os dadso, o vetor que contém os dados não agrupados
     * e um vetor para armazenar as frequências. */
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
    /* Este procedimento encontra as frequências acumuladas da tabela de frequências, tem como paramêtros, o tamanho do vetor de frequências,
     * o vetor com os valores das frequências, um vetor para armazenar as frequências acumuladas. */
    int i;

    frequencia_acumulada[0] = frequencia[0];
    for(i = 1; i < size; i++){
        frequencia_acumulada[i] = frequencia_acumulada[i - 1] +  frequencia[i];
    }
}

void encontrar_frequencias_relativas(int size_faixas, int size_valores, int frequencia[], float frequencia_relativa[])
{
    /* Este procedimento encontra as frequências relativas da tabela de frequências, tem como paramêtros, a quantidade de faixa de valores,
     * a quantidade de valores, o vetor que armazena as frequências e um vetor para armazenar as frequências relativas.  */
    int i;

    for(i = 0; i < size_faixas; i++){
        if(size_valores == 0) break;
        frequencia_relativa[i] = frequencia[i] / (float)size_valores;
    }
}

void encontrar_frequencias_relativas_acumuladas(int size_faixas, int size, int frequencia_acumulada[], float frequencia_relativa_acumulada[])
{
    /* Este procedimento encontras as frequências relativas acumuladas da tabela de frequências, tem como paramêtros a quantidade de faixas de
     * valores, a quantidade de valores não agrupados, o vetor com que armazena as frequências acumuladas, um vetor para armazenar as frequências
     * relativas acumuladas. */
    int i;

    for(i = 0; i < size_faixas; i++){
        if(size == 0) break;
        frequencia_relativa_acumulada[i] = frequencia_acumulada[i] / (float)size;
    }
}

double encontrar_media_valores(int size, double vetor[])
{
    /* Esta função econtra a média dos dados não agrupados, tem como paramêtros a quantidade de dados e o vetor que armazena os dados.
     * Retorna a média dos dados contidos no vetor. */
    if(size == 0) return 0;

    return (soma_simples_double(size, vetor)/size);
}

double encontrar_media_faixas(int size, float ponto_medio[], int frequencias[])
{
    /* Esta função encontra a média dos dados agrupados, as faixas de valores, tem como paramêtros a quantidade de faixas de valores, o vetor que
     * armazena os pontos médios das faixas de valores e o vetor de que armazena as frequências de cada faixa de valor.
     * Retorna a média as faixas de valores. */
    if(size == 0) return 0;
    int soma = soma_simples_int(size, frequencias);
    if(soma == 0){
        printf("\nDivisao por 0.");
        exit(1);
    }
    return(soma_produtos(size, ponto_medio, frequencias)/soma);
}

int encontrar_moda_valores(int size, double vetor[], double moda[], int * qntdd_modas)
{
    /* Esta função encontra a moda dos dados não agrupados, tem como paramêtros a quantidade de dados não agrupados, o vetor que contém os
     * dados não agrupados, um vetor para armazenar as modas (caso seja multimodal) e o ponteiro de um inteiro com a quantidade de modas que o
     * vetor de modas irá armazenar.
     * Retorna 0 caso não haja moda, ou retorna 1, caso haja moda. */
    int i, j, contador, maior_repeticao = 0, quantidade_repeticoes[size];

    for(i = 0; i < size; i++){ //Contar quantas repetições há para cada valor
        contador = 0;
        for(j = 0; j < size; j++){
            if(vetor[i] == vetor[j]){
                contador++;
            }
        }
        quantidade_repeticoes[i] = contador;
    }

    for(i = 0; i < size; i++){ // encontrar maior repetição
        if(quantidade_repeticoes[i] > quantidade_repeticoes[maior_repeticao]){
            maior_repeticao = i;
        }
    }

    int k = 0;
    bool ja_esta;

    for(i = 0; i < size; i++){ // Verificar a quantidade de modas e inserir as modas num vetor
        if(quantidade_repeticoes[maior_repeticao] == quantidade_repeticoes[i]){
            ja_esta = false;
            for(j = 0; j < size; j++){ // não repetir valores no vetor que armazena as modas
                if(moda[j] == vetor[i]){
                    ja_esta = true;
                    break;
                }
            }
            if(!ja_esta){ // inserir moda no vetor
                moda[k++] = vetor[i];
            }
        }
    }
    if(size == k){
        return 0;
    }
    quick_sort(moda, 0, k-1); // ordenar as modas para fins estéticos
    *qntdd_modas = k; // quantidade de modas
    return 1;
}

int encontrar_moda_faixas(int size, double faixa_valores[], int frequencia[], double amplitude_modal, double moda[], int * qntdd_modas)
{
    /* Esta função encontra a moda das faixas de valores, caso hajam, tem como paramêtros a quantidade de faixa de valores, o vetor com as
     * faixas de valores, o vetor com as frequências, a amplitude modal, o vetor para armazenar as modas (caso seja multimodal) e um ponteiro
     * para inteiro que indica a quantidade de modas no vetor.
     * Retorna 0 caso não haja moda, ou retorna 1, caso haja moda. */
    int i, j, k = 0, maior_repeticao = 0;
    bool ja_esta;

    for(i = 0; i < size; i++){ // Encontrar maior frequência
        if(frequencia[i] > frequencia[maior_repeticao]){
            maior_repeticao = i;
        }
    }

    double aux;;
    for(i = 1; i < size; i++){
        if(frequencia[maior_repeticao] == frequencia[i]){
            aux = faixa_valores[(i % 2 == 0? i - 1 : i)] + (amplitude_modal * (frequencia[i + 1] / (frequencia[i - 1] + frequencia[i + 1]) ));
            ja_esta = false;
            for(j = 0; j < i; j++){ // não repetir valores no vetor que armazena as modas
                if(moda[j] == aux){
                    ja_esta = true;
                    break;
                }
            }
            if(!ja_esta){ // inserir moda no vetor
                moda[k++] = aux;
            }
        }
    }
    if(size == k){
        return 0;
    }
    quick_sort(moda, 0, k-1); // ordenar as modas para fins estéticos
    *qntdd_modas = k;
    return 1;
}

double encontrar_mediana(int size, double vetor[])
{
    /* Esta função encontra a mediana dos dados não agrupados. Tem como paramêtros a quantidade de dados e o vetor que armazena os dados não agrupados.
     * Retorna o valor da mediana. */
    int i;
    double aux[size];

    for(i = 0; i < size; i++){
        aux[i] = vetor[i];
    }

    quick_sort(aux, 0, size - 1);

    if(size % 2 == 0){
        return((aux[size / 2]));
    }
    return(aux[(size + 1) / 2]);
}

double encontrar_quartil_inferior(int size, double vetor[])
{
    /* Esta função econtra o quartil inferior do conjunto de dados não agrupados, tem como paramêtros a quantidade de dados não agrupados e o vetor que armazena
     * esses dados.
     * Retorna o valor do quartil inferior. */
    int i;
    double aux[size];

    for(i = 0; i < size; i++){
        aux[i] = vetor[i];
    }

    quick_sort(aux, 0, size - 1);

    return aux[(size + 1) / 4];
}

double encontrar_quartil_superior(int size, double vetor[])
{
    /* Esta função econtra o quartil superior do conjunto de dados não agrupados, tem como paramêtros a quantidade de dados não agrupados e o vetor que armazena
     * esses dados.
     * Retorna o valor do quartil superior. */
    int i;
    double aux[size];

    for(i = 0; i < size; i++){
        aux[i] = vetor[i];
    }

    quick_sort(aux, 0, size - 1);

    return aux[(3 * (size + 1)) / 4];
}

void encontrar_box_plot(double quaritl_inf, double mediana, double quaritl_sup, int size, double vetor[], double box_plot[])
{
    /* Este procedimento encontra os valores para o box-plot, tem como paramêtros o valor do quartil inferior, a mediana, o valor do quartil superior,
     * a quantidade de dados não agrupados, o vetor que contém esses dados e um vetor para armazenar os dados do box-plot. */
    double interquartil = quaritl_sup - quaritl_inf;
    double lim_inf = quaritl_inf - 1.5 * interquartil;
    double lim_sup = quaritl_sup + 1.5 * interquartil;

    box_plot[0] = lim_inf;
    box_plot[1] = quaritl_inf;
    box_plot[2] = mediana;
    box_plot[3] = quaritl_sup;
    box_plot[4] = lim_sup;
}

void encontrar_outliers(double lim_inf, double lim_sup, int * qntdd_outliers, double vetor[], int size, double outliers[])
{
    /* Este procedimento verifica se existem outliers baseado nos dados dos achados para o box-plot. Tem como paramêtros o limite inferior,
     * o limite superior, um ponteiro de inteiro que indica a quantidade de outliers encontrados, o vetor que contém os dados não agrupados,
     * a quantidade de dados não agrupados e um vetor para armazenar os outliers. */
    int i, k = 0;

    double aux[size];

    for(i = 0; i < size; i++){
        aux[i] = vetor[i];
    }
    quick_sort(aux, 0, size - 1);

    for(i = 0; i < size; i++){
        if(aux[i] < lim_inf || aux[i] > lim_sup){
            outliers[k] = aux[i];
            k++;
        }
    }
    *qntdd_outliers = k;
}

double encontrar_desvio_padrao(int size, double media, double vetor[])
{
    /* Esta função encontra o desvio padrão de um conjunto de dados, tem como paramêtros a quantidade de dados não agrupados, a media desses dados,
     * o vetor que armazena os dados não agrupados.
     * Retorna o valor do desvio padrão. */
    int i;
    double soma = 0;

    for(i = 0; i < size; i++){
        soma += pow((vetor[i] - media), 2);
    }

    return sqrt( ((1 / (double)size) * soma) );
}

void encontrar_correlacao_Pearson(int size, double vetor_x[], double vetor_y[])
{
    /* Este procedimento encontra a correlacao de Pearson, tem como paramêtros a quantidade de dados não agrupados dos dois vetores a serem analisados.*/
    double media_x = encontrar_media_valores(size, vetor_x);
    double media_y = encontrar_media_valores(size, vetor_y);
    double soma_xy = 0, r;
    int i;

    for (i = 0; i < size; i++){
        soma_xy += (vetor_x[i] - media_x) * (vetor_y[i] - media_y);
    }

    double desvio_padrao_x = encontrar_desvio_padrao(size, media_x, vetor_x);
    double desvio_padrao_y = encontrar_desvio_padrao(size, media_y, vetor_y);
    r = ((1 / (double)size) * soma_xy) / (desvio_padrao_x * desvio_padrao_y);

    if(r <= 1 && r >= -1){
        printf("\n\nCorrelacao de Pearson:\nr = %lf ", r);
        if(r > 0)
        {
            if(r >= 0.9){
                printf("\nCorrelacao positiva muito forte.");
            } else {
                if(r >= 0.7 && r < 0.9){
                    printf("\nCorrelacao positiva forte.");
                } else {
                    if(r >= 0.5 && r < 0.7){
                        printf("\nCorrelacao positiva moderada.");
                    } else {
                        if(r >= 0.3 && r < 0.5){
                            printf("\nCorrelacao positiva fraca.");
                        } else {
                            if(r >= 0 && r < 0.3){
                                printf("\nCorrelacao positiva desprezivel.");
                            }
                        }
                    }
                }
            }
        } else {
            if(r <= -0.9){
                printf("\nCorrelacao positiva muito forte.");
            } else {
                if(r <= -0.7 && r > -0.9){
                    printf("\nCorrelacao positiva forte.");
                } else {
                    if(r <= -0.5 && r > -0.7){
                        printf("\nCorrelacao positiva moderada.");
                    } else {
                        if(r <= -0.3 && r > -0.5){
                            printf("\nCorrelacao positiva fraca.");
                        } else {
                            if(r <= 0 && r > -0.3){
                                printf("\nCorrelacao positiva desprezivel.");
                            }
                        }
                    }
                }
            }
        }
    }
}

void encontrar_regressao_linear(int size, double vetor_x[], double vetor_y[])
{
    /* Este procedimento encontra a equação da regressão linear, tem como paramêtros a quantidade de dados não agrupados, e os dois vetores contendo os dados
     * que serão analisados. */
    double soma_xy = 0, a, b, soma_x2 = 0;
    double media_x = encontrar_media_valores(size, vetor_x);
    double media_y = encontrar_media_valores(size, vetor_y);
    double soma_x = soma_simples_double(size, vetor_x);
    double soma_y = soma_simples_double(size, vetor_y);
    int i;

    for (i = 0; i < size; i++){
            soma_xy += (vetor_x[i] * vetor_y[i]);
    }
    for(i = 0; i < size; i++){
        soma_x2 += (pow(vetor_x[i], 2));
    }
    a = ((size * soma_xy - soma_x * soma_y) / (size * soma_x2 - pow(soma_x, 2)));
    b = media_y - a * media_x;

    printf("\n\nRegressao Linear: ");
    printf("y = %.5lfx + %.5lf ", a, b);

}
/* FIM ESTATÍSTICA ----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* FERRAMENTAS --------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
double arredondar(double valor, int casas)
{
    /* Esta função arredonda para cima um double a apartir da quantidade de casas decimais informadas.
     * Retorna o número arredondado. */
    return ( ceil(valor * pow(10, casas)) / pow(10, casas) );
}

int quantidade_casas_decimais(int size, char vetor_string[][31])
{
    /* Esta função encontra a quantidade de casas decimais usadas no arquivo para que possa ser encontrado a amplitude das faixas de valores.
     * Tem como paramêtros a quantidade de dados da uma coluna do arquivo e um vetor de strings que armazena os dados em forma de string.
     * Retorna o número de casas decimais desse conjunto de dados. */
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
    /* Esta função verifica se uma string passada é um número, caso seja, retorna true, caso seja, ou caso não seja, falso.*/
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
    /* Esta função encontra o maior valor de um vetor e retorna seu indíce. */
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
    /* Esta função encontra o menor valor de um vetor e retorna seu indíce. */
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
    /* Somatório de um vetor de doubles. */
    int i;
    double soma = 0;

    for(i = 0; i < size; i++){
        soma += vetor[i];
    }

    return soma;
}

int soma_simples_int(int size, int vetor[])
{
    /* Somatório de um vetor de inteiros. */
    int i, soma = 0;

    for(i = 0; i < size; i++){
        soma += vetor[i];
    }

    return soma;
}

float soma_produtos(int size, float vetor_a[], int vetor_b[])
{
    /* Somatório de um vetor de float com um vetor de inteiros, sendo que são feitas multiplicações entre os elementos dos vetores. */
    int i;
    float soma = 0;

    for(i = 0; i < size; i++){
        soma += (vetor_a[i] * vetor_b[i]);
    }

    return soma;
}

int particao(double vetor[], int e, int d)
{
    /* Parte do algoritmo de quicksort */
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
    /* Parte do algoritmo de quicksort */
    double aux = *a;
    *a = *b;
    *b = aux;
}

void quick_sort(double vetor[], int e, int d)
{
    /* Algoritmo de ordenação quicksort. */
    if(e < d){
        int pi = particao(vetor, e, d);

        quick_sort(vetor, e, pi - 1);
        quick_sort(vetor, pi + 1, d);
    }
}
/* FIM FERRAMENTAS ----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
