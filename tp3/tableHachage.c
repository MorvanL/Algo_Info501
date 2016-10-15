#include <stdio.h>
#include <stdlib.h>
#include "tableHachage.h"

tableHachage* creerTableHachage (int tailleTable){
	int i;
	tableHachage* table = (tableHachage*)malloc(sizeof(tableHachage));
	table->taille = tailleTable;
	table->t = (liste*)malloc(tailleTable*sizeof(liste));
	for(i=0; i<tailleTable; i++){
		(table->t)[i] = creerListe();
	}
	return table;
}

void detruireTableHachage (tableHachage* table){
	int i;
	for(i=0; i < (table->taille); i++){
		detruireListe( &((table->t)[i]) );
	}
	free(table->t);
}
