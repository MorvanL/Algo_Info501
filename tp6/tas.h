#ifndef __tas_t__
#define __tas_t__
#include "arete.h"

typedef struct{
	int longueur;
	int taille;
	arete** t;
}tas_t;

tas_t creerTas( arete**, int ); //créer un tas contenant les aretes du graphe 
void echanger(arete** , arete** );
void Entasser_Max(tas_t , int );
void construireTasMax(tas_t );
void tri_par_tas(arete **, int );

#endif
