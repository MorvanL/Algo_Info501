#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "composante.h"

composante creerComposante (int ind){
	composante c;
	c.indice = ind;
	c.ens = NULL;
	c.succ = NULL;
	return c;
}

