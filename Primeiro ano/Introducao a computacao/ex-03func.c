#include <stdio.h>

void maior(int, int, int);

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    maior(a, b, c);

    return 0;
}

void maior(int x, int y, int z)
{
    int greatest = 0;

    if(x > y){
        greatest = x;
        if(z > greatest)
            greatest = z;
    }else{
        greatest = y;
        if(z > greatest)
            greatest = z;
    }
    printf("%d\n", greatest);
}
