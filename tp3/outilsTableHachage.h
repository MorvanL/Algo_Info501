#include "tableHachage.h"

void afficherTableHachage (tableHachage*);
unsigned long long convertirChEntier (char*);
int hachage (unsigned long long, int);
void insererHachage (tableHachage*, cellule*);
cellule* rechercherHachage (tableHachage*, char*);
void supprimerHachage (tableHachage*, cellule*);
int compterTableHachage (tableHachage*);
