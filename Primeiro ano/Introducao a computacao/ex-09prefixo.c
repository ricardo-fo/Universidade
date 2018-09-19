#include <stdio.h>
#include <string.h>

int main()
{
    int n, i = 0;
    char a[7];

    scanf("%d %s", &n, &a);

    char word[n][21];
    while(i < n){
        scanf("%s20", word[i]);
        while(strncmp(word[i],a,1)){/*SÓ FUNCIONA COM STRINGS*//*STRCASECMP COMPARA AS STRINGS IGNORA O CASE SENSITIVE*/
            printf("\nYOUR WORD DOES NOT BEGIN WITH \"%s\"\nTRY AGAIN:\n", a);
            scanf("%s20", word[i]);
        }
        i++;
    }
    printf("\n");
    for(i = 0; i < n; i++){
        if(strncmp(word[i],a,1) == 0)
            printf("%s\n",word[i]);
    }

    return 0;
}
