#ifndef __Pile__
#define __Pile__
#include "noeud.h"

typedef struct{
	int sommet;
	int capacite;
	noeud** p;
}Pile;

Pile creerPile(int);
void detruirePile(Pile*);
int pileVide(Pile*);
int pilePleine(Pile*);
void empiler(Pile*, noeud*);
noeud* depiler(Pile*);

#endif
