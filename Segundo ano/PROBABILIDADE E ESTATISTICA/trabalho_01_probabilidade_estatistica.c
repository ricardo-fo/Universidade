/*
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
//#include <ctype.h> // uso: isdigit();
#include <stdlib.h> // uso: fprintf(); fscanf();
#include <string.h> // uso: strcat(); strcmp(); strrchr(); strtok();
#include <stdbool.h> // uso: true e false;

// Esta funcao deve identificar o caractere que separa a colunas do arquivo passado.
// Retorno: caractere de separacao usado.
char get_separate_symbol(FILE *);

int main()
{
    printf("Bem-vindo(a).\n");
    printf("\nEste programa coleta dados de um arquivo .txt e, em seguida, baseados nos dados, calcula ou informa:");
    printf("\n* A frequencia de cada conjunto de dados;");
    printf("\n* A estimativa da moda;");
    printf("\n* A estimativa da media;");
    printf("\n* O desvio padrao;");
    printf("\n* A estimativa dos valores do box-plot;");
    printf("\n* Os coeficientes de Pearson e da reta de minimos quadrados.");
    // Utilização de padrão visual: traços(-) para divisão da mensagem inicial.
    printf("\n------------------------------------------------------------------------------------------------------\n");

    // Variáveis que serão utilizadas no menu
    char opcao, buffer;
    FILE * p_arquivo; // ponteiro para abrir o arquivo.
    int i, qntdd_dados;
    double col_01, col_02;

    // Menu principal.
    do{
        printf("\nInforme o numero de uma das opcoes abaixo para fazer a acao desejada:");
        printf("\n<1> Inserir nome de arquivo que possua os dados;");
        printf("\n<2> Criar arquivo e seus dados;");
        printf("\n<0> Sair.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        while((getchar()) != '\n'); // Eliminação de digitos em excesso (limpar o buffer).

        char nome_arquivo[101], novo_arquivo[101], separador = ',', * extensao;

        switch(opcao){
            case '1':
                // Utilização de padrão visual: pontos(.) para divisão opcções do menu.
                printf("\n......................................................................................................\n");
                printf("\nInforme o nome do arquivo junto a sua extensao.");
                printf("\nExemplo: meu_arquivo.txt\n");
                printf("\nNome do arquivo: ");
                scanf(" %100[^\n]", nome_arquivo);
                while((buffer = getchar() != '\n'));

                if((p_arquivo = fopen(nome_arquivo, "r")) == NULL){
                    // Validação do arquivo passado.
                    // Utilização de padrão visual: asteriscos(*) para mensagens de erros.
                    printf("\n******************************************************************************************************");
                    fprintf(stderr, "\nErro: Arquivo '%s' nao foi encontrado ou nao pode ser aberto.", nome_arquivo);
                    printf("\n******************************************************************************************************");
                    fclose(p_arquivo);
                    break;
                }
                int j = 0, size;
                i = 0;
                char linha[22], * token, separador_str[2];

                printf("\nSeparador: ");
                scanf(" %1s", separador_str);
                while((buffer = getchar()) != '\n');

                double vet_a[10] = {[0] = 0}, vet_b[10] = {[0] = 0};

                while(fgets(linha, 22, p_arquivo) != NULL){
                    //printf("\n%s", linha);
                    token = strtok(linha, separador_str);
                    if(token == NULL){
                        fprintf(stderr, "\nERRO: '%s' usa mais de um tipo de delimitador ou o delimitador passado nao corresponde aos do arquivo.\n", nome_arquivo);
                        return -1;
                    }

                    vet_a[i++] = atof(token);
                    printf("\nvet_a[%d] = %lf", i-1, vet_a[i-1]);

                    token = strtok(NULL, separador_str);
                    if(token == NULL){
                        fprintf(stderr, "\nERRO: '%s' usa mais de um tipo de delimitador ou o delimitador passado nao corresponde aos do arquivo.\n", nome_arquivo);
                        return -1;
                    }
                    vet_b[j++] = atof(token);
                    printf("\nvet_b[%d] = %lf", j-1, vet_b[j-1]);
                }

                /*for(i = 0; i < 10; i++){
                    printf("\n%lf", vet_a[i]);
                }
                printf("\n");
                for(i = 0; i < 10; i++){
                    printf("\n%lf", vet_b[i]);
                }*/

                printf("\n......................................................................................................\n");
                break;
            case '2':
                // Utilização de padrão visual: pontos(.) para divisão opções do menu.
                printf("\n......................................................................................................\n");
                printf("\nNome do novo arquivo: ");
                scanf("%100[^\n]", novo_arquivo);

                extensao = strrchr(novo_arquivo, '.');
                if(extensao == NULL){
                    strcat(novo_arquivo, ".txt");
                } else {
                    if(strcmp(extensao, ".txt") != 0){
                        strcat(novo_arquivo, ".txt");
                    }
                }

                if((p_arquivo = fopen(novo_arquivo, "w")) == NULL){
                    // Validação do arquivo passado.
                    // Utilização de padrão visual: asteriscos(*) para mensagens de erros.
                    printf("\n******************************************************************************************************");
                    fprintf(stderr, "\nErro: Arquivo '%s' nao foi encontrado ou nao pode ser aberto.", novo_arquivo);
                    printf("\n******************************************************************************************************");
                    fclose(p_arquivo);
                    break;
                }

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
                    scanf("%lf %lf", &col_01, &col_02);
                    fprintf(p_arquivo, "%lf%c%lf%c", col_01, separador, col_02, '\n');
                }
                fclose(p_arquivo);

                printf("\nSeu arquivo foi criado com sucesso.\n");
                printf("\n......................................................................................................\n");
            case '0':
                break;
            default:
                // Utilização de padrão visual: asteriscos(*) para mensagens de erros.
                printf("\n******************************************************************************************************");
                fprintf(stderr, "\nErro: Opcao '%c' invalida. Digite apenas opcoes validas.", opcao);
                printf("\n******************************************************************************************************");
        } // Fecha switch(opcao)
    } while(opcao != '0'); // fecha menu

    printf("\n");

    return 0;
}

/*
char get_separate_symbol(FILE * p_arquivo)
{

}
*/

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
