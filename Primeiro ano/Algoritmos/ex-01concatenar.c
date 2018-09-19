#include <stdio.h>
#include <string.h>

int main()
{
    char a[101], b[101], c[101], d[101], e[401];

    scanf("%100[^\n]", a);
    scanf(" %100[^\n]", b);
    scanf(" %100[^\n]", c);
    scanf(" %100[^\n]", d);
    strcat(e,a);
    strcat(e,b);
    strcat(e,c);
    strcat(e,d);
    puts(e);

    return 0;
}
