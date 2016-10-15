#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outilsGraphe.h"
#include "tas.h"


arete** genererAcpmKruskal (graphe* g){
	int i, j=0, k=0;
	sommet* s;
	arete** aretesGraphe = (arete**)malloc(sizeof(arete*)*(g->nbAretes)); 
	arete** aretesRetenues = (arete**)malloc( sizeof(arete*)*((g->nbSommets)-1) );	//ensemble des arêtes retenues pour construire l'arbre
	composante* composantes = (composante*)malloc(sizeof(composante)*(g->nbSommets));	//représente les sommets du graphe dans les ensembles
	ensemble** ensembles = (ensemble**)malloc(sizeof(ensemble*)*(g->nbSommets));
	// Pour chaque sommet on créer la composante le représentant
	for(i=0; i<g->nbSommets; i++){
		composantes[i] = creerComposante(i);
	}
	// Pour chaque composante(sommet) on créer un ensemble dont elle est l'unique constituant
	for(i=0; i<g->nbSommets; i++){
		ensembles[i] = creerEnsemble(&(composantes[i]));
	}
	// On parcours la liste d'adjacence de chaque sommet sauf le dernier afin de récupérer les arretes du graphe
	for(i=0; i<g->nbSommets-1; i++){
		s = ((g->listesAdjacences->t)[i]).tete;
		// On s'arrete si "s->indice < i" pour ne pas récupérer deux fois les arêtes puisque le graphe est non orienté. D'où le fait que l'on ne traite pas le dernier sommet
		while( s != NULL  &&  s->indice > i){
			aretesGraphe[j] = creerArete(i, s->indice, s->valeurArete);
			s = s->succ;
			j++;
		}
	}
	// On trie le tableau des aretes du graphe avec le tri par tas
	tri_par_tas(aretesGraphe, g->nbAretes);
	// On regarde pour chaque arete si elle doit être retenue dans l'arbre de poids minimal
	for(i=0; i < g->nbAretes; i++){
		// On vérifie si les 2 sommets de l'arete ne font pas déjà partie du même ensemble (s'ils sont déjà lié ou non)
		if(  trouverEnsemble( &(composantes[aretesGraphe[i]->s1]) )   !=   trouverEnsemble( &(composantes[aretesGraphe[i]->s2]) )  ){
			aretesRetenues[k] = aretesGraphe[i];
			k++;
			Union( &(composantes[aretesGraphe[i]->s1]), &(composantes[aretesGraphe[i]->s2]) );
		}
		//si l'arete n'est pas retenue on libère son espace
		else{
			free(aretesGraphe[i]);
		}
	}
	free(composantes);
	//on libère les espaces alloués pour chaque ensemble
	for(i=0; i < g->nbSommets; i++){
		free(ensembles[i]);
	}
	free(ensembles);
	free(aretesGraphe);	
	return aretesRetenues;
}


void afficherAcpmKruskal (arete** acpm, int nbSommets){
	int i;
	printf("Acpm Kruskal : \n");
	printf("aretes retenues     poids \n");
	for(i=0; i<nbSommets-1; i++){
		printf("   %d-%d               %d\n", acpm[i]->s1, acpm[i]->s2, acpm[i]->valeur);
	}
}

void detruireAcpmKruskal (arete*** acpm, int nbSommets){
	int i;
	//On libère l'espace des arêtes retenues
	for(i=0; i<nbSommets; i++){
		free( (*acpm)[i] );
	}
	//On libère le tableau d'arêtes retenues
	free(*acpm);
}

/* On choisi de retourner directement la file de priorité utilisée pendant l'alogorithme plutôt qu'un tableau d'arêtes pour limiter l'espace mémoire utilisé.
Si nou avions voulu utiliser un tableau d'arêtes il suffisait de créer la nouvelle arête retenue après chaque "extraire_min_file" à l'exception du premier "extraire_min_file" */
File_de_priorite genererAcpmPrim (graphe* g){
	int i;
	sommet* v;
	sommetPrim* u;
	sommetPrim** sommetsGraphe = (sommetPrim**)malloc(sizeof(sommetPrim*)*(g->nbSommets)); //Permet de stocker les sommets et les informations nécessaires à l'algorithme
	// On initialise les sommets
	for(i=0; i < g->nbSommets; i++){
		sommetsGraphe[i] = creerSommetPrim(i, 2147483647);
	}
	sommetsGraphe[0]->cle = 0; //On utilise le sommet 0 comme point de départ
	//On construit la file de sommets de priorité minimum
	File_de_priorite file = creerFile(sommetsGraphe, g->nbSommets);
	construireFileMin(file);	//Utile que si l'on utilise pas le sommet 0 comme point de départ
	while(file.taille > 1){
		u = extraire_min_file(&file);
		u->traite = 1;
		//On parcours la liste d'adjacences du dernier sommet ajouté à l'arbre pour mettre à jour ses voisins
		v = ((g->listesAdjacences->t)[u->indice]).tete;
		while( v != NULL ){
			if( (sommetsGraphe[v->indice]->traite == 0)   &&   (v->valeurArete < sommetsGraphe[v->indice]->cle) ){
				sommetsGraphe[v->indice]->pere = u;
				diminuer_cle_file(file, sommetsGraphe[v->indice]->indiceFile, v->valeurArete);
			}
			v = v->succ;
		}
	}
	free(sommetsGraphe);
	return file;
}

void afficherAcpmPrim (File_de_priorite acpm, int nbSommets){
	int i;
	printf("Acpm Prim : \n");
	printf("aretes retenues     poids \n");
	for(i=nbSommets-2; i>=0; i--){
		printf("   %d-%d               %d\n", (acpm.t)[i]->pere->indice, (acpm.t)[i]->indice, (acpm.t)[i]->cle);
	}
}

void detruireAcpmPrim (File_de_priorite acpm, int nbSommets){
	int i;
	//On détruit l'espace alloué pour chaque sommetPrim
	for(i=0; i<nbSommets; i++){
		free( (acpm.t)[i] );
	}
	//On détruit l'espace alloué pour le pointeur de pointeurs de sommet dans la file
	detruireFile(acpm);
}
























