#include <stdio.h>
#include <string.h>
/*
Escreva uma função que receba uma string e substitua cada segmento de dois ou mais espaços em branco por um só caracter ' '.
*/
int main()
{
    char str[301];
    int i, j, k, cont = 0;

    scanf("%300[^\n]", str);
    for(i = 0; str[i] != '\0'; i++){
        cont = 0;
        if(str[i] == ' '){/*PROCURA POR ESPAÇOS*/
            for(j = i; str[j] == ' '; j++){/*CONTA QUANTOS ESPAÇOS SEGUIDOS TEM*/
                cont++;
            }
            if(cont > 1){/*SE TIVER MAIS DE 1 ESPAÇO, ENTÃO PRECISO OS RETIRAR*/
                for(k = i + 1; str[k] != '\0'; k++, j++){/*PEGA O ÍNDICE DO PRÓXIMO CARACTERE APÓS O ÚLTIMO ESPAÇO E COPIA O QUE TEM EM DIANTE PARA O ÍNDICE DO 2 ESPAÇO EM DIANTE*/
                    str[k] = str[j];
                }
            }
        }
    }
    printf("\n%s\n", str);
    return 0;
}
