#include <stdio.h>
#include <ctype.h>
//#include <string.h>

int main()
{
    char nome[20];
    int i, cont = 0;

    scanf("%19[^\n]", nome);
    printf("%d\n", cont);
    for(i = 0; nome[i] != '\0' ; i++)
    {
        printf("%d\n", cont);
        if(isupper(nome[i])){
            cont++;
        }
    }
    printf("Ha %d maiusculas", cont);
    return 0;
}
