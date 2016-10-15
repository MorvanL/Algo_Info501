#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"

Hanoi creerHanoi (int n){
	int i;
	Hanoi h;
	h.p1 = creerPile(n);
	h.p2 = creerPile(n);
	h.p3 = creerPile(n);
	for(i=n; i>0; i--){
		empiler( &(h.p1), i );
	}
	return h;
}

void afficherHanoi (Hanoi* h){
	printf("Tour 1 : ");
	afficherPile( &((*h).p1) );
	printf("Tour 2 : ");
	afficherPile( &((*h).p2) );
	printf("Tour 3 : ");
	afficherPile( &((*h).p3) );	
}

void deplacerDisque( int tourDepart, int tourArrive, Hanoi* h ){
	if( tourDepart == 1 ){
		if( tourArrive == 2 ){
			if( (pileVide(&((*h).p1)) == 1)  &&  ( (pileVide(&((*h).p2)) == 0) || (sommet(&((*h).p1)) < sommet(&((*h).p2))) ) ){
				empiler( &((*h).p2), depiler(&((*h).p1)) );
			}
		}
		if( tourArrive == 3 ){
			if( (pileVide(&((*h).p1)) == 1)  &&  ( (pileVide(&((*h).p3)) == 0) || (sommet(&((*h).p1)) < sommet(&((*h).p3))) ) ){
				empiler( &((*h).p3), depiler(&((*h).p1)) );
			}
		}
	}

	if( tourDepart == 2 ){
		if( tourArrive == 1 ){
			if( (pileVide(&((*h).p2)) == 1)  &&  ( (pileVide(&((*h).p1)) == 0) || (sommet(&((*h).p2)) < sommet(&((*h).p1))) ) ){
				empiler( &((*h).p1), depiler(&((*h).p2)) );
			}
		}
		if( tourArrive == 3 ){
			if( (pileVide(&((*h).p2)) == 1)  &&  ( (pileVide(&((*h).p3)) == 0) || (sommet(&((*h).p2)) < sommet(&((*h).p3))) ) ){
				empiler( &((*h).p3), depiler(&((*h).p2)) );
			}
		}
	}

	if( tourDepart == 3 ){
		if( tourArrive == 1 ){
			if( (pileVide(&((*h).p3)) == 1)  &&  ( (pileVide(&((*h).p1)) == 0) || (sommet(&((*h).p3)) < sommet(&((*h).p1))) ) ){
				empiler( &((*h).p1), depiler(&((*h).p3)) );
			}
		}
		if( tourArrive == 2 ){
			if( (pileVide(&((*h).p3)) == 1)  &&  ( (pileVide(&((*h).p2)) == 0) || (sommet(&((*h).p3)) < sommet(&((*h).p2))) ) ){
				empiler( &((*h).p2), depiler(&((*h).p3)) );
			}
		}
	}	
}

int gagne (Hanoi* h, int n){		//retourne 0 si gagne 1 sinon
	if( taillePile(&((*h).p2)) == n  ||  taillePile(&((*h).p3)) == n ){
		return 0;
	}
	return 1;
}
