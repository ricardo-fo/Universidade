#include <stdio.h>

void ret(int, int);


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    ret(a, b);

    return 0;
}

void ret(int x, int y)
{
    int i, j;

    for(i = 0; i < x; i++){
        printf("*");
        for(j = 1; j < y; j++){
            printf("*");
        }
        printf("\n");
    }
}

