#include <stdio.h>

int main()
{
	char nome[15];
    int i;

	printf("Informe seu nome: ");
	scanf("%14[^\n]", nome);
	/*14 = número máximo de entrada
	scanf("%14[A-Z^\n]", nome);/*
	scanf("%14[A-Za-z ]", nome);
	*/
	/*
	fgets(nome, 15, stdin);
	armazena o ENTER
	f = file,
	stdin = teclado,
	stdout = video,
	stderr = video(sem buffer)
	*/
	/*
	gets(nome);
	não há como limitar o tamanho da entrada
	função "perigosa"
	*/
	printf("Boa noite, %s!\n", nome);
	/*
	printf("Boa noite, %s!\n", &nome[5]);
	for(i = 0; nome[i] "= '\0'; i++)
    {
        printf("%c", nome[i]);
    }
	/*
    puts("Boa noite,");
    puts(nome);//FUNCIONA DA MESMA FORMA QUE O PRINTF
    puts("!")
    pula linha automaticamente*/

    /*while(getchar() != '\n');
    LIMPA O BUFFER DO TECLADO
    */
	return 0;
}
