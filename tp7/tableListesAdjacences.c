#include <stdio.h>
#include <stdlib.h>
#include "tableListesAdjacences.h"

tableListesAdjacences* creerTableListesAdjacences (int nbSommets){
	int i;
	tableListesAdjacences* table = (tableListesAdjacences*)malloc(sizeof(tableListesAdjacences));
	table->taille = nbSommets;
	table->t = (listeAdjacences*)malloc(nbSommets*sizeof(listeAdjacences));
	for(i=0; i<nbSommets; i++){
		(table->t)[i] = creerListeAdjacences();
	}
	return table;
}

void detruireTableListesAdjacences (tableListesAdjacences* tla){
	int i;
	for(i=0; i<tla->taille; i++){
		//On détruit chaque liste d'adjacences
		detruireListeAdjacences( &((tla->t)[i]) );
	}
	//Ainsi que la table, c'est à dire le pointeur sur ces listes
	free(tla->t);
}

void afficherTableListesAdjacences (tableListesAdjacences* tla){
	int i;
	for(i=0; i < (tla->taille); i++){
		printf("%d", i);
		afficherListeAdjacences( &(tla->t)[i] );
	} 
}
