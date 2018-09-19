/*
Criar uma função em C que receba um número decimal e converta-o para binário. 
Obs.: O parâmetro passado na chamada à função deve ser alterado para binário. 
*/

#include <stdio.h>
#include <math.h>

void dec_bin(int *, int);

int main()
{
	int decimal;

	scanf("%d", &decimal);
	dec_bin(&decimal, decimal);
	printf("%d\n", decimal);

	return 0;
}
void dec_bin(int * func_decimal, int value_func_decimal)
{
	int storage = 1, cont = 0, num = value_func_decimal;
	while(value_func_decimal > 0)
	{
		value_func_decimal = (value_func_decimal - value_func_decimal % 10)/10;
		cont++; 
	}
	storage = (num % 2) * pow(10, cont);
	printf("storage = %d\nnum % 2 = %d\npow(10, %d) = %d\n", storage, num % 2, cont, pow(10, cont));
	/*func_decimal = storage;*/
}