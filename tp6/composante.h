#ifndef __composante__
#define __composante__

typedef struct ensemble ensemble;

typedef struct composante_type{
	int indice;
	struct ensemble *ens;
	struct composante_type* succ;
}composante;

composante creerComposante (int);



#endif
