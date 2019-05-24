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
#include <stdio.h> // utilizacao: inptus e outputs.
#include <ctype.h> // utilizacao: isdigiy();
#include <stdlib.h> // fprintf(); fscanf();

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
    char opcao;

    // Menu principal.
    do{
        printf("\nInforme o numero de uma das opcoes abaixo para fazer a acao desejada:");
        printf("\n<1> Inserir nome de arquivo que possua os dados;");
        printf("\n<2> Criar arquivo e seus dados;");
        printf("\n<0> Sair.");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);
        while((getchar()) != '\n'); // Eliminação de digitos em excesso (limpar o buffer).

        char nome_arquivo[101];

        switch(opcao){
            case '1':
                // Utilização de padrão visual: pontos(.) para divisão opcções do menu.
                printf("\n......................................................................................................\n");
                printf("\nInforme o nome do arquivo junto a sua extensao.");
                printf("\nExemplo: meu_arquivo.txt\n");
                printf("\nNome do arquivo:");
                scanf(" %100[^\n]s", nome_arquivo);
                while((getchar() != '\n'));

                // printf("\nSeu arquivo: %s\n", nome_arquivo); // Apenas para testar se o input foi realizado com sucesso.
                FILE * p_arquivo; // ponteiro para abrir o arquivo.
                if((p_arquivo = fopen(nome_arquivo, "r")) == NULL){
                    // Validação do arquivo passado.
                    // Utilização de padrão visual: asteriscos(*) para mensagens de erros.
                    printf("\n******************************************************************************************************");
                    fprintf(stderr, "\nErro: Arquivo '%s' nao foi encontrado ou nao pode ser aberto.", nome_arquivo);
                    printf("\n******************************************************************************************************");
                    fclose(p_arquivo);
                } else {
                    /*
                        --> CONTINUAR DAQUI <--
                    */
                    printf("\ntudo ok\n");
                }
                printf("\n......................................................................................................\n");
                break;
            case '2':
                // Utilização de padrão visual: pontos(.) para divisão opções do menu.
                printf("\n......................................................................................................\n");
                printf("\nOpcao 2:");
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
