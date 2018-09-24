#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void gerarUrnas(void);
void apura(void);
int voto[1000000];

int main()
{
    gerarUrnas();
    apura();
	return 0;
}
void gerarUrnas()
{
    int numeros[15] = {1, 2, 12, 13 ,15, 16, 17, 18, 19, 27, 30, 45, 50, 51, 54};
	int i, j;
	FILE * pin;
	srand((unsigned)time(NULL));
	for(j = 0; j < 24; j++){
        /*CRIAÇÃO DOS ARQUIVOS*/
        char arquivo[11] = "urna";
        char buffer[20];
	    itoa(j,buffer,10);
	    strcat(arquivo, buffer);
	    strcat(arquivo, ".bin");
        pin = fopen(arquivo, "wb");
        /*GERAÇÃO DOS VOTOS*/
        for(i = 0; i < 1000000; i++){
            voto[i] = numeros[(rand() % 15)];
        }
        fwrite(voto, sizeof(int), 1000000, pin);
        fclose(pin);
        printf("Computando os votos . . .\n\n");
	}
    system("cls");
}

void apura()
{
    FILE * pout;
    int numeros[15] = {1, 2, 12, 13 ,15, 16, 17, 18, 19, 27, 30, 45, 50, 51, 54};
    int storage[15];
    char nomes[15][101] = {"Brancos", "Nulos", "Ciro Gomes (PDT)", "Fernando Haddad (PT)",
                          "Henrique Meirelles (MDB)", "Vera Lucia (PSTU)", "Jair Bolsonaro (PSL)",
                          "Marina Silva (Rede)", "Alvaro Dias (Podemos)", "Eymael (DC)",
                          "Joao Amoedo (Novo)", "Geraldo Alckmin (PSDB)", "Guilherme Boulos (PSol)",
                          "Cabo Daciolo (Patriota)", "Joao Vicente Goulart (PPL)"};
    int j, i, k, cont, aux;
    for(j = 0; j < 15; j++){
        cont = 0;
	    for(i = 0; i < 24; i++){
            /*MONTAGEM DO NOME DOS ARQUIVOS*/
            char arquivo[11] = "urna";
            char buffer[20];
            itoa(i,buffer,10);
            strcat(arquivo, buffer);
            strcat(arquivo, ".bin");
            /*LEITURA DOS VOTOS*/
            pout = fopen(arquivo, "rb");
            fread(voto, sizeof(int), 1000000, pout);
            fclose(pout);
            /*CONTAGEM DOS VOTOS*/
            for(k = 0; k < 1000000; k++){
                if(voto[k] == numeros[j])
                    cont++;
            }
	    }
        storage[j] = cont;
        printf("Apurando . . .\n\n");
    }
    system("cls");
    /*ORDENAÇÃO:*/
    char ch[101];
    for(i = 0; i < 15; i++){
        for(j = 0; j < 15; j++){
            if(storage[i] < storage[j]){
                aux = storage[i];
                storage[i] = storage[j];
                storage[j] = aux;
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
                strcpy(ch, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], ch);
            }
        }
    }
    /*AMOSTRAGEM*/
    char dots[51] = "                                                  ";
    printf("\a\n***********************************************************************************\n");
    printf("Codigo  Candidato                                            Votos   Porcentagem\n");
    for(i = 14; i >= 0; i--)
        printf("\n %02d     %s %s %d | %.04f%% \n", numeros[i], nomes[i], &dots[strlen(nomes[i])], storage[i], (storage[i] / 24000000.0)*100);
}
