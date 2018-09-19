#include <stdio.h>

void somabit(int b1, int b2, int * vaium, int * soma);
/*
*soma = b1 + b2 + *vaium;
*vaium = *soma / 2;
*soma %= 2;
*/
int main()
{
    int main_b1, main_b2, vaium, soma;

    scanf("%d %d", &main_b1, &main_b2);
    somabit(main_b1, main_b2, &vaium, &soma);
    printf("b1: %d\nb2: %d\nvaium: %d\nsoma: %d\n");

    return 0;
}

void somabit(int b1, int b2, int * vaium, int * soma)
{

}
