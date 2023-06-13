#include "pile.h"
#define MAX 5

struct pile{
	int top;
	int qtt;
	float *elems;
	int tam_max;
};

Pile* create_pile(){
	
	Pile* p  = (Pile*) malloc(sizeof(Pile));
	if(!p) exit(1);
	
	p->qtt = 0;
	p->top = -1;
	p->tam_max = MAX;
	p->elems = (float*) malloc(sizeof(float)*MAX);
	if(!p->elems) exit(1);
	
	return p;
}

int empty(Pile*p){
	return(p->qtt == 0);
}

int full(Pile*p){
	return(p->qtt == p->tam_max);
}

int size(Pile*p){
	return p->qtt;
}

void destroy(Pile*p){
	free(p->elems);
	free(p);
}

void push(Pile*p, float valor){
	if(!full(p)){
		p->top++;
		p->elems[p->top] = valor;
		p->qtt++;
	}else{
		printf("\nPile full");
	}
	
}

float pop(Pile*p){
	if(!empty(p)){
		p->qtt--;
		p->top--;
		return p->elems[p->top+1];
	}
}


