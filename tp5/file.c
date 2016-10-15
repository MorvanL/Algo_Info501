#include <stdio.h>
#include <stdlib.h>
#include "file.h"

file* creerFile (int taille){
	file* f = (file*)malloc(sizeof(file));
	f->t = (sommetParcours**)malloc(sizeof(sommetParcours*)*taille);
	f->taille = taille;
	f->tete = 0;
	f->queue = 0;
	return f;
}

void detruireFile (file* f){
	free(f->t);	
}

int fileVide (file* f){
	int vide = 1;
	if(f->queue == f->tete){
		vide =0;
	}
	return vide;
}

void enfiler (file* f, sommetParcours* sp){
	(f->t)[f->queue] = sp;
	f->queue = (f->queue + 1)%(f->taille);
}

sommetParcours* defiler (file* f){
	sommetParcours* s = (f->t)[(f->tete)];
	f->tete = (f->tete + 1)%(f->taille);
	return(s);
}


