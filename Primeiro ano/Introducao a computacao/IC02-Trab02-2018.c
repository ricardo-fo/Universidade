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
		fprintf(stderr, "Erro ao abrir 'produtos.dat'!\n");
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
		if(!strcmp(descricao, "sair"))
			break;
		while(getchar() != '\n');

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
		fprintf(stderr, "\a\nErro ao ler o arquivo 'produtos.dat'!\n");
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

}

void alterar_prod()
{

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
