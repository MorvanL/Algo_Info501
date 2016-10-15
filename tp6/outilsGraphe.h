#include "graphe.h"
#include "arete.h"
#include "ensemble.h"
#include "sommetPrim.h"
#include "file.h"

arete** genererAcpmKruskal (graphe*);
void afficherAcpmKruskal (arete**, int);
void detruireAcpmKruskal (arete***, int);

File_de_priorite genererAcpmPrim (graphe*);
void afficherAcpmPrim (File_de_priorite, int);
void detruireAcpmPrim (File_de_priorite, int);


