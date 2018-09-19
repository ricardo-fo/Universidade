#include <stdio.h>
#include <string.h>

int main()
{
    char str[51], vowel[] = {'a', 'e', 'i', 'o', 'u'};
    int i, j = 0, k, confirma;
    scanf("%50s", str);
    char copy[strlen(str)];

    for(i = 0; str[i] != '\0'; i++){
        for(k = 0; k < 5; k++){
            if(str[i] == vowel[k]){
                copy[j++] = vowel[k];
            }
        }
    }
    copy[j] = '\0';

    for(i = 0, j = strlen(copy) - 1; i <= j; i++, j--){
        if(copy[i] == copy[j]){
            confirma = 1;
        }else{
            confirma = 0;
        }
    }
    if(confirma == 1){
        printf("S\n");
    }else{
        printf("N\n");
    }
    return 0;
}
