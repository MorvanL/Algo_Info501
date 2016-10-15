#ifndef __noeud__
#define __noeud__

typedef struct noeud_type{
	char* mot;
	struct noeud_type* pere;
	struct noeud_type* filsG;
	struct noeud_type* filsD;
}noeud;

noeud* creerNoeud (char*);
void detruireNoeud (noeud*);

#endif
