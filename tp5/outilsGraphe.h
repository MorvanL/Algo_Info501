#include "graphe.h"
#include "file.h"

sommetParcours* parcoursLargeur (graphe*, int);
void afficherChemin (sommetParcours*, int, int);

sommetParcours* parcoursProfondeur (graphe*);
void visiter_pp (graphe*, sommetParcours*, sommetParcours*, int*);
void afficherParcoursProfondeur (int, sommetParcours*);
