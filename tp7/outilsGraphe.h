#include "graphe.h"
#include "file.h"

sommetPcc** source_unique_initialisation(graphe*, int);
void afficherPcc (sommetPcc**, int, int); //Affiche le pcc entre deux sommets
void detruirePcc(sommetPcc***, int);

void relacherDijkstra (sommetPcc*, sommetPcc*, int, File_de_priorite*);
sommetPcc** Dijkstra (graphe*, int);
void pcc_tous_a_tous (graphe*); //Affiche le pcc de tous sommets à tous sommets

void relacherBF (sommetPcc*, sommetPcc*, int);
int Bellman_Ford (graphe*, int, sommetPcc***); //retourne 1 s'il existe un circuit negatif, 0 sinon



