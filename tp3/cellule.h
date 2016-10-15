#ifndef __cellule__
#define __cellule__

typedef struct cellule_type{
	char* mot;
	struct cellule_type* pred;
	struct cellule_type* succ;
}cellule;

cellule* creerCellule (char*);
void detruireCellule (cellule*);

#endif
