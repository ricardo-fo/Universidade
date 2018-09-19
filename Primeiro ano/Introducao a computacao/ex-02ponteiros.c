/*
Criar uma função em C que receba um número binário e converta-o para decimal.
Obs.: O parâmetro passado na chamada à função deve ser alterado para decimal.
*/
#include <stdio.h>

void bin_dec(float *, int);

int main()
{
	float bin;
	int int_bin_main;

	scanf("%f", &bin);
	int_bin_main = (int)bin;
	bin_dec(&bin, bin);
	printf("%.0f\n", bin);

	return 0;
}

void bin_dec(float * bin_func, int int_bin)
{
	int dec = 0, pot2 = 1;

	while(int_bin > 0){
		dec += (int_bin % 10) * pot2;
		int_bin /= 10;
		pot2 *= 2;
	}
	*bin_func = dec;
}
