#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cellule.h"

cellule* creerCellule (char* mot){
	cellule* c = (cellule*)malloc(sizeof(cellule));
	c->mot = (char*)malloc(sizeof(char)*50);
	strcpy(c->mot, mot);
	c->pred = NULL;
	c->succ = NULL;
	return c;
}

void detruireCellule (cellule* c){
	free(c->mot);
}
