#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tri.h"
#include "tas.h"
#include "util.h"
#include "file.h"


int main ( ){
	int i =0,j;
	int *t;
	int taille;
	tas_t tas;
	
	

	
   /*	FILE* fic = fopen("donnesTab1.txt", "r");  
   	fscanf(fic, "%d ", &taille);			/////tri par insertion avec fichier//////
	t = malloc(taille*(sizeof(int)));
	while(fscanf(fic, "%d ", &(t[i])) != EOF){
			i+=1;
	}
	TriInsertion(t, taille);
   	

	fscanf( fic, "%d ", &(tas.longueur) );		/////tri par tas avec fichier//////
	tas.t = malloc( (tas.longueur)*(sizeof(int)) );
	while(fscanf(fic, "%d ", &((tas.t)[i])) != EOF){
			i+=1;
	}
	tri_par_tas(tas);
	afficherTas(tas);
	fclose(fic);   
   */
	

   /*   float temps;				//////comparaison temps tri par insertion/tri par tas à partir du meme tableau///////
    	clock_t t1, t2;
	int n = 1000000;
	t = creerTabAleatoire(n);		

	tas.t = malloc( (n)*(sizeof(int)) );
	tas.longueur = n;
	for(i=0; i<n; i++){
		(tas.t)[i] = t[i];
	}

	t1 = clock();
	TriInsertion(t, n);
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("%f \n", temps);

	t1 = clock();
	tri_par_tas(tas);
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("%f \n", temps);

   */

   	File_de_priorite file;				//////file de priorite/////////
	Tache* cle = malloc(sizeof(Tache));
	FILE* fic = fopen("listeTaches1.txt", "r");
	fscanf(fic, "%d", &(file.longueur));			//tri par insertion avec fichier
	file.taille = file.longueur;	
	file.t = malloc( (file.longueur + 5)*(sizeof(Tache*))); //+5 pour pouvoir rajouter des taches
	for(j=0; j < (file.longueur); j++){
		(file.t)[j] = malloc(sizeof(Tache));
		fscanf(fic, "%s ", (*((file.t)[j])).intitule );
		fscanf(fic, "%d ", &((*((file.t)[j])).priorite) );
	} 

	construireFileMax(file);
	Afficher_file_de_priorite(file);
	printf("\n");
	extraire_max_file(file);
	Afficher_file_de_priorite(file);
	printf("\n");
	(*cle).priorite = 30;
	strcpy( (*cle).intitule, "faire_une_sieste" );
	inserer_cle_file(file, cle);
	Afficher_file_de_priorite(file);
	printf("\n");
	augmenter_cle_file(file , 8 , 28 );
	Afficher_file_de_priorite(file);
	printf("\n");
	fclose(fic); 
   

	exit(0);
}
