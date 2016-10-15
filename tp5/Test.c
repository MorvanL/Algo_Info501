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
	
	//Parcours en largeur
	int origine = atoi(argv[2]);
	int i;
	sommetParcours* parcoursLarg = parcoursLargeur(g, origine);
	printf("Parcours en largeur à partir du sommet %d :\n", origine);		
	for(i=0; i < g->nbSommets; i++){
		printf("pour le sommet %d : ", i);
		afficherChemin(parcoursLarg, origine, i);
		printf("\n");
	}
	printf("\n\n");

	//Parcours en profondeur
	sommetParcours* parcoursProf = parcoursProfondeur(g);
	printf("Parcours en profondeur :\n");
	afficherParcoursProfondeur(g->nbSommets, parcoursProf);

	free(parcoursLarg);
	free(parcoursProf);
	detruireGraphe(g);
	free(g);
	
	exit(0);
    
}













