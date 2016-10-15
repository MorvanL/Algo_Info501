#include <stdio.h>
#include <stdlib.h>
#include "outilsListe.h"

void afficherListe (liste* l){
	cellule* c = l->tete;
	while( c != NULL ){
		printf("%s ",c->mot);
		c = c->succ;
	}
	printf("\n");
}

int compterListe (liste* l){
	int cpt = 0;
	cellule* c = l->tete;
	while( c != NULL ){
		cpt++;
		c = c->succ;
	}
	return cpt;
}
