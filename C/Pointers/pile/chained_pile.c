#include "pile.h"

typedef struct node{
	float info;
	struct no* next;
}No;

struct pile{
	No* top;
	int qtt;
};

Pile* create_pile(){
	Pile* p = (Pile*) malloc(sizeof(Pile));
	if(!p) exit(1);
	
	p->qtt = 0;
	p->top = NULL;
	return p;
}

int empty(Pile*p){
	return (p->qtt == 0);
}

int size(Pile*p){
	return p->qtt;
}

void destroy(Pile*p){
	No* aux = p->top;
	while(aux){
		No* t = aux->next;
		free(aux);
		aux = t;
	}
	free(p);
}

void push(Pile* p, float value){
	No* new_ = (No*) malloc(sizeof(No));
	if(!new_) exit(1);
	new_->info = value;
	new_->next = p->top;
	p->top = new_;
	p->qtt++;
}

float pop(Pile* p){
	if(!empty(p)){
		No* aux = p->top;
		float ret = p->top->info;
		p->top = p->top->next;
		free(aux);
		p->qtt--;
		return ret;
	}else{
		printf("\nEmpty Pile");
		return-1;
	}
}
