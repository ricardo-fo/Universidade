#include <stdio.h>
#include <string.h>

int main()
{
    int maior = 0, i, cont = 0;
    char str[81];

    scanf("%80[^\n]", str);

    for(i = 0; str[i] != '\0'; i++){
        cont = 0;
        if(str[i] == ' '){
            while(str[i] == ' '){
                cont++;
                i++;
            }
        }
        if(cont > maior){
            maior = cont;
        }
    }
    printf("\nmaior = %d\n", maior);

    return 0;
}
