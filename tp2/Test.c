#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"


int main(int argc, char *argv[]){
     /*	int n = 8;			  //////Test pile//////
	Pile p = creerPile(n);
	remplirPile(&p, n);
	afficherPile(&p);
	printf("%d \n",capacitePile(&p));
	printf("Vide : %d \n",pileVide(&p));
	printf("Pleine : %d \n",pilePleine(&p));
	depiler(&p);
	afficherPile(&p);
	empiler(&p, 5);
	afficherPile(&p);
	Pile p2 = copierPile(p);
	afficherPile(&p2);
	afficherPile(&p);
	printf("%d\n", taillePile(&p));
	detruirePile(&p);
	detruirePile(&p2);
	afficherPile(&p);
   */

	int tourDepart;
	int tourArriver;
	int depOk;
	int cpt = 0;
	Hanoi h = creerHanoi(atoi(argv[1]));
	afficherHanoi(&h);
	while( gagne(&h, atoi(argv[1])) == 1){
		cpt++;
		printf("Tour numero %d :\n", cpt);
		depOk = 1;
		while( depOk == 1 ){
			printf("Veuillez entrer 1, 2 ou 3 selon la tour sur laquelle se trouve le disque a deplacer\n");
			scanf("%d", &tourDepart);
			printf("Veuillez entrer 1, 2 ou 3 selon la tour sur laquelle vous souhaitez deplacer le disque\n");
			scanf("%d", &tourArriver);
			if( (tourDepart != tourArriver)  &&  (tourDepart==1 || tourDepart==2 || tourDepart==3)  &&  (tourArriver==1 || tourArriver==2 || tourArriver==3) ){
				depOk = 0;
			}
		}
		deplacerDisque(tourDepart, tourArriver, &h);
		afficherHanoi(&h);
	}
	printf("vous avez gagne \n");

	exit(0);
}
