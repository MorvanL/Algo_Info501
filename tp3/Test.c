#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "outilsTableHachage.h"

int main (int argc, char *argv[]){

  /*  	liste l = creerListe();				/////////Test liste////////
	cellule* c1 = creerCellule("blabla");
	inserer(&l, c1);
	cellule* c2 = creerCellule("blublu");
	inserer(&l, c2);
	cellule* c3 = creerCellule("bloblo");
	inserer(&l, c3);
	afficherListe(&l);

	cellule* c4 = rechercher( &l, "blublu" );
	printf("%s \n",c4->mot);

	supprimer(&l, c3);
	afficherListe(&l);

	detruireListe(&l);
	afficherListe(&l);
    */
   

   /*	liste l = creerListe();				/////////compter nombre de mot dans fichier avec liste/////////
	char* ch = (char*)malloc(sizeof(char)*26);
	int cpt = 0;
	int cpt2;
	FILE* fic = fopen(argv[1], "r"); 
	float temps;				
    	clock_t t1, t2;
	t1 = clock();    				 //voir ou placer tout ça
	while(fscanf(fic, "%s ", ch) != EOF){
		if( rechercher(&l, ch) == NULL ){
			inserer(&l, creerCellule(ch));	
		}
		cpt++;
	}
	//afficherListe(&l);
	cpt2 = compterListe(&l);
	t2 = clock();				
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps pour compter le nombre de mot dans la liste : %f \n", temps);
	printf("nombre de mots dans la liste : %d\n", cpt2);
	printf("nombre de mots dans le ficher : %d\n", cpt);

	fclose(fic); 
   */
	
   	int i, cpt = 0, cpt2;				////////////////test table de hachage////////////////
	
	tableHachage* table = creerTableHachage(11);

	for(i=0; i<5; i++){
		insererHachage(table, creerCellule("test")); 
	}
	afficherTableHachage(table);
	cellule* c = rechercherHachage (table, "test");
	printf("%s\n", c->mot);

	printf("%lld\n", convertirChEntier("Abc"));

	cellule* c2 = creerCellule("tester");
	insererHachage(table, c2);
	afficherTableHachage(table);
	supprimerHachage (table, c2);
  	afficherTableHachage(table);
	detruireTableHachage(table);

    
  /*  	printf("ok");
  	int i, cpt = 0, cpt2;				//////////compter nombre de mot dans fichier avec table de hachage////////////
	char* ch = (char*)malloc(sizeof(char)*50);
	tableHachage* table = creerTableHachage(11); 
	FILE* fic = fopen(argv[1], "r"); 		
	float temps;				
    	clock_t t1, t2;
	t1 = clock();   				
	while(fscanf(fic, "%s ", ch) != EOF){
		if( strlen(ch) < 27 ){
			if( rechercherHachage (table, ch) == NULL ){	
				insererHachage(table, creerCellule(ch));
			}
			cpt++;
		}
	}
	cpt2 = compterTableHachage(table);
	t2 = clock();				
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps pour compter le nombre de mot dans la table : %f \n", temps);
	printf("nombre de mots dans la liste : %d\n", cpt2);
	printf("nombre de mots dans le ficher : %d\n", cpt);
	
	detruireTableHachage(table);
	//fclose(fic);
    
	exit(0);
   */
	
}
