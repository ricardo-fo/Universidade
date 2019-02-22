#include <stdio.h>

void calcular(float, float, char);

int main()
{
	float num1, num2;
	char op;

	printf("Modelo:\nnúmero operação número\nExemplo:1 + 2\n\n>>> ");
	// Não detectar como algo diferente de char é um erro de confiabilidade
	scanf("%f %c %f", &num1, &op, &num2);

	calcular(num1, num2, op);

	return 0;
}

void calcular(float num1, float num2, char op)
{
	// Busca pela operação passada
	switch(op){
		case '+':
			printf(">>> %.3f\n", num1 + num2);
			break;
		case '-':
			printf(">>> %.3f\n", num1 - num2);
			break;
		case '*':
			printf(">>> %.3f\n", num1 * num2);
			break;
		case '/':
			// Exceção: divisão por zero
			if(!num2) op = '.';
			else {
				printf(">>> %.3f\n", num1 / num2);
				break;
			}
		default:
			printf("Operação inválida!\n");
	}
}
