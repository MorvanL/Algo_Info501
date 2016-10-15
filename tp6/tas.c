#include <stdio.h>
#include <stdlib.h>
#include "tas.h"
#include "util.h"

tas_t creerTas( arete** aretesGraphe, int nbAretes ){
	tas_t tas;
	tas.longueur = nbAretes;
	tas.taille = nbAretes;
	tas.t = aretesGraphe;
	return tas;
}

void echanger(arete** a, arete** b){
	arete* tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Entasser_Max(tas_t tas, int i){
	int d,g, max;
	g=gauche(i);
	d=droite(i);
	if( g < tas.taille   &&   ((tas.t)[g])->valeur > ((tas.t)[i])->valeur ){
		max = g;	
	}
	else{
		max = i;
	}
	if( d < tas.taille   &&   ((tas.t)[d])->valeur > ((tas.t)[max])->valeur ){
		max = d;	
	}
	if(max != i){
		echanger(&((tas.t)[i]), &((tas.t)[max]));
		Entasser_Max(tas,max);
	}
}

void construireTasMax(tas_t tas){
	int i;
	for(i=(tas.longueur); i>=0; i--){
		Entasser_Max(tas, i);
	}
}

void tri_par_tas(arete** aretesGraphe, int nbAretes){
	tas_t tas = creerTas(aretesGraphe, nbAretes);
	int i,j;
	construireTasMax(tas);
	for(i=tas.longueur; i>0; i--){
		echanger(&((tas.t)[0]), &((tas.t)[i-1]));
		tas.taille--;
		Entasser_Max(tas, 0);
	}
}



