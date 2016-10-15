#ifndef __file__
#define __file__
#include "sommetParcours.h"

typedef struct{
	int tete;
	int queue;
	int taille;
	sommetParcours** t;
}file;

file* creerFile (int taille);
void detruireFile (file*);
int fileVide (file*); //retourne 0 si vide, 1 si non vide
void enfiler (file*, sommetParcours*);
sommetParcours* defiler (file*);

#endif
