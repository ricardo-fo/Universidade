#include <stdio.h>
#include <string.h>

int main(){
    char nomes[3][21], copia[61] = {'\0'};
    int i;

    for(i = 0; i < 3; i++)
        scanf(" %s20", nomes[i]);

    for(i = i - 1; i >= 0; i--)
        strcat(copia, nomes[i]);

    printf("\n%s\n", copia);

    return 0;
}
