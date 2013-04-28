#include "exo323.h"

void jeu_M(int **tab1, int n, int m, int B[9], int S[9], int ng) {
	printf("génération n°1 :\n");
	affiche(tab1, n, m);
	int **tab_t=calloc(n, sizeof(int*));
	for(int i=0;i<n;++i) {
		tab_t[i]=calloc(m, sizeof(int));
	}
	_initialisation2(tab_t, n, m);
	int **tmp;
	for(int i=2;i<=ng;++i) {
		printf("génération n°%d :\n", i);
		generation_suivante_M(tab1, tab_t, n, m, B, S);
		tmp=tab1;tab1=tab_t;tab_t=tmp;
		affiche(tab1, n, m);
	}
}
/**/
