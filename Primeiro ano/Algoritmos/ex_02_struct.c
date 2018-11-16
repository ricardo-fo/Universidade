#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 40

typedef struct {
	char nome[101];
	int numero;
	float area;
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
void ArquivoBin(void);
int CheckNome(const char *);
int CheckNumero(int);
void Reset(void);
void AreaTotal(void);
void Despesas(void);
void MaisMoradores(void);
void Ordenar(void);

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
	int choice, choice2;

	printf("-------------------------------------------------------------\n");
	printf("\t\tBem Vindo(a) ao condominio Aguas\n");
	printf("-------------------------------------------------------------\n");
	do{
		printf("\nEscolha o numero de uma das opcoes e digite-o:\n1 - Preencher condominos automaticamente;\n");
		printf("2 - Preencher condominos manualmente;\n");
		printf("3 - Mais opcoes;\n");
		printf("0 - Sair.\n>>> ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				PreencheAuto();
				break;
			case 2:
				Reset();
				PreencheManu();
				break;
			case 3:
				do{
					printf("\n4 - Mostrar informacoes sobre os condominos;\n");
					printf("5 - Area total do condominio;\n");
					printf("6 - Despesas;\n");
					printf("7 - Apartamento com mais moradores;\n");
					printf("8 - Ordenar por tamanho do apartamento;\n");
					printf("0 - Retornar...\n>>> ");
					scanf("%d", &choice2);
					switch(choice2){
						case 4:
							MostrarMoradores();
							break;
						case 5:
							AreaTotal();
							break;
						case 6:
							Despesas();
							break;
						case 7:
							MaisMoradores();
							break;
						case 8:
							Ordenar();
							break;
						case 0:
							printf(". . .");
							choice2 = 0;
							break;
						default:
							fprintf(stderr, "\n\aResposta nao compreendida!\n");
					}
				}while(choice2 != 0);
			case 0:
				printf("Adeus, visitante! :)\n");
				choice = 0;
				break;
			default:
				fprintf(stderr, "\n\aResposta nao compreendida!\n");
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

void Reset()
{
	register int i;

	for(i = 0; i < MAX; ++i){
		strcpy(lares[i].nome, "");
		lares[i].numero = 0;
		lares[i].area = 0;
		lares[i].moradores = 0;
		lares[i].valor = 0;
	}
}

void PreencheManu()
{
	register int i;
	char nome[101], choice;
	int numero, moradores;
	float valor, area;

	printf("\nDigite o <sair> no campo de nome para finalizar antes das 40 adicoes!");
	for(i = 0; i < MAX; i++){
		printf("\nNome (%03d): ", i+1);
		scanf(" %[^\n]s", nome);
		if(!strcmp(nome, "sair")){
			printf("Adeus!\n");
			break;
		}
		while(CheckNome(nome)){
			fprintf(stderr, "\nNome ja adcionado\nTem certeza que quer adiciona'-lo novamente? (s/n)>>> ");
			scanf(" %c", &choice);
			if(choice == 's' || choice == 'S'){
				strcpy(lares[i].nome, nome);
				printf("Nome adicionado\n");
				break;
			}
			if(choice == 'n' || choice == 'N'){
				printf("Novo nome: ");
				scanf(" %[^\n]s", nome);
				continue;
			}else{
				printf("Resposta nao entendida!\n");
			}
		}
		strcpy(lares[i].nome, nome);

		printf("Numero do apartamento (%03d): ", i+1);
		scanf("%d", &numero);
		while(CheckNumero(numero)){
			fprintf(stderr, "\nNumero ja adcionado\nTem certeza que quer adiciona'-lo novamente? (s/n)>>> ");
			scanf(" %c", &choice);
			if(choice == 's' || choice == 'S'){
				lares[i].numero = numero;
				printf("Numero adicionado\n");
				break;
			}
			if(choice == 'n' || choice == 'N'){
				printf("Novo numero: ");
				scanf("%d", &numero);
				continue;
			}else{
				printf("Resposta nao entendida!\n");
			}
		}
		lares[i].numero = numero;

		printf("Area do apartamento (%03d): ", i+1);
		scanf("%f", &area);
		lares[i].area = area;

		printf("Moradores do apartamento (%03d): ", i+1);
		scanf("%d", &moradores);
		lares[i].moradores = moradores;

		printf("Valor do apartamento (%03d): R$ ", i+1);
		scanf("%f", &valor);
		lares[i].valor = valor;
	}
}

int CheckNome(const char * str)
{
	static char todos_nomes[40][31];
	static int lim = 0;
	register int i;

	if(!lim){
		strcpy(todos_nomes[lim], str);
		lim++;
		return 0;
	}
	lim++;
	for(i = 0; i < lim; ++i){
		if(!strcmp(todos_nomes[i], str))
			return 1;
	}
	strcpy(todos_nomes[lim], str);
	return 0;
}

int CheckNumero(int numero)
{
	static int todos_numeros[40], limi = 0;
	register int i;

	if(!limi){
		todos_numeros[limi] = numero;
		limi++;
		return 0;
	}
	limi++;
	for(i = 0; i < limi; ++i){
		if(todos_numeros[i] == numero){
			return 1;
		}
	}
	return 0;
}

void MostrarMoradores()
{
	register int i;

	for(i = 0; i < MAX; ++i){
		printf("Proprietario: %s\n", lares[i].nome);
		printf("Numero: %d\n", lares[i].numero);
		printf("Area: %.2f m2\n", lares[i].area);
		printf("Moradores: %d\n", lares[i].moradores);
		printf("Valor: R$ %.2f\n\n", lares[i].valor);
	}
}

void AreaTotal()
{
	register int i;
	register float maior = 0, storage = 0;

	for(i = 0; i < MAX; ++i){
		storage += lares[i].area;
		if(lares[i].area > maior){
			maior = lares[i].area;
		}
	}
	printf("\nProvavel area do condominio: %.2f m2\n", maior);
	printf("Soma da area de todos os condominios: %.2f m2\n\n", storage);
}

void Despesas()
{
	register int i;
	float area, despesas, valor_pessoal;

	printf("\nArea total do condominio: ");
	scanf("%f", &area);
	printf("Total de despesas: R$ ");
	scanf("%f", &despesas);

	for(i = 0; i < MAX; ++i){
		valor_pessoal = (despesas * lares[i].area)/ area;
		printf("Despesa para o apartamento de numero (%03d): R$ %.2f\n\n", i+1, valor_pessoal);
	}
}

void MaisMoradores()
{
	register int i, j = 0;

	for(i = 0; i < MAX; ++i){
		if(lares[i].moradores > lares[j].moradores){
			j = lares[i].moradores;
		}
	}
	printf("\nApartamento(s) com mais numero de moradores: ");
	for(i = 0; i < MAX; ++i){
		if(lares[i].moradores == j){
			printf("\nProprietario: %s\n", lares[i].nome);
			printf("Numero: %d\n", lares[i].numero);
			printf("Moradores: %d\n", lares[i].moradores);
		}
	}
	printf("\n");
}

void Ordenar()
{
	register int i, j;
	data aux;

	for(i = 0; i < MAX; ++i){
		for(j = i; j < MAX; ++j){
			if(lares[i].area > lares[j].area){
				aux = lares[i];
				lares[i] = lares[j];
				lares[j] = aux;
			}
		}
	}
	printf("\nApartamentos ordenados segundo ordem decrescente por tamanho de condominio\n\n");
}
