#include <stdio.h>  //padrão
#include <time.h>   //time_t
#include <string.h> //strings
#include <stdlib.h> //srand and rand
#include <ctype.h>	//tolower
#define FIVE 5

struct sbanda{
	char name[101], song[101];
	int members, ranking;
};
typedef struct sbanda banda;

void swap(int vet[][FIVE]);
int mkBin(banda bandas[FIVE]);
void fillUser(banda bandas[FIVE]);
void fillRandomic(banda bandas[FIVE]);
void sort(banda bandas[FIVE]);
void sortMember(banda * one, banda * two);
int checkStr(const char *, banda bandas[FIVE]);
int checkInt(int, banda bandas[FIVE]);
void findRank(void);
void findSong(void);
void findBand(void);

int main()
{
	time_t t;
	register int i;
	banda bandas[FIVE];

	srand((unsigned)time(&t));
	fillRandomic(bandas);
	//fillUser(bandas);
	sort(bandas);
	findRank();
	findSong();
	findBand();
	for(i = 0; i < FIVE; i++){
		printf("Nome: %s\n", bandas[i].name);
		printf("Musica: %s\n", bandas[i].song);
		printf("Membro(s): %d\n", bandas[i].members);
		printf("Ranking: %do\n\n", bandas[i].ranking);
	}

	if(mkBin(bandas)){
		fprintf(stderr, "\nHouveram problemas ao manipular o arquivo binario!\n");
		return 1;
	}

	return 0;
}

void fillRandomic(banda bandas[FIVE])
{
	/*This function fill out the struct randomly to save time*/
	char list_names[FIVE][51] = {"the beatles", "pink floyd", "chet baker",
							     "tchaikovsky", "zeca pagodinho"};
	char list_songs[FIVE][21] = {"rock", "psicodelico", "jazz", "classico",
					   		     "pagode"};
	int storage[4][FIVE] = {{0, 1, 2, 3, 4},
						    {0, 1, 2, 3, 4},
						    {1, 1, 1, 4, 4},
						    {1, 2, 3, 4, 5}};
	int i, j;

	swap(storage);

	for(i = 0; i < FIVE; i++){
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

void swap(int vet[][FIVE])
{
	/*THIS FUNCTION CHANGE THE ORIGINAL ARRAY TO MAKE A RANDOMIC ARRAY*/
	register int i, j, rnd1, rnd2, aux;

	for(i = 0; i < 4; i++){
		for(j = 0; j < FIVE; j++){
			rnd1 = rand() % FIVE;
			rnd2 = rand() % FIVE;
			aux = vet[j][rnd1];
			vet[j][rnd1] = vet[j][rnd2];
			vet[j][rnd2] = aux;
		}
	}
}

void fillUser(banda bandas[FIVE])
{
	/*THIS FUNCTION MAKE A STRUCT BY THE USER WAY*/
	register int i, j;
	char nome[101], musica[101], r;
	int membros, rank;

	printf("Preencha as estruturas com informacoes sobre bandas:\n");
	for(i = 0; i < 5; i++){
		printf("\nNome da banda 0%d >>> ", i+1);
		scanf(" %[^\n]s", nome);
		for(j = 0; j < strlen(nome); j++){
			nome[j] = tolower(nome[j]);
		}
		while(checkStr(nome, bandas)){
			fprintf(stderr, "\nEssa banda ja foi adicionada!\nEscolha outro nome para a banda 0%d >>> ", i);
			scanf(" %[^\n]s", nome);
		}	
		strcpy(bandas[i].name, nome);

		printf("\nTipo de musica da banda 0%d >>> ", i+1);
		scanf(" %[^\n]s", musica);
		for(j = 0; j < strlen(musica); j++){
			musica[j] = tolower(musica[j]);
		}
		strcpy(bandas[i].song, musica);

		printf("\nQuantidade de membros da banda 0%d >>> ", i+1);
		scanf("%d", &membros);
		bandas[i].members = membros;

		printf("\nPosicao do ranking da banda 0%d >>> ", i+1);
		scanf("%d", &rank);
		while(checkInt(rank, bandas) || rank < 1 || rank > 5){
			fprintf(stderr, "\nOops!\nEscolha outra posicao para a banda 0%d >>> ", i+1);
			scanf("%d", &rank);
		}
		bandas[i].ranking = rank;
	}
}

int checkStr(const char * nome, banda bandas[FIVE])
{
	/*THIS FUNCTION CHECKS IF A BAND NAME THERE IS IN YOUR STRUCT*/
	register int i;
	for(i = 0; i < 5; i++){
		if(!strcmp(bandas[i].name, nome))
			return 1;
	}
	return 0;
}

int checkInt(int rank, banda bandas[FIVE])
{
	/*THIS FUNCTION CHECKS IF A BAND RANKING THERE IS IN YOUR STRUCT*/
	register int i;
	for(i = 0; i < 5; i++){
		if(bandas[i].ranking == rank)
			return 1;
	}
	return 0;
}

void sort(banda bandas[FIVE])
{
	/*THIS FUNCTION SORTS THE STRUCT BY THE RANKING ORDER*/
	register int i, j;

	for(i = 0; i < 5; i++){
		for(j = i; j < 5; j++){
			if(bandas[i].ranking > bandas[j].ranking)
				sortMember(&bandas[i], &bandas[j]);
		}
	}
}

void sortMember(banda * one, banda * two)
{
	/*THIS FUNCTION CHANGES STRUCT LINES*/
	char str[strlen(one->name)];
	register int aux;

	strcpy(str, one->name);
	strcpy(one->name, two->name);
	strcpy(two->name, str);

	strcpy(str, one->song);
	strcpy(one->song, two->song);
	strcpy(two->song, str);

	aux = one->members;
	one->members = two->members;
	two->members = aux;

	aux = one->ranking;
	one->ranking = two->ranking;
	two->ranking = aux;
}

int mkBin(banda bandas[FIVE])
{
	/*THIS FUNCTION CREATE THE BINARY FILE TO STORAGE ALL INFORMATIONS*/
	register int i;
	FILE * PB_IN; //pointer, binary, input

	if((PB_IN = fopen("storage_bands.bin", "wb")) == NULL)
		return 1;
	for(i = 0; i < FIVE; i++){
		fwrite(&bandas[i], sizeof(banda), 1, PB_IN);
	}
	fclose(PB_IN);
	return 0;
}

void findRank()
{
	/*THIS FUNCTION SEARCH WHETER A BAND'S RANKING EXISTS*/
	struct sbanda read[FIVE];
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
		exit(1);
	}
	for(i = 0; i < FIVE; i++){
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
	struct sbanda read[FIVE];
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
		exit(1);
	}
	for(i = 0; i < FIVE; i++){
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
	struct sbanda read[FIVE];
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
		exit(1);
	}
	for(i = 0; i < FIVE; i++){
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
/*END OF FILE*/
