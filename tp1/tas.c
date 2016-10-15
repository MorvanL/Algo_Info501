#include <stdio.h>
#include <stdlib.h>
#include "tas.h"
#include "util.h"



void Entasser_Max(tas_t tas, int i){
	int d,g, max;
	g=gauche(i);
	d=droite(i);
	if( g < tas.taille   &&   (tas.t)[g] > (tas.t)[i] ){
		max = g;	
	}
	else{
		max = i;
	}
	if( d < tas.taille   &&   (tas.t)[d] > (tas.t)[max] ){
		max = d;	
	}
	if(max != i){
		echanger(&((tas.t)[i]), &((tas.t)[max]));
		Entasser_Max(tas,max);
	}
}

void construireTasMax(tas_t tas){
	int i;
	for(i=(tas.longueur)/2; i>=0; i--){
		Entasser_Max(tas, i);
	}
}

void tri_par_tas(tas_t tas){
	int i,j;
	tas.taille = tas.longueur;
	construireTasMax(tas);
	for(i=tas.longueur; i>0; i--){
		echanger(&((tas.t)[0]), &((tas.t)[i-1]));
		tas.taille--;
		Entasser_Max(tas, 0);
	}
}

void afficherTas(tas_t tas){
	int i;
	for(i=0; i<tas.taille-1; i++){
		printf("%d  ",(tas.t)[i]);
	}
}


