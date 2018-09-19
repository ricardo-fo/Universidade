#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[20][101];
    int i, j, upper_1 = 1, upper_2, cont = 0;

    for(i = 0; i < 20; i++){
   		fgets(str[i], 101, stdin);
   		cont++;
   		if(str[i][0] == '\n')
   			break;
   	}
    for(i = 0; i < cont; i++){
        for(j = 0; str[i][j] != '\0'; j++){
        	if(upper_1 == 1 && str[i][j] != ' '){
        		str[i][j] = toupper(str[i][j]);
        		upper_1 = 0;
        		upper_2 = 1;
        	}else{
        		if(upper_2 == 1 && str[i][j] != ' '){
        			str[i][j] = tolower(str[i][j]);
        			upper_1 = 1;
        			upper_2 = 0;
        		}

        	}
        }
    }
    for(i = 0; i < cont; i++)
    	puts(str[i]);

    return 0;
}
