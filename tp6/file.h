#ifndef __File_de_priorite__
#define __File_de_priorite__
#ifndef __Tache__
#define __Tache__
#include "sommetPrim.h"

typedef struct{
	int longueur;
	int taille;
	sommetPrim** t;
}File_de_priorite;

File_de_priorite creerFile (sommetPrim**, int nbSommets);
void echanger_sommet( sommetPrim** , sommetPrim** );
void Entasser_Min_file(File_de_priorite , int );
void construireFileMin( File_de_priorite );
sommetPrim* extraire_min_file(File_de_priorite*);
void diminuer_cle_file(File_de_priorite , int , int );
void detruireFile (File_de_priorite );

#endif
#endif
