#include <stdio.h>
#include <stdlib.h>

typedef struct pile Pile;

Pile* create_pile();
int empty(Pile*p);
void push(Pile*p, float value);
float pop(Pile*p);
int size(Pile*p);
void destroy(Pile*p);
