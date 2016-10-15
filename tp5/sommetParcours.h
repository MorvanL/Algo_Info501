#ifndef __sommetParcours__
#define __sommetParcours__

typedef struct sommetParcours_type{
	char* couleur; //blanc pour non visité, gris pour visité, noir pour traité
	int date;
	int fin;
	int indice;
	struct sommetParcours_type* pere;
}sommetParcours;

sommetParcours creerSommetParcours (int);
void detruireSommetParcours (sommetParcours*);

#endif
