#include <stdio.h>
#include <stdlib.h>
#include "outilsGraphe.h"

int main (int argc, char *argv[]){

	FILE* fic = fopen(argv[1], "r");
	
	//Creation et affichage du graphe
	graphe* g = creerGraphe(fic);
	printf("\nListes d'ajacences : \n");
	afficherListesAdjacences(g);
	printf("\n\n Matrice d'ajacences : \n");
	afficherMatriceAdjacences(g);
	printf("\n\n");

	//Kruskal
	arete** acpmKruskal = genererAcpmKruskal(g);
	afficherAcpmKruskal (acpmKruskal, g->nbSommets);
	detruireAcpmKruskal( &(acpmKruskal), g->nbSommets );
	printf("\n\n");

	//Prim
	File_de_priorite acpmPrim = genererAcpmPrim(g);
	afficherAcpmPrim (acpmPrim, g->nbSommets);
	detruireAcpmPrim( acpmPrim, g->nbSommets );

	detruireGraphe(g);
	free(g);

	exit(0); 
}













