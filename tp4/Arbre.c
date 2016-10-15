#include <stdio.h>
#include <stdlib.h>
#include "outilsArbre.h"

noeud* creerArbre (){
	return NULL;
}

void detruireArbre (noeud* arbre){
	if( arbre != NULL ){
		detruireArbre(arbre->filsG);
		detruireArbre(arbre->filsD);
		detruireNoeud(arbre);
		free(arbre);
	}	
}

void inserer (noeud** arbre, noeud** n){
		noeud* parentM = NULL;
		noeud* m = *arbre;
		while( m != NULL ){
			parentM = m;
			if( strcmp( (*n)->mot, m->mot) < 0 ){
				m = m->filsG;
			}
			else{
				m = m->filsD;
			}
		}  
		(*n)->pere = parentM;
		if( parentM == NULL ){
			*arbre = *n;
		}
		else{
			if( strcmp( (*n)->mot, parentM->mot) < 0 ){
				parentM->filsG = *n;
			}
			else{
				parentM->filsD = *n;
			}
		}
}

noeud* rechercher (noeud* arbre, char* ch){
	noeud* n = arbre;
	while( (n != NULL)  &&  (strcmp(ch, n->mot) != 0) ){
		if( strcmp(ch, n->mot) < 0 ){
			n = n->filsG;
		}
		else{
			n = n->filsD;
		}
	}
	return n;
}

void supprimer(noeud* arbre, noeud* n){
	noeud* y = NULL;
	if( n->filsG == NULL ){
		transplanter(&arbre, n, n->filsD);
	}
	else if( n->filsD == NULL ){
		transplanter(&arbre, n, n->filsG);
	}
	else{
		y = minimumArbre(n->filsD);
		if( y->pere != n ){
			transplanter(&arbre, n, n->filsD);
			y->filsD = n->filsD;
			y->filsD->pere = y;
		}
		transplanter(&arbre, n, y);
		y->filsG = n->filsG;
		y->filsG->pere = y;
	}
	detruireNoeud(n);
}
