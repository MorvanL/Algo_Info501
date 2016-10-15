#include <stdio.h>
#include <stdlib.h>
#include "outilsArbre.h"

void afficherArbreTrieRecursif (noeud* arbre){
	if( arbre != NULL ){
		afficherArbreTrieRecursif(arbre->filsG);
		printf("%s\n", arbre->mot);
		afficherArbreTrieRecursif(arbre->filsD);
	}	
}

void afficherArbreIteratif(noeud* arbre){
	Pile p = creerPile(50);
	noeud* n = arbre;
	if( n != NULL ){
		empiler(&p, n);
		while( pileVide(&p) == 1 ){
			n = depiler(&p);
			printf("%s\n", n->mot);
			if( n->filsD != NULL ){
				empiler(&p, n->filsD);
			}
			if( n->filsG != NULL ){
				empiler(&p, n->filsG);
			}
		}
	}
}

int compterArbre (noeud* arbre, int* cpt){
	if(arbre != NULL){
		*cpt = *cpt+1;
		compterArbre(arbre->filsG, cpt);
		compterArbre(arbre->filsD, cpt);
	}
	return *cpt;
}

noeud* minimumArbre (noeud* arbre){
	noeud* n = arbre;
	while( n->filsG != NULL ){
		n = n->filsG;
	}
	return n;
}

void transplanter (noeud** arbre, noeud* u, noeud* v){
	if( u->pere == NULL ){
		*arbre = v;
	}
	else if( u == u->pere->filsG ){
		u->pere->filsG = v;
	}
	else{
		u->pere->filsD = v;
	}
	if( v != NULL ){
		v->pere = u->pere;
	}
}
