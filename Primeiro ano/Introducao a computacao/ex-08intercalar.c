#include <stdio.h>
#include <string.h>

int main(){

    char a[8][21] = {'\0'}, b[8][21] = {'\0'}, c[16][21] = {'\0'};
    int i;
    /*INPUTS*/
    for(i = 0; i < 8; i++){
        scanf(" %s20", a[i]);
    }
    for(i = 0; i < 8; i++){
        scanf(" %s20", b[i]);
    }
    /*CONCATENAÇÕES*/
    for(i = 0; i < 16; i++){
        if(i % 2 == 0)
            strcat(c[i],a[i/2]);
        else
            strcat(c[i],b[i/2]);
    }
    for(i = 0; i < 16; i++){
        printf("%s", c[i]);
    }
    return 0;
}
