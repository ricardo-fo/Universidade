/* pivot_algoritmo.c
 *
 * Este programa executa o pivotamento de um sistema e encontra a solução para as variáveis apresentadas.
 * Autor: Ricardo de F. Oliveira.
 * Autor: Vitor Kuribara.
 * Curso: Ciência da Computação.
 * Disciplina: Cálculo Numérico.
 * Profº.: Júlio César.
 * Universidade Católica de Santos - Maio de 2019.
*/

#include <stdio.h>

void pivotamento(int, float matriz[][*]);

int main()
{
    int n, i, j;

    printf("Informe a da matriz.\n>>> ");
    scanf("%d", &n);

    // col+1 representa a última coluna da matriz, que será usada para manter as soluções das equações.
    float sistema[n][n+1];

    // Leitura do sistema (constantes)
    printf("\nInsira suas equacoes utilizando espacos entre os valores.");
    printf("\nExemplo (4 variaveis): 2 1 -3 4");
    printf("\nValores por equacao: %d.\n", n + 1);
    for(i = 0; i < n; i++){
        printf("\nEquacao %02d:\n", i + 1);
        for(j = 0; j < n + 1; j++){
            scanf("%f", &sistema[i][j]);
        }
    }

    // Verificação do armazenamento do sistema numa matriz
    printf("\n-------------------------------");
    printf("\nSeu sistema:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%.3f%c ", sistema[i][j], 123 - n + j);
        }
        printf(" = %.3f\n", sistema[i][j++]);
    }
    pivotamento(n, sistema);

    return 0;
}

void pivotamento(int n, float matriz[][n + 1])
{
    int i, j, k;
    float pivo, aux[n], soma = 0;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j > i){
                pivo = matriz[j][i] / matriz[i][i];
                for(k = 0; k < n + 1; k++){
                    matriz[j][k] = matriz[j][k] - (pivo * matriz[i][k]);
                }
            }
        }
    }
    printf("\n-------------------------------");
    printf("\nSistema apos o pivotamento:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%.3f%c ", matriz[i][j], 123 - n + j);
        }
        printf(" = %.3f\n", matriz[i][j++]);
    }

    printf("\n-------------------------------");
    printf("\nSolucao:\n");
    aux[n - 1] = matriz[n - 1][n] / matriz[n - 1][n - 1];
    for(i = n - 1; i >= 0; i--){
        soma = 0;
        for(j = i + 1; j < n; j++){
            soma += matriz[i][j] * aux[j];
        }
        aux[i] = (matriz[i][n] - soma) / matriz[i][i];
    }

    for(i = 0; i < n; i++){
        printf("%c = %.3f\n", 123 - n + i, aux[i]);
    }
}
