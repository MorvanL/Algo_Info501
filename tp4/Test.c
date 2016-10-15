#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "outilsArbre.h"

int main (int argc, char *argv[]){
	
   /*	noeud* arbre = creerArbre();			///////////////Test arbre de recherche///////////
	int* cpt = (int*)malloc(sizeof(int));
	*cpt = 0;

	noeud* n = creerNoeud("salut");
	inserer(&arbre, &n);
	noeud* n2 = creerNoeud("test");
	inserer(&arbre, &n2);
	noeud* n3 = creerNoeud("salutation");
	inserer(&arbre, &n3);	
	
	printf("affichage recursif : \n");
	afficherArbreTrieRecursif(arbre);
	
	supprimer(arbre, n2);

	printf("affichage Iteratif : \n");
	afficherArbreIteratif(arbre);
	printf("\n");
	
	noeud* m = rechercher(arbre, "salut");
	printf("%s\n", m->mot);
	noeud* o = rechercher(arbre, "inconnu");
	if( o == NULL ){
		printf("le mot n'a pas été trouvé\n");
	}
	
	compterArbre(arbre, cpt);
	printf("nombre de mot dans l'arbre : %d\n", *cpt);

	detruireArbre(arbre);
    */

    	int* cpt = (int*)malloc(sizeof(int));
	*cpt = 0;
	int cpt2;				//////////compter nombre de mot dans fichier avec arbre de recherche////////////
	char* ch = (char*)malloc(sizeof(char)*50);
	noeud* arbre = creerArbre();
	noeud* n = creerArbre();
	FILE* fic = fopen(argv[1], "r"); 		
	float temps;				
    	clock_t t1, t2;
	t1 = clock();    				 //voir ou placer tout ça
	while(fscanf(fic, "%s ", ch) != EOF){
		if( strlen(ch) < 27 ){
			if( rechercher(arbre, ch) == NULL ){
				n = creerNoeud(ch);
				inserer(&arbre, &n);
			}
			cpt2++;
		}
	}
	compterArbre(arbre, cpt);
	t2 = clock();				
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps pour compter le nombre de mot dans l'arbre : %f \n", temps);
	printf("nombre de mots dans l'arbre : %d\n", *cpt);
	printf("nombre de mots dans le ficher : %d\n", cpt2);

	detruireArbre(arbre);

	exit(0);
    
}















