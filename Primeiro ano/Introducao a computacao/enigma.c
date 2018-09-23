#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool eh_possivel(int, const char *, const char *);

int main()
{
	char msg[10001], crb[10001];
	scanf(" %10000[A-Z]", msg);
	scanf(" %10000[A-Z]", crb);
	int i, lim = strlen(msg) - strlen(crb) + 1, cont = 0;
	for(i = 0; i < lim; i++){
		if(eh_possivel(i, msg, crb))
			cont++;
	}
	printf("%d\n", cont);

	return 0;
}

bool eh_possivel(int index, const char * mensagem, const char * crib)
{
	int j;
	for(j = 0; crib[j] != '\0'; index++, j++){
		if(mensagem[index] == crib[j])
			return false;
	}
	return true;
}
