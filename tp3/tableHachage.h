#ifndef __tableHachage__
#define __tableHachage__
#include "outilsListe.h"

typedef struct{
	liste* t;
	int taille;
}tableHachage;

tableHachage* creerTableHachage (int);
void detruireTableHachage (tableHachage*);

#endif
