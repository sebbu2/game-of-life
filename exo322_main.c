#include "exo322.h"

int main(void) {
	int n=0;
	int m=0;
	dimensionnement(&n, &m);
	int **tab=calloc(n, sizeof(int*));
	for(int i=0;i<n;++i) {
		tab[i]=calloc(m, sizeof(int));
	}
	initialisation(tab, n, m);
	int nbgen=nb_generation();
	printf("Vous avez demand� %d g�n�rations.\n", nbgen);
	int B[9];
	for(int i=0;i<9;++i) {
		B[i]=0;
	}
	int S[9];
	for(int i=0;i<9;++i) {
		S[i]=0;
	}
	saisie_B_M(B);
	saisie_S_M(S);
	for(int i=0;i<9;++i) {
		printf("%d ", i);
	}
	printf("\n");
	printf("B :\n");
	for(int i=0;i<9;++i) {
		printf("%d ", B[i]);
	}
	printf("\n");
	printf("S :\n");
	for(int i=0;i<9;++i) {
		printf("%d ", S[i]);
	}
	printf("\n");
	printf("g�n�ration n�1 :\n");
	affiche(tab, n, m);
	/**/
	int **tab_t=calloc(n, sizeof(int*));
	for(int i=0;i<n;++i) {
		tab_t[i]=calloc(m, sizeof(int));
	}
	_initialisation2(tab_t, n, m);
	/**/
	int **tmp;
	for(int i=2;i<=nbgen;++i) {
		printf("g�n�ration n�%d :\n", i);
		generation_suivante_M(tab, tab_t, n, m, B, S);
		tmp=tab;tab=tab_t;tab_t=tmp;
		affiche(tab, n, m);
	}
	return EXIT_SUCCESS;
}
/**/
