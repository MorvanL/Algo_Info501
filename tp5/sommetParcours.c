#include <stdio.h>
#include <stdlib.h>
#include "sommetParcours.h"

sommetParcours creerSommetParcours (int ind){
	sommetParcours sp;
	sp.couleur = "blanc";
	sp.date = 0;
	sp.fin = 0;
	sp.indice = ind;
	sp.pere = NULL;
	return sp;
}

