#ifndef __graphe__
#define __graphe__

#include "tableListesAdjacences.h"

typedef struct{
	int nbSommets;
	int nbAretes;
	int oriente; //0 si non orienté, 1 sinon
	int value; //0 si non valué, 1 sinon
	int complet; //0 si non complet, 1 sinon
	tableListesAdjacences* listesAdjacences;
	int** matriceAdjacences;
}graphe;

void construireListesAdjacences (graphe*, FILE*);
void afficherListesAdjacences (graphe* g);

void construireMatriceAdjacences (graphe* g, FILE*);
void afficherMatriceAdjacences (graphe* g);


graphe* creerGraphe (FILE*);
void detruireGraphe (graphe*);

#endif
