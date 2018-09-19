#include <stdio.h>
#include <string.h>

int main()
{
    char a[81] = {'\0'}, b[81] = {'\0'};
    int i = 0;

    scanf("%80[^\n]", a);
    scanf(" %80[^\n]", b);

    char c[161] = {'\0'};

    while(i < strlen(a) + strlen(b)){
        if(strlen(a) == strlen(b)){
            if(i % 2 == 0)
                c[i] = a[i/2];
            else
                c[i] = b[i/2];

        }else{
            if(strlen(a) > strlen(b)){
                if(i % 2 == 0 || b[i/2] == '\0')
                    c[i] = a[i/2];
                else
                    c[i] = b[i/2];
            }
            if(strlen(a) < strlen(b)){
                if(i % 2 != 0 || a[i/2] == '\0')
                    c[i] = b[i/2];
                else
                    c[i] = a[i/2];
            }
        }
        i++;
    }
    printf("\n%s\n", c);
    return 0;
}
