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


