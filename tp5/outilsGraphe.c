#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outilsGraphe.h"

sommetParcours* parcoursLargeur (graphe* g, int sommetDepart){
	int i;
	file* f = creerFile(g->nbSommets);
	sommet* s;
	sommetParcours* sp;
	sommetParcours* spFils;
	//On créer le tableau de sommetParcours contenant les informations du parcours pour chaque sommet
	sommetParcours* sommet = (sommetParcours*)malloc(sizeof(sommetParcours)*g->nbSommets);
	for(i=0; i < g->nbSommets; i++){
		sommet[i] = creerSommetParcours(i);
	}
	//On initialise et enfile le premier sommet
	sommet[sommetDepart].couleur = "gris";
	sommet[sommetDepart].date = 0;
	enfiler(f, &(sommet[sommetDepart]) );
	//Tant que tout les sommets ne sont pas traités
	while( fileVide(f) != 0 ){
		sp = defiler(f);  //On récupère le prochain sommet à traité
		//On visite et enfile tout ses voisins
		s = ((g->listesAdjacences->t)[sp->indice]).tete;
		while( s != NULL ){
			spFils = &(sommet[s->indice]);
			if( strcmp(spFils->couleur, "blanc") == 0 ){
				spFils->couleur = "gris";
				spFils->date = (sp->date)+1;
				spFils->pere = sp;
				enfiler(f, spFils);
			}
			s = s->succ;
		}		
		sp->couleur = "noir";	//On marque le sommet traité
	}
	detruireFile(f);
	free(f);
	return sommet;
}

void afficherChemin (sommetParcours* sp, int sommetDepart, int sommetArrive){
	if(sommetDepart == sommetArrive){
		printf("%d", sommetDepart); 
	}
	else{
		if( sp[sommetArrive].pere == NULL ){	
			printf("aucun chemin entre ces deux sommets\n");
		}
		else{	//On remonte jusqu'au sommet de départ pour l'afficher en premier 
			afficherChemin(sp, sommetDepart, (sp[sommetArrive].pere)->indice);
			printf("->%d", sommetArrive);			
		}
	}
}

sommetParcours* parcoursProfondeur (graphe* g){
	int i;
	int date = 0;
	//On créer la forêt du parcours contenant les informations de chaque sommet
	sommetParcours* foret = (sommetParcours*)malloc(sizeof(sommetParcours)*g->nbSommets);
	for(i=0; i < g->nbSommets; i++){
		foret[i] = creerSommetParcours(i);
	}
	//Pour chaque sommet non visité on visite ses voisins
	for(i=0; i < g->nbSommets; i++){
		if( strcmp(foret[i].couleur, "blanc") == 0 ){
			visiter_pp(g, foret, &(foret[i]), &date);
		}
	}
	return(foret);
}

void visiter_pp (graphe* g, sommetParcours* foret, sommetParcours* sp, int* date){
	sommet* s;
	sommetParcours* spFils;
	*date = *date+1;
	sp->date = *date;	//On met à jour sa date de découverte
	sp->couleur = "gris";	//Et on l'indique visité
	//On visite chacun de ses voisins
	s = ((g->listesAdjacences->t)[sp->indice]).tete;
	while( s != NULL ){
		//On visite tout les voisins de ses voisins non déjà visité
		spFils = &(foret[s->indice]);
		if( strcmp(spFils->couleur, "blanc") == 0 ){
			spFils->pere = sp;	//On le note comme père des ces voisins
			visiter_pp(g, foret, spFils, date);
		}
		s = s->succ;
	}		
	sp->couleur = "noir";	//On l'indique traité 
	*date = *date+1;	
	sp->fin = *date;	//On met à jour sa date de fin de traitement
}

void afficherParcoursProfondeur (int nbSommets, sommetParcours* sp){
	int i;
	for(i=0; i < nbSommets; i++){
		printf("sommet %d : découvert en %d traités en %d\n", i, sp[i].date, sp[i].fin);
	}
}





















