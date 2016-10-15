#include <stdio.h>
#include <stdlib.h>
#include "outilsPile.h"


void remplirPile(Pile* pile, int taille){	//fonction "bidon" pour test
	int i;
	for (i=0 ; i < taille ; i++){
		empiler(pile, i+1);
	}
}

void afficherPile(Pile* pile){
	int i;
	Pile pile2 = copierPile(*pile);
	for (i=0 ; i < taillePile(pile) ; i++){
		printf("%d ",depiler(&pile2));
	}
	printf("\n");
	detruirePile(&pile2);
}

int taillePile (Pile* pile){
	return( (*pile).sommet );
}

Pile copierPile (Pile pile){
	int i;
	int taille = taillePile(&pile);
	Pile pile2 = creerPile( taille );
	Pile pile3 = creerPile( taille );
	for(i=0; i<taille; i++){
		empiler( &pile2, depiler(&pile) );		
	}
	for(i=0; i<taille; i++){
		empiler( &pile3, depiler(&pile2) );		
	}
	detruirePile(&pile2);
	return pile3;
}

	








