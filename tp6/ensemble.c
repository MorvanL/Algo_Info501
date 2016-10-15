#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

ensemble* creerEnsemble ( composante* c){
	ensemble* e = (ensemble*)malloc(sizeof(ensemble));
	e->tete = c;
	e->queue = c;
	c->ens = e;
	return e;
}	

composante* trouverEnsemble (composante* c){						
	return( c->ens->tete );
}

void Union(composante* c1,composante* c2){
	composante* tmp = c2->ens->tete;
	c1->ens->queue->succ = tmp;
	c1->ens->queue = c2->ens->queue;
	while( tmp != NULL ){
		tmp->ens = c1->ens;
		tmp = tmp->succ;
	}
}

