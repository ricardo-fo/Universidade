#include <stdio.h>
#include <stdlib.h>

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

void cadastar_prod(void);
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
		scanf("%f", &op);

		switch(op){
			case 0:
				break;
			case 1:
				cadastar_prod();
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
	}while(op != 0);
}

void cadastrar_prod()
{

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