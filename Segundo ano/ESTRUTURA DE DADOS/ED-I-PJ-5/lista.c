/* lista.c */

#include <stdio.h>
#include "lista.h"

void lst_init(lista * l)
{
	l->n = 0;
}

bool lst_acessar(lista l, int k, lst_info * val)
{
	if (k >= 0 && k < l.n) {
		*val = l.itens[k];
		return true;
	}
	return false;
}

bool lst_alterar(lista * l, int k, lst_info val)
{
	if (k >= 0 && k < l->n) {
		l->itens[k] = val;
		return true;
	}
	return false;
}

bool lst_inserir(lista * l, int k, lst_info val) {
	if (l->n < LST_MAX && k >= 0 && k <= l->n) {
		int i;
		for (i = l->n - 1; i >= k; i--) {
			l->itens[i + 1] = l->itens[i];
		}		
		l->itens[k] = val;
		l->n++;
		return true;
	}
	return false;
}

bool lst_remover(lista * l, int k, lst_info * val)
{
	if (k >= 0 && k < l->n) {
		int i;
		*val = l->itens[k];
		for (i = k + 1; i < l->n; i++) {
			l->itens[i - 1] = l->itens[i];
		}
		l->n--;
		return true;
	}
	return false;
}

void lst_imprimir(lista l)
{
	if(l.n > LST_MAX) return;

	register int i;	

	for(i = 0; i < l.n; i++){
		printf("\nPosição: %d\nValor: %d\n", i, l.itens[i]);
		printf("-------");
	}
}

int lst_procurar(lista l, lst_info val)
{
	if(l.n > LST_MAX) return -1;

	register int i;

	for(i = 0; i < l.n; i++){
		if(l.itens[i] == val){
			return i;
		}
	}
	return -1;
}

bool lst_ins_ordenado(lista * l, lst_info val)
{
	if(l->n > LST_MAX) return false;

	lst_ordenar(l);

	register int i, k;

	if(val > 0){
		for(i = val; ;i++){
			if((k = lst_procurar(*l, i)) != -1){
				break;
			}
		}
	} else {
		for(i = val; ;i--){
			if((k = lst_procurar(*l, i)) != -1){
				break;
			}
		}
	}
		

	if(lst_inserir(l, k, val)){
		return true;
	}
	return false;
	
}

void lst_ordenar(lista * l)
{
	register int i, j, aux;

	for(i = 0; i < l->n; i++){
		for(j = i; j < l->n; j++){
			if(l->itens[i] > l->itens[j]){
				aux = l->itens[i];
				l->itens[i] = l->itens[j];
				l->itens[j] = aux;
			}
		}
	}
}



