/* 
Faça um programa em Linguagem C que gere 100.000 caracteres aleatórios e grave em um arquivo texto.
Caracteres válidos: A-Z, a-z, 0-9;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE * pin;
    char alfa[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char grava;
    int lenght, i, carac;

    pin = fopen("grava.txt", "w");
    lenght = strlen(alfa);
    srand( (unsigned)time(NULL) );

    for(i = 0; i < 100000; i++){
        carac = rand() % lenght;
        grava = alfa[carac];
        fprintf(pin,"%c", grava);
    }
    fclose(pin);
    return 0;
}
