#include <stdio.h>
/*
Escreva uma função de protótipo void  triangulo(int  n, char  ch); que desenha no
vídeo um triângulo invertido formado por n caracteres ch em sua base. Por exemplo, se for feita
seguinte chamada a função: triangulo(7, '#');
A função deve desenhar no vídeo o seguinte triângulo:
#######
 #####
  ###
   #
*/
void tri(int, char);

int main()
{
    int n, i;
    char ch;

    scanf("%d %c", &n, &ch);
    while(n % 2 == 0){
        printf("\nInforme um número impar: ");
        scanf("%d", &n);
    }
    tri(n, ch);

    return 0;
}

void tri(int x, char c)
{
    int i, j;

    for(i = n; i < (n + 1) / 2; i--)
    {
        printf("%c");
    }

}
