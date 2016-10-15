#ifndef __sommetPrim__
#define __sommetPrim__

typedef struct sommetPrim_type{
	int indiceFile; //permet de savoir à quelle indice se trouve le sommet dans la file.
	int traite; //1 si traité 0 sinon
	int indice;
	int cle;
	struct sommetPrim_type* pere;
}sommetPrim;

sommetPrim* creerSommetPrim (int, int);

#endif
