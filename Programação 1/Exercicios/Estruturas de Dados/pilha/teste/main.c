#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *prox;
};

struct pilha{
	struct no *topo;
};

void push(struct pilha *p){
	struct no *novo = malloc(sizeof(struct no));
	novo->prox = NULL;
	scanf("%d", &novo->dado);
	if(!p->topo)
		p->topo = novo;
	else{
		novo->prox = p->topo;
		p->topo = novo;
	}
}

struct no *pop(struct pilha *p){
	struct no *aux = p->topo;
	p->topo = p->topo->prox;
	return aux;
}

void imprimirPilha(struct pilha *p){
	struct no *aux = p->topo;
	while(aux){
		printf("%d\n", aux->dado);
		aux = aux->prox;
	}
}

void destruirPilha(struct pilha *p){
	struct no *aux = p->topo;
	while(aux){
		aux = aux->prox;
		free(p->topo);
		p->topo = aux;
	}
}

int main(){
	struct pilha *p = malloc(sizeof(struct pilha));
	int op;
	printf("op (0 = push 1 = pop): ");
	scanf("%d", &op);
	while(op != 2){
		if(!op)
			push(p);
		else{
			struct no *aux;
			aux = pop(p);
			free(aux);
		}
		printf("op (0 = push 1 = pop): ");
		scanf("%d", &op);
	}
	imprimirPilha(p);
	destruirPilha(p);
	free(p);
	return 0;
}
