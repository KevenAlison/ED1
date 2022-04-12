
#include <stdio.h>
#include <stdlib.h>

struct no {
	int val;
	struct no* prox;
};

struct linkedlist {
	struct no* cabeca;
	int tamanho;
};

struct linkedlist* inicializar(){
	struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	lista->cabeca = NULL;
	lista->tamanho = 0;
	return lista; 
}

struct no* alocarNovoNo(int valor)
{
	struct no* novoNo = (struct no*)malloc(sizeof(struct no));
	novoNo->val = valor;
	novoNo->prox = NULL;
	return novoNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
	struct no *noFim = alocarNovoNo(valor);
	struct no *aux = NULL;
	if (lista->cabeca == NULL){
		lista->cabeca = noFim;
	} else {
		aux = lista->cabeca;
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = noFim;
	}
	lista->tamanho++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
	struct no* noInicio = alocarNovoNo(valor);
	if (lista->cabeca != NULL) {
		noInicio->prox = lista->cabeca;
		lista->cabeca = noInicio;
	}
	else {
		lista->cabeca = noInicio;
	}
	lista->tamanho++;
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
	if (posicao >= 0 && lista->tamanho != 0) {
		struct no* aux = lista->cabeca;
		int count = 0;
		while (count < posicao && aux->prox != NULL) {
			aux = aux->prox;
			count++;
		}
		return aux->val;
	}
	else {
		printf("\nPosicao invalida\n");
		return -1;
	}
}

void imprimirLista(struct linkedlist* lista) {
	//usamos o aux para percorrer a lista
	if (lista->cabeca != NULL) {
		struct no* aux = lista->cabeca;
		//navega partindo da cabeça até chegar NULL
		printf("[");
		do {
			printf("%d", aux->val);
			aux = aux->prox;
			if (aux != NULL) {
				printf(", ");
			}
		} while (aux != NULL);
		printf("]");
	}
	else {
		printf("A lista está vazia!");
	}
}

