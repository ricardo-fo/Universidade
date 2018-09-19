#include <stdio.h>
#include <ctype.h>
int main()
{
    char text[51];
    int A = 0, E = 0, I = 0, O = 0, U = 0, j;

    scanf("%50[^\n]", text);
    for(j = 0; text[j] != '\0'; j++){
        text[j] = tolower(text[j]);
        switch (text[j]){
        case 'a':
            A++;
            break;
        case 'e':
            E++;
            break;
        case 'i':
            I++;
            break;
        case 'o':
            O++;
            break;
        case 'u':
            U++;
        }
    }
    printf("\nHistograma:\na: ");
    for(j = 0; j < A; j++){
        printf("*");
    }
    printf(" (%d)\ne: ", A);
    for(j = 0; j < E; j++){
        printf("*");
    }
    printf(" (%d)\ni: ", E);
    for(j = 0; j < I; j++){
        printf("*");
    }
    printf(" (%d)\no: ", I);
    for(j = 0; j < O; j++){
        printf("*");
    }
    printf(" (%d)\nu: ", O);
    for(j = 0; j < U; j++){
        printf("*");
    }
    printf(" (%d)\n", U);

    return 0;
}
