#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

liste creerListe(){
	liste l;
	l.tete = NULL;
	return l;
}

void inserer( liste* l, cellule* c ){
	if( l->tete != NULL ){
		l->tete->pred = c;
		c->succ = l->tete;
	}
	l->tete = c;
}

cellule* rechercher( liste* l, char* ch){
	cellule* c = l->tete;
	while( (c!=NULL)  && (strcmp(c->mot, ch) != 0) ){
		c = c->succ;
	}
	return c;
}

void supprimer( liste* l, cellule* c){
	if( c->pred != NULL ){
		c->pred->succ = c->succ;
	}
	else{
		l->tete = c->succ;
	}
	if( c->succ != NULL ){
		c->succ->pred = c->pred;
	}
	detruireCellule(c);
}


void detruireListe( liste* l){
	cellule* c = l->tete;
	cellule* c2 = NULL;
	while( c != NULL ){
		c2 = c->succ;
		detruireCellule(c);
		free(c);
		c = c2;
	}	
}


