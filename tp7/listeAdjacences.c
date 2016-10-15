#include <stdio.h>
#include <stdlib.h>
#include "listeAdjacences.h"

listeAdjacences creerListeAdjacences(){
	listeAdjacences l;
	l.tete = NULL;
	return l;
}

void inserer( listeAdjacences* l, sommet* s ){
	if( l->tete != NULL ){
		l->tete->pred = s;
		s->succ = l->tete;
	}
	l->tete = s;
}

sommet* rechercher( listeAdjacences* l, int ind){
	sommet* s = l->tete;
	while( (s!=NULL)  &&  (s->indice != ind) ){
		s = s->succ;
	}
	return s;
}

void supprimer( listeAdjacences* l, sommet* s){
	if( s->pred != NULL ){
		s->pred->succ = s->succ;
	}
	else{
		l->tete = s->succ;
	}
	if( s->succ != NULL ){
		s->succ->pred = s->pred;
	}
}

void detruireListeAdjacences (listeAdjacences* l){
	sommet* s = l->tete;
	sommet* s2 = NULL;
	while( s!= NULL ){
		s2 = s->succ;
		free(s);
		s = s2;
	}
}

void afficherListeAdjacences (listeAdjacences* l){
	sommet* s = l->tete;
	while( s != NULL ){
		printf("->%d",s->indice);
		s = s->succ;
	}
	printf("\n");
}

