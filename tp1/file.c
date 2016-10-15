#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "util.h"

void echanger_tache( Tache** t1, Tache** t2 ){
	Tache* tmp;
	tmp = *t1;
	*t1=*t2;
	*t2=tmp;
}

void Entasser_Max_file(File_de_priorite file, int i){
	int d,g, max;
	g=gauche(i);
	d=droite(i);
	if( g < file.taille   &&   (*((file.t)[g])).priorite > (*((file.t)[i])).priorite ){
		max = g;
			
	}
	else{
		max = i;
	}
	if( d < file.taille   &&   (*((file.t)[d])).priorite > (*((file.t)[max])).priorite ){
		max = d;	
	}
	if(max != i){
		echanger_tache( &((file.t)[i]), &((file.t)[max]) );
		Entasser_Max_file(file,max);
	}
}

void construireFileMax( File_de_priorite file ){
	int i;
	for(i=(file.longueur)/2; i>=0; i--){
		Entasser_Max_file(file, i);
	}
}



Tache extraire_max_file(File_de_priorite file){
	Tache max;
	if(file.taille < 1){
		printf("Erreur limite inférieur dépassée");
	}
	max = *((file.t)[0]);
	(file.t)[0] = (file.t)[file.taille-1];
	file.taille--;
	Entasser_Max_file(file, 0);
	return max;  
}

void inserer_cle_file(File_de_priorite file, Tache* cle){
	int i;
	(file.t)[file.taille-1] = cle;
	i = file.taille-1;
	file.taille++;
	while( (*((file.t)[i])).priorite > (*((file.t)[parent(i)])).priorite ){
		echanger_tache( &((file.t)[i]), &((file.t)[parent(i)]) );
		i = parent(i);
	}
}

void augmenter_cle_file(File_de_priorite file, int i, int priorite){
	(*((file.t)[i])).priorite = priorite;
	while( (*((file.t)[i])).priorite > (*((file.t)[parent(i)])).priorite ){
		echanger_tache( &((file.t)[i]), &((file.t)[parent(i)]) );
		i = parent(i);
	}
}

void AfficherTache( Tache t ){
	printf("%s : %d", t.intitule, t.priorite);
}
void Afficher_file_de_priorite( File_de_priorite file ){
	int i;
	for(i=0; i<file.taille-1; i++){
		AfficherTache( *((file.t)[i]) );
		printf("\n");
	}
}
