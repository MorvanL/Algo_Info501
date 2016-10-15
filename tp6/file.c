#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "util.h"

File_de_priorite creerFile (sommetPrim** sommetsGraphe, int nbSommets){
	int i;
	File_de_priorite file;
	file.longueur = nbSommets;
	file.taille = nbSommets;
	//On copie chaque pointeur de sommetsGraphe pour ne pas changer l'ordre des sommets dans sommetsGraphe par la suite;
	file.t = (sommetPrim**)malloc(sizeof(sommetPrim*)*nbSommets);
	for(i=0; i<nbSommets; i++){
		(file.t)[i] = sommetsGraphe[i];
		(file.t)[i]->indiceFile = i;
	}
	return file;
}

void echanger_sommet( sommetPrim** t1, sommetPrim** t2 ){
	int indFileTmp;
	sommetPrim* tmp;
	indFileTmp = (*t1)->indiceFile;
	tmp = *t1;
	(*t1)->indiceFile = (*t2)->indiceFile;
	*t1=*t2;
	(*t2)->indiceFile = indFileTmp;
	*t2=tmp;
}

void Entasser_Min_file(File_de_priorite file, int i){
	int d,g, min;
	g=gauche(i);
	d=droite(i);
	if( g < file.taille   &&   ((file.t)[g])->cle < ((file.t)[i])->cle ){
		min = g;
			
	}
	else{
		min = i;
	}
	if( d < file.taille   &&   ((file.t)[d])->cle < ((file.t)[min])->cle ){
		min = d;	
	}
	if(min != i){
		echanger_sommet( &((file.t)[i]), &((file.t)[min]) );
		Entasser_Min_file(file,min);
	}
}

void construireFileMin( File_de_priorite file ){
	int i;
	for(i=(file.longueur)/2; i>=0; i--){
		Entasser_Min_file(file, i);
	}
}

sommetPrim* extraire_min_file(File_de_priorite* file){
	sommetPrim* s;
	if(file->taille < 1){
		printf("Erreur limite inférieur dépassée");
	}
	s = (file->t)[0];
	echanger_sommet( &((file->t)[0]), &((file->t)[file->taille-1]) );
	file->taille--;
	Entasser_Min_file(*file, 0);
	return s;  
}


void diminuer_cle_file(File_de_priorite file, int i, int cle){
	((file.t)[i])->cle = cle;
	while( ((file.t)[i])->cle < ((file.t)[parent(i)])->cle ){
		echanger_sommet( &((file.t)[i]), &((file.t)[parent(i)]) );
		i = parent(i);
	}
}

void detruireFile (File_de_priorite file){
	free(file.t);
}

