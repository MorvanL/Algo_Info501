#include <stdio.h>
#include <stdlib.h>
#include "outilsGraphe.h"

int main (int argc, char *argv[]){

	int i, choix;
	int sommetDepart = atoi(argv[2]);
	FILE* fic = fopen(argv[1], "r");
	printf("Entrer 1 pour Dijkstra, 2 pour Bellman-Ford\n");
	scanf("%d", &choix);
	
	//Creation et affichage du graphe
	graphe* g = creerGraphe(fic);
	printf("\nListes d'ajacences : \n");
	afficherListesAdjacences(g);
	printf("\n\n Matrice d'ajacences : \n");
	afficherMatriceAdjacences(g);
	printf("\n\n");

	if(choix == 1){
		//Dijkstra
	  	sommetPcc** pccDijkstra = Dijkstra(g, sommetDepart);
		printf("Pcc Dijkstra à partir du sommet %d : \n", sommetDepart);
		for(i=0; i < g->nbSommets; i++){
			printf("Jusqu'à %d : ", i);
			afficherPcc (pccDijkstra, sommetDepart, i);
			printf("\n");
		}
		detruirePcc( &pccDijkstra, g->nbSommets);
		printf("\n\n");
		//pcc_tous_a_tous (g);
		printf("\n\n");
	}
	else if(choix == 2){  
		//Bellman-Ford
		sommetPcc*** pccBF = (sommetPcc***)malloc(sizeof(sommetPcc**));
		if( Bellman_Ford(g, sommetDepart, pccBF) == 0 ){
			printf("Pcc Bellman-Ford à partir du sommet %d : \n", sommetDepart);
			for(i=0; i < g->nbSommets; i++){
				printf("Jusqu'à %d : ", i);
				afficherPcc (*pccBF, sommetDepart, i);
				printf("\n");
			}
		}
		else{
			printf("Il existe un circuit de poids strictement négatif à partir du sommet %d\n", sommetDepart);
		}
		detruirePcc(pccBF, g->nbSommets);
		free(pccBF);
	}

	detruireGraphe(g);
	free(g);

	exit(0); 
}













