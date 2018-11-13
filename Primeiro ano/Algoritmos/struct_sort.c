/*TRABALHO DE ALGORITMOS - II *
* Autor: Ricardo de Freitas   *
* 13/11/2018		      */
#include <stdio.h>  //padrão
#include <time.h>   //time_t
#include <string.h> //strings
#include <stdlib.h> //srand and rand
#include <ctype.h>	//tolower

struct sbanda{
	char name[101];
	char song[101];
	int members;
	int ranking;
};

typedef struct sbanda banda;

void swap(int vet[][5]);
void mkBin(banda bandas[5]);
void fillUser(banda bandas[5]);
void fillRandomic(banda bandas[5]);
void sort(banda bandas[5]);
void reset(banda bandas[5]);
int checkStr(const char *, banda bandas[5]);
int checkInt(int, banda bandas[5]);
void findRank(void);
void findSong(void);
void findBand(void);
void menu(banda bandas[5]);
void showAll(const banda bandas[5]);

int main()
{
	time_t t;
	register int i;
	banda bandas[5];

	srand((unsigned)time(&t));
	menu(bandas);

	return 0;
}

void menu(banda bandas[5])
{
	int choice, choice2;
	printf("--------------------------------------------------\n");
	printf("\t\tBEM-VINDO(A)\n");
	printf("--------------------------------------------------\n");
	do{
		printf("\n1 - Preencher estrutura automaticamente;\n");
		printf("2 - Preencher estrutura manualmente;\n");
		printf("3 - Mais opcoes . . .\n");
		printf("0 - Sair.\n>>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				fillRandomic(bandas);
				sort(bandas);
				mkBin(bandas);
				break;
			case 2:
				reset(bandas);
				fillUser(bandas);
				sort(bandas);
				mkBin(bandas);
				break;
			case 3:
				do{
					printf("\n4 - Achar pelo ranking;\n");
					printf("5 - Achar pelo estilo de musica;\n");
					printf("6 - Achar pelo nome da banda;\n");
					printf("7 - Mostrar tudo;\n");
					printf("0 - Retornar.\n>>> ");
					scanf("%d", &choice2);
					switch(choice2){
						case 4:
							findRank();
							break;
						case 5:
							findSong();
							break;
						case 6:
							findBand();
							break;
						case 7:
							showAll(bandas);
							break;
						case 0:
							printf("\n. . .\n");
							break;
						default:
							fprintf(stderr, "\nOops! Algo deu errado!\n");
							break;
					}
				}while(choice2 != 0);
				break;
			case 0:
				printf("\nBye :)\n");
				break;
			default:
				fprintf(stderr, "\nOpps! Algo deu errado!\n");
				break;
		}
	}while(choice != 0);
	return;
}

void fillRandomic(banda bandas[5])
{
	/*This function fill out the struct randomly to save time*/
	char list_names[5][51] = {"the beatles", "pink floyd", "chet baker",
				  "tchaikovsky", "zeca pagodinho"};
	char list_songs[5][21] = {"rock", "psicodelico", "jazz", "classico",
				  "pagode"};
	int storage[4][5] = {{0, 1, 2, 3, 4},
			     {0, 1, 2, 3, 4},
			     {1, 1, 1, 4, 4},
			     {1, 2, 3, 4, 5}};
	int i, j;

	swap(storage);
	for(i = 0; i < 5; i++){
		strcpy(bandas[i].name, list_names[storage[0][i]]);
		if(strlen(list_songs[storage[1][i]]) == 0){
			strcpy(bandas[i].song, "rock");
		}else{
			strcpy(bandas[i].song, list_songs[storage[1][i]]);
		}
		bandas[i].members = storage[2][i];
		bandas[i].ranking = storage[3][i];
	}
}

void swap(int vet[][5])
{
	/*THIS FUNCTION CHANGE THE ORIGINAL ARRAY TO MAKE A RANDOMIC ARRAY*/
	register int i, j, rnd1, rnd2, aux;

	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			rnd1 = rand() % 5;
			rnd2 = rand() % 5;
			aux = vet[j][rnd1];
			vet[j][rnd1] = vet[j][rnd2];
			vet[j][rnd2] = aux;
		}
	}
}

void fillUser(banda bandas[5])
{
	/*THIS FUNCTION MAKE A STRUCT BY THE USER WAY*/
	register int i, j;
	char nome[101], musica[101], r;
	int membros, rank;

	printf("\nPreencha as estruturas com informacoes sobre bandas:");
	for(i = 0; i < 5; i++){
		printf("\nNome 0%d: ", i+1);
		scanf(" %[^\n]s", nome);
		for(j = 0; j < strlen(nome); j++){
			nome[j] = tolower(nome[j]);
		}
		while(checkStr(nome, bandas)){
			fprintf(stderr, "\nEssa banda ja foi adicionada!\nEscolha outro nome para a banda 0%d >>> ", i+1);
			scanf(" %[^\n]s", nome);
		}
		strcpy(bandas[i].name, nome);

		printf("Musica 0%d: ", i+1);
		scanf(" %[^\n]s", musica);
		for(j = 0; j < strlen(musica); j++){
			musica[j] = tolower(musica[j]);
		}
		strcpy(bandas[i].song, musica);

		printf("Membros 0%d: ", i+1);
		scanf("%d", &membros);
		bandas[i].members = membros;

		printf("Ranking 0%d: ", i+1);
		scanf("%d", &rank);
		while(checkInt(rank, bandas) || rank < 1 || rank > 5){
			fprintf(stderr, "\nOops!\nEscolha outra posicao para a banda 0%d >>> ", i+1);
			scanf("%d", &rank);
		}
		bandas[i].ranking = rank;
	}
}

void reset(banda bandas[5])
{
	register int i;

	for(i = 0; i < 5; i++){
		strcpy(bandas[i].name, "");
		strcpy(bandas[i].song, "");
		bandas[i].members = 0;
		bandas[i].ranking = 0;
	}
}

int checkStr(const char * nome, banda bandas[5])
{
	/*THIS FUNCTION CHECKS IF A BAND NAME THERE IS IN YOUR STRUCT*/
	register int i;
	for(i = 0; i < 5; i++){
		if(!strcmp(bandas[i].name, nome))
			return 1;
	}
	return 0;
}

int checkInt(int rank, banda bandas[5])
{
	/*THIS FUNCTION CHECKS IF A BAND RANKING THERE IS IN YOUR STRUCT*/
	register int i;
	for(i = 0; i < 5; i++){
		if(bandas[i].ranking == rank)
			return 1;
	}
	return 0;
}

void sort(banda bandas[5])
{
	/*THIS FUNCTION SORTS THE STRUCT BY THE RANKING ORDER*/
	register int i, j;
	banda aux;

	for(i = 0; i < 5; i++){
		for(j = i; j < 5; j++){
			if(bandas[i].ranking > bandas[j].ranking){
				aux = bandas[i];
				bandas[i] = bandas[j];
				bandas[j] = aux;
			}
		}
	}
}

void mkBin(banda bandas[5])
{
	/*THIS FUNCTION CREATE THE BINARY FILE TO STORAGE ALL INFORMATIONS*/
	register int i;
	FILE * PB_IN; //pointer, binary, input

	if((PB_IN = fopen("storage_bands.bin", "wb")) == NULL){
		fprintf(stderr, "\nHouveram problemas ao manipular o arquivo binario!\n");
		return;
	}
	for(i = 0; i < 5; i++){
		fwrite(&bandas[i], sizeof(banda), 1, PB_IN);
	}
	fclose(PB_IN);
	return;
}

void findRank()
{
	/*THIS FUNCTION SEARCH WHETER A BAND'S RANKING EXISTS*/
	struct sbanda read[5];
	int number = 1, i, a = 1;
	FILE * PB_OUT;

	printf("\nInforme um numero do ranking (1 ate 5)\n>>> ");
	scanf("%d", &number);
	while(number > 5 || number < 1){
		fprintf(stderr, "\nApenas numeros entre 1 e 5\n>>> ");
		scanf("%d", &number);
	}
	if((PB_OUT = fopen("storage_bands.bin","rb")) == NULL){
		fprintf(stderr, "\nHouveram problemas ao manipular o arquivo binario!\n");
		return;
	}
	for(i = 0; i < 5; i++){
		fread(&read[i], sizeof(struct sbanda), 1, PB_OUT);
		if(read[i].ranking == number){
			printf("\nNome: %s\nMusica: %s\nMembro(s): %d\nRanking: %do\n\n", read[i].name, read[i].song, read[i].members, read[i].ranking);
			a = 0;
			break;
		}
	}
	if(a)
		printf("\nNao encontrado!\n");
	fclose(PB_OUT);
}

void findSong()
{
	/*THIS FUNCTION SEARCH WHETER A BAND'S SONG EXISTS*/
	struct sbanda read[5];
	int i, a = 1;
	char nome[101];
	FILE * PB_OUT;

	printf("\nInforme um tipo de musica\n>>> ");
	scanf(" %[^\n]s", nome);
	for(i = 0; i < strlen(nome); i++){
			nome[i] = tolower(nome[i]);
	}
	if((PB_OUT = fopen("storage_bands.bin","rb")) == NULL){
		fprintf(stderr, "\nHouveram problemas ao manipular o arquivo binario!\n");
		return;
	}
	for(i = 0; i < 5; i++){
		fread(&read[i], sizeof(struct sbanda), 1, PB_OUT);
		if(!strcmp(read[i].song, nome)){
			printf("\nNome: %s\nMusica: %s\nMembro(s): %d\nRanking: %do\n\n", read[i].name, read[i].song, read[i].members, read[i].ranking);
			a = 0;
		}
	}
	if(a)
		printf("\nNao encontrado!\n");
	fclose(PB_OUT);
}

void findBand()
{
	/*THIS FUNCTION SEARCH WHETER A BAND THERE IS IN MY FAVORITE LIST*/
	struct sbanda read[5];
	int i, a = 1;
	char band[101];
	FILE * PB_OUT;

	printf("\nInforme uma banda e saiba se e' uma de minhas favoritas\n>>> ");
	scanf(" %[^\n]s", band);
	for(i = 0; i < strlen(band); i++){
			band[i] = tolower(band[i]);
	}
	if((PB_OUT = fopen("storage_bands.bin","rb")) == NULL){
		fprintf(stderr, "\nHouveram problemas ao manipular o arquivo binario!\n");
		return;
	}
	for(i = 0; i < 5; i++){
		fread(&read[i], sizeof(struct sbanda), 1, PB_OUT);
		if(!strcmp(read[i].name, band)){
			printf("Sim, eu gosto de %s\n", read[i].name);
			a = 0;
		}
	}
	if(a)
		printf("\nNao esta' entre minhas bandas favoritas!\n");
	fclose(PB_OUT);
}

void showAll(const banda bandas[5])
{
	register int i;

	for(i = 0; i < 5; i++){
		printf("\nNome: %s\n", bandas[i].name);
		printf("Musica: %s\n", bandas[i].song);
		printf("Membro(s): %d\n", bandas[i].members);
		printf("Ranking: %do\n", bandas[i].ranking);
	}
}
