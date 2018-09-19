#include <stdio.h>
#include <string.h>
int main()
{
    char flor[41];
    char sufixo[] = " cheira como sapato velho";
    printf("Qual sua flor favorita? ");
    scanf("%40[^\n]", flor);
    puts(strncat(flor, sufixo, 40 - strlen(flor)));
    //puts(flor);
    return 0;
}
