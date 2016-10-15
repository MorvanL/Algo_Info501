#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outilsGraphe.h"

sommetPcc** source_unique_initialisation(graphe* g, int sommetDepart){
	int i;
	sommetPcc** pcc = (sommetPcc**)malloc(sizeof(sommetPcc*)*(g->nbSommets));
	//On initialise les sommets avec un majorant pour la distance à l'origine
	for(i=0; i < g->nbSommets; i++){
		pcc[i] = creerSommetPcc(i, 1000000000);
	}
	pcc[sommetDepart]->d = 0; //On met à 0 la distance du sommet de depart
	return pcc;
}

void afficherPcc (sommetPcc** pcc, int sommetDepart, int sommetArrive){
	if(sommetDepart == pcc[sommetArrive]->indice){
		printf("%d", sommetDepart); 
	}
	else{
		if( pcc[sommetArrive]->pere == NULL ){	
			printf("aucun chemin entre ces deux sommets\n");
		}
		else{	//On remonte jusqu'au sommet de départ pour l'afficher en premier 
			afficherPcc(pcc, sommetDepart, pcc[sommetArrive]->pere->indice);
			printf("->%d", sommetArrive);			
		}
	}
}

void detruirePcc(sommetPcc*** pcc, int nbSommets){
	int i;
	//On détruit l'espace alloué pour chaque sommetPcc
	for(i=0; i<nbSommets; i++){
		free( (*pcc)[i] );
	}
	//On détruit l'espace alloué pour le pointeur de pointeurs de sommetPcc contenant les informations de l'algorithme
	free(*pcc);
}



void relacherDijkstra (sommetPcc* u, sommetPcc* v, int poidsArete, File_de_priorite* file){
	if( v->d > (u->d + poidsArete) ){ 
		diminuer_d_file(*file, v->indiceFile, (u->d + poidsArete));
		v->pere = u;
	}
}

sommetPcc** Dijkstra (graphe* g, int sommetDepart){
	int i;
	sommet* v;
	sommetPcc* u;
	sommetPcc** pccDijkstra = source_unique_initialisation(g, sommetDepart); //Permet de stocker les sommets et les informations nécessaires à l'algorithme
	//On construit la file de sommets de priorité minimum
	File_de_priorite file = creerFile(pccDijkstra, g->nbSommets);
	construireFileMin(file);
	//Tant que tout les sommets ne sont pas traités
	while(file.taille > 1){
		u = extraire_min_file(&file);
		//On parcours la liste d'adjacences du sommet que l'on traite pour mettre à jour ses voisins
		v = ((g->listesAdjacences->t)[u->indice]).tete;
		while( v != NULL ){
			relacherDijkstra( pccDijkstra[u->indice], pccDijkstra[v->indice], v->valeurArete, &file );
			v = v->succ;
		}
	}
	detruireFile(file);
	return pccDijkstra;
}

void pcc_tous_a_tous (graphe* g){
	int i, j;
	sommetPcc** pccDijkstra;
	//Pour chaque sommet on effectue Dijkstra et on affiche le pcc entre ce sommet et tout les autres sommets
	for(i=0; i < g->nbSommets; i++){
		pccDijkstra = Dijkstra(g, i);
		printf("Pcc Dijkstra à partir du sommet %d : \n", i);
		for(j=0; j < g->nbSommets; j++){
			printf("Jusqu'à %d : ", i);
			afficherPcc (pccDijkstra, i, j);
			printf("\n");
		}
		detruirePcc( &pccDijkstra, g->nbSommets);
		printf("\n");
	}
}



void relacherBF (sommetPcc* u, sommetPcc* v, int poidsArete){
	if( v->d > (u->d + poidsArete) ){ 
		v->d = (u->d + poidsArete);
		v->pere = u;
	}
}

int Bellman_Ford (graphe* g, int sommetDepart, sommetPcc*** pccBF){
	int i, j, k;
	sommet* s;
	int circuitNegatif = 0;
	*pccBF = source_unique_initialisation(g, sommetDepart); // "pccBF" Permet de stocker les sommets et les informations nécessaires à l'algorithme
	//On relache chaque arc nbSommets-1 fois
	for(i=0; i < g->nbSommets-1; i++){
		for(j=0; j < g->nbSommets; j++){
			s = ((g->listesAdjacences->t)[j]).tete;
			while( s != NULL){
				relacherBF((*pccBF)[j], (*pccBF)[s->indice], s->valeurArete); 
				s = s->succ;
			}
		}
	} 
	//Si des arcs peuvent encore être relachés à là nième itération alors le graphe possède un circuit de poids strictement négatif
	for(k=0; k < g->nbSommets; k++){
		s = ((g->listesAdjacences->t)[k]).tete;
		while( s != NULL){
			if( (*pccBF)[s->indice]->d > ( (*pccBF)[k]->d + s->valeurArete) ){
				circuitNegatif = 1;
			} 
			s = s->succ;
		}
	}
	return circuitNegatif;
}



























