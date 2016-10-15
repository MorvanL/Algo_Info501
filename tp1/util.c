#include <time.h>
#include <stdlib.h>
#include "util.h"

int parent(int i){
	return ((i-1)/2);
}

int gauche (int i){
	return (2*i+1);
}


int droite (int i){
	return (2*i+2);
}

void echanger(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int* creerTabAleatoire ( int nbValeur){
	int i;
	int* t;
	t = malloc( nbValeur*(sizeof(int)) );
	srand(time(NULL));
	for(i=0; i<nbValeur; i++){
		t[i] = (rand ()%nbValeur)+1;
	}
	return t;
}
