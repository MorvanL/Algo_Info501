#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"

sommet* creerSommet (int ind, int valArete  ){
	sommet* s = (sommet*)malloc(sizeof(sommet));
	s->indice = ind;
	s->valeurArete = valArete;
	s->pred = NULL;
	s->succ = NULL;
	return s;
}

