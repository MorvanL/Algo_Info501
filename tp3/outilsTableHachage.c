#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "outilsTableHachage.h"

void afficherTableHachage (tableHachage* table){
	int i;
	for(i=0; i < (table->taille); i++){
		printf("%d : ", i);
		afficherListe( &(table->t)[i] );
	} 
}

unsigned long long convertirChEntier (char* ch){
	int i, j=0;
	unsigned long long k = 0;
	for(i = strlen(ch)-1; i>=0; i--){
		k += (long long)ch[i]*( (int)pow(128,j) );
		j++;
	}
	return k;
}

int hachage(unsigned long long k, int taille){
	return k%taille;
}

void insererHachage (tableHachage* table, cellule* c){
	unsigned long long k = convertirChEntier(c->mot);
	int indice = hachage(k, table->taille);
	inserer( &((table->t)[indice]), c);
}

cellule* rechercherHachage (tableHachage* table, char* ch){
	unsigned long long k = convertirChEntier(ch);
	int indice = hachage(k, table->taille);
	return rechercher( &((table->t)[indice]), ch );
}

void supprimerHachage (tableHachage* table, cellule* c){
	unsigned long long k = convertirChEntier(c->mot);
	int indice = hachage(k, table->taille);
	supprimer( &((table->t)[indice]), c );
}

int compterTableHachage (tableHachage* table){
	int i, cpt = 0;
	for(i=0; i < (table->taille); i++){
		cpt += compterListe( &((table->t)[i]) );
	}
	return cpt;
}
