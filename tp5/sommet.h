#ifndef __sommet__
#define __sommet__

typedef struct sommet_type{
	int indice;
	int valeurArete;
	struct sommet_type* pred;
	struct sommet_type* succ;
}sommet;

sommet* creerSommet (int, int);

#endif
