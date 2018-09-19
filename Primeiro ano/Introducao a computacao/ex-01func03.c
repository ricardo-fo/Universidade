/*
Escreva uma função que receba um vetor de inteiros de n elementos e troque o 1º
elemento pelo último, o 2º pelo penúltimo, o 3º pelo antepenúltimo, e assim
sucessivamente. Escreva um programa que leia um vetor de inteiros de n elementos,
utilize a função para inverter a ordem dos elementos do vetor e depois mostre o vetor
*/
#include <stdio.h>
#include <string.h>
void reverse(char * func_str);

int main()
{
    char str[101];
    scanf("%100[^\n]", str);
    reverse(str);
    printf("%s\n", str);

    return 0;
}
void reverse(char * func_str)
{
    int i, j;
    char aux[strlen(func_str)];
    for(i = 0, j = strlen(func_str) - 1; func_str[i] != '\0'; i++, j--){
        //printf("func_str[%d](%c) = aux[%d](%c)\n",i,func_str[i],j,aux[j]);
        aux[j] = func_str[i];
    }
    aux[i] = '\0';
    strcpy(func_str,aux);
}
