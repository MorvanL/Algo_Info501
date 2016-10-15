#include <stdio.h>
#include <stdlib.h>
#include "sommetPcc.h"

sommetPcc* creerSommetPcc (int ind, int distance){
	sommetPcc* s = (sommetPcc*)malloc(sizeof(sommetPcc));
	s->indice = ind;
	s->d = distance;
	s->pere = NULL;
	s->indiceFile = 0;
	return s;
}
