/*
Faça um programa em C com duas funções: uma para gravar
em um arquivo e outra para escrever. O programa principal
deve conter um menu com as opções: 1- Gravar Pessoa;
2- Exibir Listagem; 3- Sair. Ao escolher Gravar Pessoa,
a função void gravar(void) deve ser chamada; ao escolher
Exibir Listagem, o programa deve exibir o conteúdo do
arquivo manipulado em Gravar Pessoa; O nome do arquivo
deve ser parametrizado em uma variável global.

void gravarPessoa(void):

A função permite o usuário informar o nome de uma pessoa
e o ano de nascimento. Deve ser criada uma linha no
arquivo com a seguinte característica:

[nome][anonascimento]\n
Onde deve ser preenchido com espaços após o nome até que
se atinja um total de 50 caracteres para nome, seguido
de 4 caracteres para o ano de nascimento. Exemplo:

Fernando..........................................1977

(Na linha acima cada ponto corresponde a um espaço.
 Neste caso como a string Fernando possui 8 caracteres,
 são concatenados 42 espaços para que atinja 50)

void exibirListagem(void):

A função deverá ler o arquivo de entrada e imprimir na
tela cada linha. O programa deve calcular a idade a
partir do ano de nascimento, e colocar ao lado do
nascimento uma mensagem conforme a regra a seguir:

Se a idade for menor do que 18 anos, escrever:  <18
Se a idade for maior ou igual que 18 anos, escrever  OK
*/
#include <stdio.h>  /*padrão*/
#include <string.h> /*strcat();*/
#include <time.h>

char file[] = "hold.txt";
void gravarPessoa(void);
void exibirListagem(void);

int main()
{
    int global, j = 1;

    printf("Digite um dos numeros abaixo para fazer sua escolha:\n1 - Gravar pessoa;\n2 - Exibir listagem;\n3 - Sair.\n");
    while(j){
        printf(">>> ");
        scanf("%d", &global);
        switch (global)
        {
            case 1:
                    gravarPessoa();
                    break;
            case 2:
                    //exibirListagem();
                    break;
            default:
                    j = 0;
                    break;
        }
    }
    return 0;
}

void gravarPessoa(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano_atual = tm.tm_year + 1900;
    int ano_nascimento, idade, i = 0;
    char ch, nome[51], dots[51] = "..................................................";

    FILE *pin;

    printf("Informe seu nome: ");
    scanf(" %50[^\n]", nome);
    printf("Informe o ano de seu nascimento: ");
    scanf("%d", &ano_nascimento);
    strncat(nome,dots,(50 - strlen(nome)));
    nome[51] = '\0';

    pin = fopen(file, "a");
    while(nome[i] != '\0')
    {
        printf("%d\n", ano_nascimento);
        ch = nome[i];
        fprintf(pin,"%c",ch);
        i++;
    }
    printf("%d\n", ano_nascimento);
    fprintf(pin,"%d",ano_nascimento);
    printf("%d\n", ano_nascimento);
    idade = ano_atual - ano_nascimento;
    if(idade < 18)
        fprintf(pin," <18");
    else
        fprintf(pin," OK");
    fprintf(pin,"%c", '\n');
    fclose(pin);
}

//void exibirListagem(void)
//{
//    char storage[55];
//
//    FILE *pout;
//    pout = fopen("hold.txt","r");
//    while(!feof(pout)){
//        fscanf(pout,"%s[^\n]",storage);
//        printf("%s\n",storage);
//    }
//    fclose(pout);
//
//}
