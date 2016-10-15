#ifndef __liste__
#define __liste__
#include "cellule.h"

typedef struct{
	cellule* tete;
}liste;

liste creerListe ();
cellule* rechercher( liste*, char* );
void inserer( liste* , cellule* );
void supprimer( liste*, cellule* );
void detruireListe(liste*);

#endif
