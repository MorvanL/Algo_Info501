#include <stdio.h>
#include <stdlib.h>
#include "sommetPrim.h"

sommetPrim* creerSommetPrim (int ind, int cle){
	sommetPrim* s = (sommetPrim*)malloc(sizeof(sommetPrim));
	s->indice = ind;
	s->cle = cle;
	s->pere = NULL;
	s->traite = 0;
	s->indiceFile = 0;
	return s;
}

