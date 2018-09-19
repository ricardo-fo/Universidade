/*Nicholas Meirinho Perez : 3699232
  Arthur Silveira Chaves : 6729738
  Ricardo de Freitas Oliveira: 5934078
*/
#include <stdio.h>

int main()
{
    int alunos, i, cont;
    float nota, media;

    for(;;){
        cont = 0;
        scanf("%d", &alunos);
        if(alunos == 0) break;
        scanf("%f", &media);

        for(i = 1; i <= alunos; i++){
            scanf("%f", &nota);
            if(nota < media){
                cont++;
            }
        }
        printf("%d/%d\n\n", cont, alunos);
    }
    return 0;
}
