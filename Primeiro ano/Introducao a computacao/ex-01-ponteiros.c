/*
Para cada uma das sentenças seguintes escreva uma instrução que realize a
tarefa indicada. Admita que as variáveis do tipo float, numero1 e
numero2, foram declaradas e numero1 foi inicializada com o valor 7.3.
a) Declare a variável fptr como ponteiro para uma variável do tipo
float;
b) Atribua o endereço da variável numero1 ao ponteiro fptr;
c) Imprima o valor da variável apontada por fptr usando o ponteiro;
d) Atribua o valor da variável apontada por fptr à variável numero2;
e) Imprima o valor de numero2;
f) Imprima o endereço de numero1;
g) Imprima o endereço armazenado em fptr.
*/

#include <stdio.h>

int main()
{
	float numero1 = 7.3, numero2, * fptr;

	fptr = &numero1;
	printf("valor da variavel apontada por fptr usando o ponteiro = %f\n", *fptr);
	numero2 = *fptr;
	printf("numero2 = %f\n", numero2);
	printf("endereco de numero1 = %p\n", &numero1);
	printf("endereco armazenado em fptr = %p\n", fptr);

	return 0;
}
