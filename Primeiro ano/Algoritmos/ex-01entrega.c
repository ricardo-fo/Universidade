#include <stdio.h>
/*
Faça um programa em Linguagem C que receba do usuário um arquivo texto, e mostre na tela quantas linhas esse arquivo possui.
Considere o ‘\n’ como terminador de linha;
*/

int main()
{
    FILE * pin;
    char linha;
    int cont = 1;
    if(!(pin = fopen("entrada.txt","r")))
    {
        printf("Erro!");
        exit(1);
    }
    while(!feof(pin)){
        fscanf(pin, "%c", &linha);
        //printf("linha = %c\n", linha);
        if(linha == '\n')
            cont++;
    }
    printf("%d\n", cont);
    fclose(pin);

    return 0;
}
