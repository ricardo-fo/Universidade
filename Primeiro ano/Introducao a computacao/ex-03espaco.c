#include <stdio.h>

int main()
{
    char text[81] = {'\0'};
    int i, j;

    scanf("%80[^\n]", text);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == ' ')
        {
            for(j = i; text[j] != '\0'; j++)
            {
                text[j] = text[j+1];
            }
        }
    }
    for(i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
    }

    printf("\n");
    return 0;
}
