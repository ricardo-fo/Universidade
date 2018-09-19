#include <stdio.h>
#include <string.h>

int main()
{
    char text[81] = {'\0'};
    int i, j, logico = 0, a;

    scanf("%80[^\n]", text);
    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = tolower(text[i]);
        if(text[i] == ' ')
        {
            for(j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j+1];
            }
        }
    }
    for(i = 0, j = strlen(text) - 1; i <= strlen(text)/2; i++, j--)
    {
        if(text[i] == text[j])
        {
            logico = 1;
        }else{
            break;
        }
    }
    if(logico)
    {
        printf("\nE' um palindromo\n");
    }else{
        printf("\nNao e' palindromo\n");
    }
    return 0;
}
