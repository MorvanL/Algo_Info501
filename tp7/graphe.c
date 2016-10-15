#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

void construireListesAdjacences (graphe* g, FILE* fic){  	
	int i, j, valeurArete=0;
	char* ch = (char*)malloc(sizeof(char)*15);
	g->listesAdjacences = creerTableListesAdjacences(g->nbSommets);	
	fscanf(fic, "%s", ch);
	//On lit chaque arête
	while( strcmp(ch, "finDefAretes") != 0 ){
		i = atoi(ch);
		fscanf(fic, "%d", &j);
		//Si le graphe est valué alors on lit la valeur de l'arête
		if(g->value != 0){
			fscanf(fic, "%d", &valeurArete);
		}
		inserer( &((g->listesAdjacences->t)[i]) , creerSommet (j, valeurArete) );
		g->nbAretes += 1;
		//Si le graphe est orienté alors on créer l'arête dans la liste d'adjacence du 2ème sommet la constituant
		if(g->oriente == 0){
			inserer( &((g->listesAdjacences->t)[j]) , creerSommet (i, valeurArete) );
		}
		fscanf(fic, "%s", ch);	
	}
	free(ch);
}

void afficherListesAdjacences (graphe* g){
	afficherTableListesAdjacences(g->listesAdjacences);
}

void construireMatriceAdjacences (graphe* g, FILE* fic){
	int i, j, valeurArete=0;
	char* ch = (char*)malloc(sizeof(char)*15);
	g->matriceAdjacences = (int**)malloc(sizeof(int*)*(g->nbSommets));
	for(i=0; i < g->nbSommets; i++){
		(g->matriceAdjacences)[i] = (int*)malloc(sizeof(int)*(g->nbSommets));
	}
	fscanf(fic, "%s", ch);
	while( strcmp(ch, "finDefAretes") != 0 ){
		i = atoi(ch);
		fscanf(fic, "%d", &j);
		if(g->value != 0){
			fscanf(fic, "%d", &valeurArete);
			(g->matriceAdjacences)[i][j] = valeurArete;
		}
		else{
			(g->matriceAdjacences)[i][j] = 1;
		}
		if(g->oriente == 0){
			if(g->value != 0){
				(g->matriceAdjacences)[j][i] = valeurArete;
			}
			else{
				(g->matriceAdjacences)[j][i] = 1;
			}
		}
		fscanf(fic, "%s", ch);	
	}
	free(ch);
}

void afficherMatriceAdjacences (graphe* g){
	int i,j;
	printf("    ");
	for(j=0; j < g->nbSommets; j++){
		printf("    %d", j);
	}
	printf("\n\n");
	for(i=0; i < g->nbSommets; i++){
		printf("%d   ", i);
		for(j=0; j < g->nbSommets; j++){
			printf("    %d", (g->matriceAdjacences)[i][j] );
		}
		printf("\n");
	}
}


graphe* creerGraphe (FILE* fic){
	graphe* g = (graphe*)malloc(sizeof(graphe));
	char* ch =(char*)malloc(sizeof(char)*20);
	long position;	
	g->nbAretes = 0;
	fscanf( fic, "%s %d ", ch, &(g->nbSommets) );
	fscanf( fic, "%s %d ", ch, &(g->oriente) );
	fscanf( fic, "%s %d ", ch, &(g->value) );
	fscanf( fic, "%s %d ", ch, &(g->complet) );
	fscanf( fic, "%s", ch );
	position = ftell(fic);	//On récupère la postion du début de la définition des arêtes

	construireListesAdjacences( g, fic);
	
	fseek(fic, position, 0); //On revient à la position du début de la définition des arêtes
	
	construireMatriceAdjacences (g, fic);

	free(ch);

	return g;
}

void detruireGraphe (graphe* g){
	int i;
	//On détruit la table de listes d'adjacences
	detruireTableListesAdjacences( g->listesAdjacences );
	//Ainsi que le pointeur sur celle-ci
	free(g->listesAdjacences);
	
	//On libère chaque ligne de la matrice d'adjacence
	for(i=0; i < g->nbSommets; i++){
		free(g->matriceAdjacences[i]);
	}
	//Ainsi que le pointeur sur ces lignes
	free(g->matriceAdjacences);
}
