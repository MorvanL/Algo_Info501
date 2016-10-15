#ifndef __ensemble__
#define __ensemble__

#include "composante.h"

struct ensemble{
	 composante* tete;
	 composante* queue;
};

ensemble* creerEnsemble ();

composante* trouverEnsemble (composante*);  

void Union(composante*, composante*);

#endif
