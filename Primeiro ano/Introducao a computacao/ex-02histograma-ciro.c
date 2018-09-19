#include <stdio.h>
#include <ctype.h>

int main()
{
    int cont[5] = {0}, i, j;
    char text[81], /*vowel[] = {'a', 'e', 'i', 'o', 'u'},*/ ch;
    char * vowel = "aeiou";

    printf("Informe uma palavra: ");
    scanf("%80[^\n]", text);

    for(i = 0; text[i] != '\0'; i++)
    {
        ch = tolower(text[i]);
        for(j = 0; j < 5; j++)
        {
            if(ch == vowel[j])
            {
                cont[j]++;
                break;
            }
        }
    }
    printf("\nHistograma:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%c: ", vowel[i]);
        for(j = 1; j <= cont[i]; j++)
        {
            printf("*");//putchar('*'); --> aceitar só um caracter como argumento
        }
        printf(" (%d)\n", cont[i]);
    }

    return 0;
}
