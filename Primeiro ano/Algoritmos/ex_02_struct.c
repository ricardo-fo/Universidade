#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 40

typedef struct {
	char nome[101];
	int numero;
	int area;
	int moradores;
	float valor;
} data;

data lares[MAX];

void Menu(void);
void PreencheAuto(void);
void TrocaNum(int vet[][5]);
void TrocaStr(int vet[][10]);
void CriaNome(char pessoas[MAX][41], const char nomes[10][15], const char sobrenomes[10][13], const char ultimo[10][15], const int vet[][10]);
void Numero(int, int, int * vet);
void PreencheManu(void);
void MostrarMoradores(void);

int main()
{
	time_t t;
	srand((unsigned)time(&t));
	Menu();

	return 0;
}

void Menu()
{
	register int i;
	int choice;

	printf("-------------------------------------------------------------\n");
	printf("\t\tBem Vindo(a) ao condominio Aguas\n");
	printf("-------------------------------------------------------------\n");
	do{
		printf("\nEscolha o numero de uma das opcoes e digite-o:\n1 - Preencher condominos automaticamente;\n");
		printf("2 - Preencher condominos manualmente;\n");
		printf("3 - Mostrar informacoes sobre os condominos;\n");
		printf("0 - Sair.\n>>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				PreencheAuto();
				break;
			case 2:
				PreencheManu();
				break;
			case 3:
				MostrarMoradores();
				break;
			case 0:
				printf("Adeus, visitante! :)\n");
				choice = 0;
				break;
		}
	}while(choice != 0);
}

void PreencheAuto()
{
	char lista_nome[10][15] = {"Ana", "Beatriz", "Caio", "Daniel", "Emanuela",
							   "Fidalgo", "Gabriel", "Homero", "Ingrid", "Joana"};
	char lista_sobrenome[10][13] = {" da Silva", " Pereira", " Oliveira", " de Freitas",
									" de Souza", " Heinsenberg", " Gilmour", " Macedo",
									" Trindade", " di Pinto"};
    char lista_ultimo_nome[10][15] = {" Vasconcelos", " Visconde", " Barbosa", " Nascimento",
                                      " Pedreira", " Rocha", " Marconde", " de Rosa",
                                      " D'Avila", " Flores"};
	char lista_nome_sobrenome[MAX][41];
	int storage_str[3][10] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
						  	  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
						  	  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
    int lista_numeros[MAX];
    int lista_areas[MAX];
    int lista_moradores[MAX];
    float lista_valores[MAX];
	register int i;
	register float j;

	TrocaStr(storage_str);
	CriaNome(lista_nome_sobrenome, lista_nome, lista_sobrenome, lista_ultimo_nome, storage_str);
    Numero(2, 1, lista_numeros);
    Numero(70, 5, lista_areas);

	for(i = 0; i < MAX; i++){
		strcpy(lares[i].nome, lista_nome_sobrenome[i]);
		lares[i].numero = lista_numeros[i];
		lares[i].area = lista_areas[i];
		j = rand() % 10;
		lares[i].valor = lista_areas[i] * 10 + (i*j) / 10;
		lares[i].moradores = (rand() % 5) + 1;
	}
	printf("\aPreenchimento automatico feito com sucesso!\n");
}

void TrocaStr(int vet[][10])
{
	register int i, j, rnd1, rnd2, aux;

	for(i = 0; i < 50; ++i){
		for(j = 0; j < 3; ++j){
			rnd1 = rand() % 10;
			rnd2 = rand() % 10;
			aux = vet[j][rnd1];
			vet[j][rnd1] = vet[j][rnd2];
			vet[j][rnd2] = aux;
		}
	}
}

void Numero(int inicio, int operacao, int * vet)
{
	register int i, j, rnd1, rnd2, aux;

    for(i = inicio, j = 0; j < MAX; i += operacao, j++){
		vet[j] = i;
    }
	for(i = 0; i < MAX; i++){
		rnd1 = rand() % MAX;
		rnd2 = rand() % MAX;
		aux = vet[rnd1];
		vet[rnd1] = vet[rnd2];
		vet[rnd2] = aux;
	}
}

void CriaNome(char pessoas[MAX][41], const char nomes[10][15], const char sobrenomes[10][13], const char ultimo[10][15], const int vet [][10])
{
	register int i, j, rnd1, rnd2, sum = 0;

	for(i = 0; i < 10; i++){
		for(j = 0; j < 4; j++){
			strcpy(pessoas[sum], nomes[vet[0][i]]);
			if(j % 2 == 0){
                rnd1 = rand () % 10;
                rnd2 = rand() % 10;
                strcat(pessoas[sum], sobrenomes[vet[1][rnd1]]);
                strcat(pessoas[sum], ultimo[vet[2][rnd2]]);
                sum++;
                continue;
			}
			rnd1 = rand () % 10;
			rnd2 = rand() % 10;
			strcat(pessoas[sum], ultimo[vet[2][rnd2]]);
			strcat(pessoas[sum], sobrenomes[vet[1][rnd1]]);
            sum++;
		}
	}
}

void PreencheManu()
{
    printf("Em construcao!\n");
}

void MostrarMoradores()
{
	register int i;

	for(i = 0; i < MAX; ++i){
		printf("Proprietario: %s\n", lares[i].nome);
		printf("Numero: %d\n", lares[i].numero);
		printf("Area: %d m2\n", lares[i].area);
		printf("Moradores: %d\n", lares[i].moradores);
		printf("Valor: R$ %.2f\n\n", lares[i].valor);
	}
}
