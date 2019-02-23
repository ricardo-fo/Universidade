/* lista.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

bool lst_remover(lista * l, int k)
{
	if (k >= 0 && k < l->n) {
		int i;
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

	printf("[");
	for(i = 0; i < l.n; i++){
		printf("%d, ", l.itens[i]);
	}
	printf("\b\b]\n");
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
		for(i = val; i < l->n; i++){
			if((k = lst_procurar(*l, i)) != -1){
				lst_inserir(l, k, val);
				lst_ordenar(l);
				return true;
			}
		}
		lst_inserir(l, l->n - 1, val);
		lst_ordenar(l);
		return true;
	} else {
		for(i = val; i > -1*(l->n); i--){
			if((k = lst_procurar(*l, i)) != -1){
				lst_inserir(l, k, val);
				lst_ordenar(l);
				return true;
			}
		}
		lst_inserir(l, 0, val);
		lst_ordenar(l);
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

bool lst_inserir_final(lista * l, lst_info x)
{
	if(l->n == LST_MAX) return false;
	
	return (lst_inserir(l, l->n-1, x));
}

bool lst_inserir_inicio(lista * l, lst_info x)
{
	if(l->n == LST_MAX) return false;
	
	return (lst_inserir(l, 0, x));
}

bool lst_remover_final(lista * l, lst_info * x)
{
	if(l->n == 0) return false;

	return (lst_remover(l, l->n-1));
}

bool lst_remover_inicio(lista * l, lst_info * x)
{
	if(l->n == 0) return false;

	return (lst_remover(l, 0));
}

bool lst_gerar(lista * l, int nos, int max)
{
	if(nos > LST_MAX) return false;

	srand(time(NULL));

	register int i;

	for(i = 0; i < nos; i++){
		lst_inserir(l, i, ((rand() % max) + 1));
	}
	l->n = nos;

	return true;
}

bool lst_ordenada(lista l)
{
	register int i;

	for(i = 0; i < l.n; i++){
		if(l.itens[i] > l.itens[i+1])
			return false;
	}
	return true;
}

int lst_remover_menores(lista * l, lst_info x)
{
	/* NECESSITA DE AJUSTES */
	register int i, j, k, cont = 0;

	lst_ordenar(l);	

	for(i = 0; i < l->n; i++){
		if(l->itens[i] < x){
			cont++;
			k = i;
			for(j = i + 1; j < l->n; j++){
				if(l->itens[j] >= x){
					l->itens[k++] = l->itens[j];
				} else {
					cont++;
				}
			}
		}
	}
	l->n -= cont;

	return cont;
}



