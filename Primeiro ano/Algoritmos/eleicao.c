#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void gerarUrnas(void);/*geração de votos e urnas*/
void apura(void);/*contagem de votos*/
void mkFile(const int, char *, const char *);/*cria o nome do arquivo. número a ser colocado, nome do arquivo, extensão*/
void sortInt(long int *, long int *);/*ordenação de inteiros*/
int voto[1000000];

int main()
{
    //gerarUrnas();
    apura();
	return 0;
}
void gerarUrnas()
{
    int numeros[15] = {1, 2, 12, 13 ,15, 16, 17, 18, 19, 27, 30, 45, 50, 51, 54}, i, j;
	FILE * pin;
	srand((unsigned)time(NULL));
	for(j = 1; j < 25; j++){
        /*CRIAÇÃO DOS ARQUIVOS*/
        char arquivo[11] = "urna";
        mkFile(j, arquivo, ".bin");
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
    int j, i, k;
    long int numeros[15] = {1, 2, 12, 13 ,15, 16, 17, 18, 19, 27, 30, 45, 50, 51, 54}, storage[15], strg = 0, cont;
    char nomes[15][101] = {"Brancos", "Nulos", "Ciro Gomes (PDT)", "Fernando Haddad (PT)",
                          "Henrique Meirelles (MDB)", "Vera Lucia (PSTU)", "Jair Bolsonaro (PSL)",
                          "Marina Silva (Rede)", "Alvaro Dias (Podemos)", "Eymael (DC)",
                          "Joao Amoedo (Novo)", "Geraldo Alckmin (PSDB)", "Guilherme Boulos (PSol)",
                          "Cabo Daciolo (Patriota)", "Joao Vicente Goulart (PPL)"};
    for(j = 0; j < 15; j++){
        cont = 0;
	    for(i = 1; i < 25; i++){
            /*MONTAGEM DO NOME DOS ARQUIVOS*/
            char arquivo[11] = "urna";
            mkFile(i, arquivo, ".bin");
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
        strg += cont;
        printf("Apurando . . .\n\n");
    }
    system("cls");
    /*ORDENAÇÃO:*/
    char ch[101];
    for(i = 0; i < 15; i++){
        for(j = i; j < 15; j++){
            if(storage[i] < storage[j]){
                sortInt(&storage[i], &storage[j]);
                sortInt(&numeros[i], &numeros[j]);
                strcpy(ch, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], ch);
            }
        }
    }
    printf("\nTotal de votos: %li\n", strg);
    /*AMOSTRAGEM*/
    char dots[51] = "                                                  ";
    printf("\a\n***********************************************************************************\n");
    printf("Codigo  Candidato                                            Votos   Porcentagem\n");
    for(i = 0; i < 15; i++)
        printf("\n %02li     %s %s %07li | %.04f%% \n", numeros[i], nomes[i], &dots[strlen(nomes[i])], storage[i], (storage[i] / 24000000.0)*100);
}
void mkFile(const int num, char * file, const char * ext)
{
    char buffer[3];
    itoa(num, buffer, 10);
    strcat(file, buffer);
    strcat(file, ext);
}
void sortInt(long int * one, long int * two)
{
    long int aux;
    aux = *one;
    *one = *two;
    *two = aux;
    /*
    k = storage[i];
    storage[i] = storage[j];
    storage[j] = k;
    k = numeros[i];
    numeros[i] = numeros[j];
    numeros[j] = k;
    */
}
