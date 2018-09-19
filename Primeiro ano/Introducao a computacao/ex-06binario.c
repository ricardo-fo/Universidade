#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char num[11];
    int i, j, pot2 = 1, dec = 0;
    unsigned long int bin = 0;

    printf("Digite um numero de ate 10 digitos: ");
    scanf("%s10", num);

    //for(i = 0; num[i] != '\0'; i++){}
    i = strlen(num) - 1;
    for(j = 0; i >= 0; i--, j++){/*TRANSFORMA A STRING PARA UMA VARIÁVEL INTEIRA*///--> EM ALGUNS CASOS DOIS LAÇOS NÃO FUNCIONAM
        if(num[j] == '1')
            bin = bin + trunc(pow(10,i));/*COMO POW DEVOLVE DOUBLE, TIRO A PARTE APÓS A VÍRGULA PARA VIRAR INTEIRO*/
    }
    while (bin > 0) {/*CONVERTE A VARIÁVEL INTEIRA PARA BASE DECIMAL*/
		dec += (bin % 10) * pot2;
		bin /= 10;
		pot2 *= 2;
	}
	printf("\n%d\n", dec);
    return 0;
}
