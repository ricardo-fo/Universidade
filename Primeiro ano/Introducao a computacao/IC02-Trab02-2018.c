/*
 * Trabalho 02 de Introdução à Computação II - UNISANTOS - 2018
 * Autores:
 * Alexandre Saura   | C.C.
 * Fábio Thomaz      | C.C.
 * Ricardo Oliveira  | C.C.
 * Professor: Ciro Cirne Trindade
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int cod;
	char descricao[51];
} tproduto;

typedef struct {
	int cod;
	char nome[41];
	char site[81];
} tloja;

typedef struct {
	int cod_produto;
	int cod_loja;
	float preco;
} tpreco;

void cadastrar_prod(void);
int pegar_cod(void);
void listar_prod(void);
void ordenar(tproduto *, int);
void alterar_prod(void);
void cadastrar_loja(void);
void listar_loja(void);
void cadastrar_preco(void);
void listar_preco(void);
void consultar_preco(void);

int main()
{
	int op;

	do{
		printf("/ Digite o numero de uma das opcoes\\\n");
		printf("*----------------------------------*\n");
		printf("| <1> Cadastrar produtos;          |\n");
		printf("| <2> Alterar produto;             |\n");
		printf("| <3> Listar produtos cadastrados; |\n");
		printf("| <4> Cadastrar lojas;             |\n");
		printf("| <5> Listar lojas cadastradas;    |\n");
		printf("| <6> Cadastrar precos;            |\n");
		printf("| <7> Listar precos cadastros;     |\n");
		printf("| <8> Consultar preco de produto;  |\n");
		printf("| <0> Sair.                        |\n");
		printf("*----------------------------------*\n>>> ");
		scanf("%d", &op);

		switch(op){
			case 0:
				break;
			case 1:
				cadastrar_prod();
				break;
			case 2:
				alterar_prod();
				break;
			case 3:
				listar_prod();
				break;
			case 4:
				cadastrar_loja();
				break;
			case 5:
				listar_loja();
				break;
			case 6:
				cadastrar_preco();
				break;
			case 7:
				listar_preco();
				break;
			case 8:
				consultar_preco();
				break;
			default:
				fprintf(stderr, "\n\aOpcao invalida!\n");
		}
		printf("\n");
	}while(op != 0);

	return 0;
}

void cadastrar_prod()
{
	/*Este procedimento cadastra novos produtos*/
	FILE * pin;
	int codigo = pegar_cod();

	printf("************************************\n");
	printf("*        CADASTRO DE PRODUTOS      *\n");
	printf("************************************\n");
	printf("* Para sair, digite 'sair' na des- *\n");
	printf("* -cricao                          *\n");
	if((pin = fopen("produtos.dat", "ab")) == NULL){
		fprintf(stderr, "\n\aErro ao abrir 'produtos.dat'!\n");
		exit(1);
	}
	tproduto produto;
	char descricao[51];
	int i = 1;

	do{
		printf("************************************\n");
		printf("Produto %03d\n", i++);
		printf("Codigo: %d\n", ++codigo);
		printf("Descricao: ");
		scanf(" %50[^\n]", descricao);
		while(getchar() != '\n');
		if(!strcmp(descricao, "sair"))
			break;

		produto.cod = codigo;
		strcpy(produto.descricao, descricao);
		fwrite(&produto, sizeof(tproduto), 1, pin);
	}while(strcmp(descricao, "sair"));
	fclose(pin);
	printf("\n");
}

int pegar_cod()
{
	/*Esta função retorna o código do último produto cadastrado*/
	FILE * pout;
	int codigo;

	if((pout = fopen("produtos.dat", "a+b")) == NULL){
		fprintf(stderr, "\n\aErro ao ler o arquivo 'produtos.dat'!\n");
		exit(1);
	}
	fseek(pout, 0, SEEK_END);
	if(!ftell(pout)){
        	fclose(pout);
        	return 0;
	}
	codigo = ftell(pout) / sizeof(tproduto);
	fclose(pout);

	return codigo;
}

void listar_prod()
{
	/*Mostra as informações sobre os produtos; baseia-se em ordem
	alfabética*/
	FILE * pout;

	if((pout = fopen("produtos.dat", "rb")) == NULL){
		fprintf(stderr, "\n\aErro ao ler o arquivo 'produtos.dat'!\n");
		exit(1);
	}

	fseek(pout, 0, SEEK_END);
	int i, tam = ftell(pout)/sizeof(tproduto);
	tproduto produtos[tam];
	rewind(pout);
	fread(produtos, sizeof(tproduto), tam, pout);
	ordenar(produtos, tam);
	fclose(pout);

	printf("+----------------------------------- --- -- -\n");
	printf("|Codigo     | Descricao             \n");
	printf("+-----------+----------------------- --- -- -\n");
	for(i = 0; i < tam; i++){
        	printf("+-----------+----------------------- --- -- -\n");
        	printf("|%010d |%s\n", produtos[i].cod, produtos[i].descricao);
	}
	printf("+-----------+----------------------- --- -- -\n");
}

void ordenar(tproduto * produtos, int max)
{
	/*Ordenação por ordem alfabética usando Insertion Sort*/
	register int i, j;
	tproduto key;

	for(i = 1; i < max; i++){
		key = produtos[i];
		j = i-1;
		while(j >= 0 && strcasecmp(produtos[j].descricao, key.descricao) > 0){
            		produtos[j+1] = produtos[j];
            		j--;
		}
		produtos[j+1] = key;
	}
}

void alterar_prod()
{
	/*Altera a descricao de um produto*/
	FILE * pin;
	int codigo;

	printf("************************************\n");
	printf("*       ALTERACAO DE PRODUTO       *\n");
	printf("************************************\n");
	printf("* Digite 'sair' na nova descricao  *\n");
	printf("* para cancelar a acao             *\n");
	printf("************************************\n");
	printf("Codigo do produto: ");
	scanf("%d", &codigo);

	if((pin = fopen("produtos.dat", "r+b")) == NULL){
		fprintf(stderr, "\n\aErro ao abrir 'produtos.dat'!\n");
		exit(1);
	}
	tproduto produto;
	fseek(pin, (codigo-1) * sizeof(tproduto), SEEK_SET);
	fread(&produto, sizeof(tproduto), 1, pin);

	if(produto.cod == codigo){
		printf("\nDescricao: %s\n", produto.descricao);
	}else{
		printf("\nProduto nao encontrado!\n");
		return;
	}

	char descricao[51];
	printf("Nova descricao: ");
	scanf(" %50[^\n]", descricao);
	while(getchar() != '\n');
	if(!strcmp(descricao, "sair")){
		fclose(pin);
		return;
	}
	produto.cod = codigo;
	strcpy(produto.descricao, descricao);
	fseek(pin, -sizeof(tproduto), SEEK_CUR);
	fwrite(&produto, sizeof(tproduto), 1, pin);
	fclose(pin);
}

void cadastrar_preco()
{

}

void listar_preco()
{

}

void cadastrar_loja()
{

}

void listar_loja()
{

}

void consultar_preco()
{

}
