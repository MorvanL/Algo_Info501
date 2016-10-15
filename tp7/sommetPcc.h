#ifndef __sommetPcc__
#define __sommetPcc__

typedef struct sommetPcc_type{
	int indiceFile; //permet de savoir à quelle indice se trouve le sommet dans la file.
	int indice;
	int d;      //distance du sommet à l'origine du parcours
	struct sommetPcc_type* pere;
}sommetPcc;

sommetPcc* creerSommetPcc (int, int);

#endif
