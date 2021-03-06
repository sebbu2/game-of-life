#include "exo323.h"

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
	printf("Vous avez demandé %d générations.\n", nbgen);
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
	jeu_M(tab, n, m, B, S, nbgen);
	return 0;
}
/**/
