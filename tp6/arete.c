#include <stdio.h>
#include <stdlib.h>
#include "arete.h"

arete* creerArete (int sommet1, int sommet2, int valArete){
	arete* a = (arete*)malloc(sizeof(arete));;
	a->s1 = sommet1;
	a->s2 = sommet2;
	a->valeur = valArete;
	return a;
}


