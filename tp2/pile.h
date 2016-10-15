#ifndef __Pile__
#define __Pile__

typedef struct{
	int sommet;
	int capacite;
	int* p;
}Pile;

Pile creerPile(int);
void detruirePile(Pile*);
int capacitePile(Pile*);
int pileVide(Pile*);
int pilePleine(Pile*);
void empiler(Pile*, int);
int depiler(Pile*);
int sommet(Pile*);

#endif
