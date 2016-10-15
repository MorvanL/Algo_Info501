#ifndef __tableListesAdjacences__
#define __tableListesAdjacences__
#include "listeAdjacences.h"

typedef struct{
	listeAdjacences* t;
	int taille;
}tableListesAdjacences;

tableListesAdjacences* creerTableListesAdjacences (int);
void detruireTableListesAdjacences (tableListesAdjacences*);
void afficherTableListesAdjacences (tableListesAdjacences*);

#endif
