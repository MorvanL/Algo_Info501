#ifndef __listeAdjacences__
#define __listeAdjacences__
#include "sommet.h"

typedef struct{
	sommet* tete;
}listeAdjacences;

listeAdjacences creerListeAdjacences ();
sommet* rechercher( listeAdjacences*, int );
void inserer( listeAdjacences* , sommet* );
void supprimer( listeAdjacences*, sommet* );
void detruireListeAdjacences (listeAdjacences*);
void afficherListeAdjacences (listeAdjacences*);

#endif
