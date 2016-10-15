#include "outilsPile.h"

typedef struct{
	Pile p1;
	Pile p2;
	Pile p3;
}Hanoi;

Hanoi creerHanoi (int);
void afficherHanoi (Hanoi*);
void deplacerDisque( int, int, Hanoi* );
