#include <stdio.h>

int main()
{
    int dim;

    printf("Informe a dimensao da matriz quadrada: ");
    scanf("%d", &dim);

    int mat[dim][dim];
    int inca[dim][dim];

    int fim = dim-1, cont = 0, ini = 0, conf = 0, i, j;

    while(ini <= fim) {
        for(i = ini; i <= fim; i++)
        {
            cont++;
            inca[ini][i] = cont;
        }
        for(i = ini + 1; i <= fim; i++)
        {
            cont++;
            inca[i][fim] = cont;
        }
        for(i = fim -1; i > ini - 1; i--)
        {
            cont++;
            inca[fim][i] = cont;
        }
        for(i = fim-1; i >= ini + 1; i--)
        {
            cont++;
            inca[i][ini] = cont;
        }
        ini++;
        fim--;
    }
    printf("\nInforme os elementos da matriz:");
    for(i = 0; i <= dim-1; i++)
    {
        for(j = 0; j <= dim-1; j++)
        {
            printf("\nmat[%d][%d] = ",i,j);
            scanf("%d", &mat[i][j]);
            if(mat[i][j]==inca[i][j])
            {
                conf++;
            }
        }
    }
    if(conf == dim*dim)
    {
        printf("\nA matriz e' inca!");
    }else{
        printf("\nA matriz nao e' inca!");
    }
    return 0;
}
