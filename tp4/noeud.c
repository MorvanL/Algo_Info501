#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noeud.h"

noeud* creerNoeud (char* ch){
	noeud* n = (noeud*)malloc(sizeof(noeud));
	n->mot = (char*)malloc(sizeof(char)*50);
	strcpy(n->mot, ch);
	n->pere = NULL;
	n->filsG = NULL;
	n->filsD = NULL;
	return n;
}

void detruireNoeud (noeud* n){
	free(n->mot);
}
