#ifndef __File_de_priorite__
#define __File_de_priorite__
#ifndef __Tache__
#define __Tache__
#include "sommetPcc.h"

typedef struct{
	int longueur;
	int taille;
	sommetPcc** t;
}File_de_priorite;

File_de_priorite creerFile (sommetPcc**, int nbSommets);
void echanger_sommet( sommetPcc** , sommetPcc** );
void Entasser_Min_file(File_de_priorite , int );
void construireFileMin( File_de_priorite );
sommetPcc* extraire_min_file(File_de_priorite*);
void diminuer_d_file(File_de_priorite , int , int );
void detruireFile (File_de_priorite );

#endif
#endif
