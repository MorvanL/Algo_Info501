#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Pile creerPile(int n){
	Pile pile;
	pile.capacite = n;
	pile.sommet = 0;
	pile.p = (noeud**)malloc (n*sizeof(noeud*));
	return pile;
}
		
		
void detruirePile(Pile* pile){
	(*pile).sommet = 0;
	free( (*pile).p );
}

int pileVide(Pile* pile){ //retourne 0 si Vide et 1 si nonVide
	if (  (*pile).sommet == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int pilePleine(Pile* pile){ //retourne 0 si Pleine et 1 si nonPleine
	if( (*pile).sommet == (*pile).capacite ){
		return 0;
	}
	else{
		return 1;
	}
}

void empiler(Pile* pile, noeud* element){
	if (pilePleine(pile) == 1 ){
		((*pile).p)[(*pile).sommet] = element;
		(*pile).sommet+=1;
	}
	else{
		printf("la pile est pleine\n");
	}
}

noeud* depiler(Pile* pile){
	if ( pileVide(pile) == 1 ){
		((*pile).sommet)-=1;
		return (((*pile).p)[(*pile).sommet]);
	}
	else{
		printf("la pile est vide\n");
		return NULL;
	}
}

















