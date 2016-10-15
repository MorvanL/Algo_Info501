#ifndef __tas_t__
#define __tas_t__
#ifndef __Tache__
#define __Tache__
#ifndef __File_de_priorite__
#define __File_de_priorite__

typedef struct{
	int longueur;
	int taille;
	int* t;
}tas_t;

typedef struct{
	char intitule [50];
	int priorite;
}Tache;

typedef struct{
	int longueur;
	int taille;
	Tache** t;
}File_de_priorite;

#endif
#endif
#endif
