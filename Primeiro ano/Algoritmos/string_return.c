#include <stdio.h>
#include <string.h>

const char * funcao(char * func_str, int);//prototipo

int main()
{
	char str[51], novo[51] = "teste";

	printf("%s\n", novo);
	scanf("%50[^\n]", str);
	strcpy(novo, funcao(str, 10));
	printf("\n%s\n", novo);

	return 0;
}

const char * funcao(char * func_str, int num)
{

	return func_str;
}
