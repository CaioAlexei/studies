#include <stdio.h>
#include <stdlib.h>

// There´s 2 types of pile in this directory, include in the project, only one between (pile_vector.c, chained_pile.c)
#include "pile.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pile* p = create_pile();
	if(empty(p)){
		printf("\nEmpty Pile");
	}
	printf("\nPOP = %f",pop(p));
	
	push(p,10.9);
	push(p,11.9);
	push(p,12.9);
	push(p,13.9);
	
	printf("\nPOP = %f",pop(p));
	printf("\nPOP = %f",pop(p));
	
	push(p,12.9);
	push(p,13.9);
	push(p,14.9);
		
	printf("\nSize = %d",size(p));
	
	push(p,15.9);
	
	destroy(p);
	
	return 0;
}
