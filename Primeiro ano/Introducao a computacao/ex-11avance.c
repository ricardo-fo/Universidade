#include <stdio.h>
#include <string.h>

int main()
{
	char str[30][61], c;
	int i, j, cont = 0;

	for(i = 0; i < 30; i += 2){
		scanf(" %60[A-Za-z]  %60[A-Za-z]", str[i], str[i+1]);
		while((c = getchar()) != '\n'){}
		cont++;
		if(str[i][0] == '\n' || str[i+1][0] == '\n'){
			cont--;
			break;
		}
	}
	for(i = 0; i < cont; i++){
		printf("%s %s\n", str[i], str[i++]);
	}
	return 0;
}
