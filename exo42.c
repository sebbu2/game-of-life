#include "exo42.h"

void jeu_seeds(int **tab1, int n, int m, int ng) {/*B2/S*/
	int B[9];
	for(int i=0;i<9;++i) {
		B[i]=0;
	}
	int S[9];
	for(int i=0;i<9;++i) {
		S[i]=0;
	}
	B[2]=1;
	jeu_M3(tab1, n, m, B, S, ng);
}
/**/
