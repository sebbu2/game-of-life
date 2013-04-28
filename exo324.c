#include "exo324.h"

void jeu_conway(int **tab1, int n, int m, int ng) {/*B3/S23*/
	int B[9];
	for(int i=0;i<9;++i) {
		B[i]=0;
	}
	int S[9];
	for(int i=0;i<9;++i) {
		S[i]=0;
	}
	B[3]=1;
	S[2]=1;
	S[3]=1;
	jeu_M(tab1, n, m, B, S, ng);
}

void jeu_fredkin_M(int **tab1, int n, int m, int ng) {/*B1357/S1357*/
	int B[9];
	for(int i=0;i<9;++i) {
		B[i]=0;
	}
	int S[9];
	for(int i=0;i<9;++i) {
		S[i]=0;
	}
	B[1]=1;
	B[3]=1;
	B[5]=1;
	B[7]=1;
	S[1]=1;
	S[3]=1;
	S[5]=1;
	S[7]=1;
	jeu_M(tab1, n, m, B, S, ng);
}
/**/
