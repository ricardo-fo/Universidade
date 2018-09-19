#include <stdio.h>
/*This page help me with booleans issues:
https://stackoverflow.com/questions/17307275/what-is-the-printf-format-specifier-for-bool
*/

void bissexto(int *);

int main()
{
    int ano;
    scanf("%d", &ano);
    bissexto(&ano);
    printf(ano ? "true\n" : "false\n");//operador condicional ternário == if-else

    return 0;
}

void bissexto(int * ano_func)
{
    if((*ano_func % 4 == 0) && (*ano_func % 100 != 0 || *ano_func % 400 == 0))
        *ano_func = 1;
    else
        *ano_func = 0;
}
