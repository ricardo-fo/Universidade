/*Trabalho de Algoritmos II - UNISANTOS - 2018.
 *Função: Criar um programa para preencher informações sobre um condomínio.
 *Autor: Ricardo de F. Oliveira - Ciência da Computação. 16/11/2018.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 40

//Estrutura para armazenar informações sobre os moradores
typedef struct {
	char nome[101];
	int numero;
	float area;
	int moradores;
	float valor;
} data;
data lares[MAX];

//Estrutura auxiliar para criar nomes de moradores 'aleatórios'
typedef struct {
	char nome[10][15];
	char sobrenome[10][13];
	char ultimo[10][15];
	char completo[MAX][41];
	int storage[3][10];
} montagem;

void Menu(void);
void PreencheAuto(void);
void TrocaStr(int vet[][10]);
void CriaNome(montagem *);
void Numero(int, int, int * vet);
void PreencheManu(void);
void MostrarMoradores(void);
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
	/*Menu amigável ao usuário*/
	register int i;
	int choice, choice2;

	printf("-------------------------------------------------------------\n");
	printf("\t\tBem Vindo(a) ao condominio Aguas\n");
	printf("-------------------------------------------------------------\n");
	do{
		/*Looping principal que força o usuário a ter alguma informação no vetor de estrutura 'lares'*/
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
					/*Looping com informações adicionais para navegar por elas*/
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
				break;
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
	/*Para fins de teste e para poupar tempo, esta função cria informações aleatórias de moradores para preencher o vetor 'lares'*/
	char lista_nome[10][15] = {"Ana", "Beatriz", "Caio", "Daniel", "Emanuela", "Fidalgo", "Gabriel", "Homero", "Ingrid", "Joana"};
	char lista_sobrenome[10][13] = {" da Silva", " Pereira", " Oliveira", " de Freitas", " de Souza", " Heinsenberg", " Gilmour", " Macedo", " Trindade", " di Pinto"};
	char lista_ultimo_nome[10][15] = {" Vasconcelos", " Visconde", " Barbosa", " Nascimento", " Pedreira", " Rocha", " Marconde", " de Rosa", " D'Avila", " Flores"};
	int lista_numeros[MAX];
	int lista_areas[MAX];
	register int i;
	montagem Pessoa;

	/*Preenchimento dos vetores auxiliares com alguns nomes, sobrenomes e últimos nomes*/
	for(i = 0; i < 10; ++i){
        	strcpy(Pessoa.nome[i], lista_nome[i]);
        	strcpy(Pessoa.sobrenome[i], lista_sobrenome[i]);
        	strcpy(Pessoa.ultimo[i], lista_ultimo_nome[i]);
        	Pessoa.storage[0][i] = i;
        	Pessoa.storage[1][i] = i;
        	Pessoa.storage[2][i] = i;
	}

	/*Mudança dos valores fixos para gerar valores aleatórios*/
	TrocaStr(Pessoa.storage);
	CriaNome(&Pessoa);
	Numero(2, 1, lista_numeros);
	Numero(70, 5, lista_areas);

	/*Preenchimento da estrutura 'lares' com informações aleatórias*/
	for(i = 0; i < MAX; ++i){
		strcpy(lares[i].nome, Pessoa.completo[i]);
		lares[i].numero = lista_numeros[i];
		lares[i].area = lista_areas[i];
		lares[i].valor = lista_areas[i] * 10 + (i * (rand() % 10)) / 10;
		lares[i].moradores = (rand() % 5) + 1;
	}
	printf("\n\aPreenchimento automatico feito com sucesso!\n");
}

void TrocaStr(int vet[][10])
{
	/*Argumentos: vetor de 3 linhas e 10 colunas. Esse vetor guarda os índices, de 0 a 9, dos elementos do vetor Pessoa.storage.
	 *Linha 0: nomes. Linha 1: sobrenomes. Linha 2: últimos nomes.
	 *Colunas: Opções de nomes, sobrenomes e últimos nomes.*/
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
	/*A função manipula um vetor, 'vet', para colocar nele valores com início em 'inicio', adicionando valores entre 'operacao' e
	 *'operacao'*/
	register int i, j, rnd1, rnd2, aux;

	for(i = inicio, j = 0; j < MAX; i += operacao, ++j){
		vet[j] = i;
	}
	for(i = 0; i < MAX; ++i){
		rnd1 = rand() % MAX;
		rnd2 = rand() % MAX;
		aux = vet[rnd1];
		vet[rnd1] = vet[rnd2];
		vet[rnd2] = aux;
	}
}

void CriaNome(montagem * Pessoa)
{
	/*Função recebe uma estrutura do tipo montagem e manipula ela. Cria pessoas aleatórias*/
	register int i, j, rnd1, rnd2, sum = 0;

	for(i = 0; i < 10; ++i){
		for(j = 0; j < 4; ++j){
			strcpy(Pessoa->completo[sum], Pessoa->nome[Pessoa->storage[0][i]]);
			rnd1 = rand () % 10;
                	rnd2 = rand() % 10;
			if(j % 2 == 0){
                		strcat(Pessoa->completo[sum], Pessoa->sobrenome[Pessoa->storage[1][rnd1]]);
                		strcat(Pessoa->completo[sum], Pessoa->ultimo[Pessoa->storage[2][rnd2]]);
                		sum++;
                		continue;
			}
			strcat(Pessoa->completo[sum], Pessoa->ultimo[Pessoa->storage[2][rnd2]]);
			strcat(Pessoa->completo[sum], Pessoa->sobrenome[Pessoa->storage[1][rnd1]]);
            		sum++;
		}
	}
}

void Reset()
{
	/*Reseta a estrutura 'lares' para que não haja problemas com repetições anteriores a nova versão de 'lares'*/
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
	printf("\n***********************************************************\n");
	printf("\t\tPREENCHIMETNO MANUAL DE MORADORES");
	printf("\n***********************************************************\n");
	/*Preenchimento manual da estrutura 'lares'*/
	register int i;
	char nome[101], numero[51], moradores[51], valor[51], area[51], choice;

	printf("\nDigite o <sair> no campo de nome para finalizar antes das 40 adicoes!");
	for(i = 0; i < MAX; ++i){
		/*Preenchimento dos nomes com checagem de repetição*/
		printf("\n______________________________________________________");
		printf("\nNome (%03d): ", i+1);
		scanf(" %[^\n]s", nome);
		if(!strcmp(nome, "sair") || !strcmp(nome, "SAIR")){
			printf(". . .\n");
			break;
		}
		while(CheckNome(nome)){
			fprintf(stderr, "\n<<< Nome ja adicionado! >>>\nTem certeza que quer adiciona-lo novamente? (s/n)>>> ");
			scanf(" %c", &choice);
			if(choice == 's' || choice == 'S'){
				strcpy(lares[i].nome, nome);
				printf("Nome adicionado\n");
				break;
			}else{
				if(choice == 'n' || choice == 'N'){
					printf("Novo nome: ");
					scanf(" %[^\n]s", nome);
					continue;
				}else{
					printf("Resposta nao entendida!\n");
				}
			}
		}
		strcpy(lares[i].nome, nome);

		/*Preenchimento dos números com checagem de repetição*/
		printf("Numero do apartamento (%03d): ", i+1);
		scanf(" %[^\n]s", numero);
		while(!atoi(numero)){
			fprintf(stderr, "\n<<< O numero informado nao e' um valor inteiro! >>>\nNumero do apartamento (%03d): ", i+1);
			scanf(" %[^\n]s", numero);
		}
		while(CheckNumero(atoi(numero))){
			fprintf(stderr, "\n<<< Numero ja adicionado! >>>\nTem certeza que quer adiciona-lo novamente? (s/n)>>> ");
			scanf(" %c", &choice);
			if(choice == 's' || choice == 'S'){
				lares[i].numero = atoi(numero);
				printf("Numero adicionado\n");
				break;
			}else{
				if(choice == 'n' || choice == 'N'){
					printf("Novo numero: ");
					scanf(" %[^\n]s", numero);
					continue;
				}else{
					printf("Resposta nao entendida!\n");
				}
			}
		}
		lares[i].numero = atoi(numero);

		/*Preenchimento das áreas*/
		printf("Area do apartamento (%03d): ", i+1);
		scanf(" %[^\n]s", area);
		while(!atof(area)){
			fprintf(stderr, "\n<<< A area informada nao e' um valor real! >>>\nArea do apartamento (%03d): ", i+1);
			scanf(" %[^\n]s", area);
		}
		lares[i].area = atof(area);

		/*Preenchimento do número de moradores*/
		printf("Moradores do apartamento (%03d): ", i+1);
		scanf(" %[^\n]s", moradores);
		while(!atoi(moradores)){
			fprintf(stderr, "\n<<< Moradores informado nao e' um valor inteiro! >>>\nMoradores do apartamento (%03d): ", i+1);
			scanf(" %[^\n]s", moradores);
		}
		lares[i].moradores = atoi(moradores);

		/*Preenchimento dos valores*/
		printf("Valor do apartamento (%03d): R$ ", i+1);
		scanf(" %[^\n]s", valor);
		while(!atof(valor)){
			fprintf(stderr, "\n<<< O valor informado nao e' um valor real! >>>\nValor do apartamento (%03d): R$ ", i+1);
			scanf(" %[^\n]s", valor);
		}
		lares[i].valor = atof(valor);
	}
}

int CheckNome(const char * str)
{
	/*Argumentos: uma string constante que verifica se ela já foi usada antes, 'repetida'*/
	static char todos_nomes[MAX][31];
	static int lim = 0;
	register int i;

	if(!lim){
		strcpy(todos_nomes[lim], str);
		lim++;
		return 0;
	}
	lim++;
	for(i = 0; i < lim; ++i){
		if(!strcmp(todos_nomes[i], str)){
			return 1;
		}
	}
	strcpy(todos_nomes[lim], str);
	return 0;
}

int CheckNumero(int numero)
{
	/*Argumentos: valor inteiro, checa se esse número já foi usado para outro apartamento*/
	static int todos_numeros[MAX], limi = 0;
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
	printf("\n***********************************************************\n");
	printf("\t\tTODOS OS MORADORES SAO:");
	printf("\n***********************************************************\n");	
	/*Mostra as informações de todos os moradores do condomínio*/
	register int i;

	for(i = 0; i < MAX; ++i){
		printf("................................................\n");
		printf("Proprietario: %s\n", lares[i].nome);
		printf("Numero: %d\n", lares[i].numero);
		printf("Area: %.2f m2\n", lares[i].area);
		printf("Moradores: %d\n", lares[i].moradores);
		printf("Valor: R$ %.2f\n\n", lares[i].valor);
	}
}

void AreaTotal()
{
	/*Calcula a área total do condomínio, baseia-se apenas em valores já registrados*/
	register int i;
	register float maior = 0, storage = 0;

	for(i = 0; i < MAX; ++i){
		storage += lares[i].area;
		if(lares[i].area > maior){
			maior = lares[i].area;
		}
	}
	printf("\n***********************************************************\n");
	printf("\nProvavel area do condominio: %.2f m2\n", maior);
	printf("Soma da area de todos os condominios: %.2f m2\n\n", storage);
	printf("\n***********************************************************\n");
}

void Despesas()
{
	/*Calcula as despesas, usa informações oferecidas pelo usuário*/
	printf("\n***********************************************************\n");
	printf("\t\tDESPESAS");
	printf("\n***********************************************************\n");
	register int i;
	char area[21], despesas[21];
	float valor_pessoal;

	printf("\nArea total do condominio: ");
	scanf(" %[^\n]s", area);
	while(!atof(area)){
		fprintf(stderr, "\n<<< A area informada nao e' um valor real! >>>\nArea total do condominio: ");
		scanf(" %[^\n]s", area);
	}
	printf("Total de despesas: R$ ");
	scanf(" %[^\n]s", despesas);
	while(!atof(despesas)){
		fprintf(stderr, "\n<<< O total de despesas informadas nao e' um valor real! >>>\nTotal de despesas do condominio: ");
		scanf(" %[^\n]s", despesas);
	}
	for(i = 0; i < MAX; ++i){
		valor_pessoal = (atof(despesas) * lares[i].area)/ atof(area);
		printf("Despesa para o apartamento de numero (%03d): R$ %.2f\n\n", i+1, valor_pessoal);
	}
}

void MaisMoradores()
{
	/*Mosta os apartamentos que possuem maior quantidade de moradores*/
	printf("\n***********************************************************\n");
	printf("\t\tAPARTAMENTOS COM MAIS MORADORES");
	printf("\n***********************************************************\n");
	register int i, j = 0;

	for(i = 0; i < MAX; ++i){
		if(lares[i].moradores > j){
			j = lares[i].moradores;
		}
	}
	printf("\nApartamento(s) com mais numero de moradores:\n");
	for(i = 0; i < MAX; ++i){
		if(lares[i].moradores == j){
			printf("...................................................");
			printf("\nProprietario: %s\n", lares[i].nome);
			printf("Numero: %d\n", lares[i].numero);
			printf("Moradores: %d\n", lares[i].moradores);
		}
	}
	printf("\n");
}

void Ordenar()
{
	/*Ordena segundo ordem decrescente por tamanho de condominio*/
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
	printf("\n*****************************************************************************\n");
	printf("\nApartamentos ordenados segundo ordem decrescente por tamanho de condominio\n");
	printf("\n*****************************************************************************\n");
}
