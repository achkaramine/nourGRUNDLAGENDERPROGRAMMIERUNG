#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _STP_NAME_MAXLENGTH_ 20

struct stS {
	int TAN;
	char name[_STP_NAME_MAXLENGTH_];
} typedef stS;

struct clS {
	stS content;
	struct clS *prev;
	struct clS *next; 
} typedef clS;

clS *stack;

stS pull () {
	if ( stack  == NULL ) exit(1) ;//pas lapene de continuer sil y a rien :P
	stS result=stack->content; // En prend la valeur du top de la pile
	if ( stack->prev == NULL ) { // Si c'est le dernier dans la pile. on libere l espace .. ptit coup de balé
		free(stack);
		stack=NULL;
	}
	else { // Sinon on supprime le dernier elemen et le remplace par le precedent
		clS *tempTobeCleared=stack;
		stack=stack->prev;
		free (tempTobeCleared);
	}
	return result; 
}

void push ( int tan, char *name ) { // c'est un peu null .. mais l exo est comme ca. 
	
	if ( tan >= 1000 || tan < 0 ) { printf ("\nTAN ID: %d not correct\n",tan); return;}
	
	stS *entry=malloc(sizeof(*entry)); // je cree le contenu de la pile ( les data .. )
	entry->TAN=tan;
	strncpy(entry->name, name, strlen(name)>_STP_NAME_MAXLENGTH_?_STP_NAME_MAXLENGTH_-1:strlen(name));

	clS *newElem=malloc(sizeof (*newElem)); // je cree de l espace
	newElem->content=*entry;

	if ( stack == NULL ) { // Sil y a rien 
		stack = newElem;
	}
	else {
		newElem->prev=stack; // on place notre new elem dans la list
		stack->next=newElem;

		clS *tmp = newElem; // On switch entre new Element est stack, comme ca .. stack rest au top de la pile
		newElem=stack;
		stack=tmp;
	}
}

void displaySts ( stS s ){
	printf ("User : {name=%s, TAN=%d}\n", s.name, s.TAN);
}

int main ( char ** args ) {
	push (122, "Amine qwedasdasd asd asd asd asd asd asd asd asd ");
	push (123, "Nour");
	push (124, "Sarah");
	push (125, "Ahmed");
 	displaySts(pull());
 	displaySts(pull());
	push (122, "Amine ");
	push (123, "Nour");
 	displaySts(pull());
 	displaySts(pull());
 	displaySts(pull());
	push (124, "Sarah");
 	displaySts(pull());
 	displaySts(pull());
 	displaySts(pull());
	return 0;
}
