#include "exo42.h"

int main(void) {
	int n=0;
	int m=0;
	dimensionnement(&n, &m);
	int **tab=calloc(n, sizeof(int*));
	for(int i=0;i<n;++i) {
		tab[i]=calloc(m, sizeof(int));
	}
	initialisation(tab, n, m);
	_initialisation3(tab, n, m);
	int nbgen=nb_generation();
	printf("Vous avez demand� %d g�n�rations.\n", nbgen);
	jeu_seeds(tab, n, m, nbgen);
	return 0;
}
/**/