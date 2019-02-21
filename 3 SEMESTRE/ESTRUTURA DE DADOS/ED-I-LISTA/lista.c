/* lista.c*/

#include "lista.h"

void lst_init(lista * l)
{
	l->n = 0; // lista vazia
}

bool lst_acessar(lista l, int k, lst_info * val)
{
	if(k >= 0 && k < l.n){ // verifica se 
		*val = l.itens[k];
		return true;	
	}
	return false;
}

bool lst_alterar(lista * l, int k, lst_info val)
{
	if(k >= 0 && k < l->n) { // verifica se é possível alterar o item pedido
		l->itens[k] = val; // item k é alterado para valor val
		return true;
	}
	return false; // item não consta na lista
}

bool lst_inserir(lista * l, int k, lst_info val)
{
	if(l->n < LST_MAX && k >= 0 && k <= l->n) { // verifica se é possível fazer a inserção
		int i;
		for(i = l->n - 1; i >= k; i--) { // desloca os itens para +1 posição
			l->itens[i + 1] = l->itens[i];		
		}
		l->itens[k] = val; // valor val é inserido na posição k
		l->n++; // adiciona +1 ao tamanho da lista
		return true;
	}
	return false; // impossível fazer a inserção
}

bool lst_remover(lista * l, int k, lst_info * val)
{
	if(k >= 0 && k < l->n) { // verifica se o item a ser inserido está nos limites da lista
		
	}
}
