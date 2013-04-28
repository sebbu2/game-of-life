#include "exo33.h"

/*von neumann*/
int nb_voisins_VN(int **tab, int i, int j, int n, int m) {
	int a=0;
	int b=0;
	int nb=0;
	int lmin=MAX(0, i-1);
	int lmax=MIN(n, i+2);
	int cmin=MAX(0, j-1);
	int cmax=MIN(m, j+2);
	assert(lmax-lmin<=3);
	assert(cmax-cmin<=3);
	int count=0;
	for(a=lmin;a<lmax;++a) {
		for(b=cmin;b<cmax;++b) {
			if(a==i&&b==j) continue;
			if(a!=i&&b!=j) continue;
			if(tab[a][b]==1) {
				++nb;
			}
			++count;
		}
	}
	assert(count<=4);
	return nb;
}

void generation_suivante_VN(int **tab1, int **tab2, int n, int m, int B[9], int S[9]) {
	_initialisation2(tab2, n, m);
	int i=0;
	int j=0;
	int nb=-1;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			nb=nb_voisins_VN(tab1, i, j, n, m);
			if(tab1[i][j]==0) {//cellule morte devenir vivante
				if(B[nb]==1) {
					tab2[i][j]=1;
				}
				else {
					tab2[i][j]=0;
				}
			}
			else if(tab1[i][j]==1) {//cellule vivante rester vivante
				if(S[nb]==1) {
					tab2[i][j]=1;
				}
				else {
					tab2[i][j]=0;
				}
			}
		}
	}
}

void jeu_VN(int **tab1, int n, int m, int B[9], int S[9], int ng) {
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
		generation_suivante_VN(tab1, tab_t, n, m, B, S);
		tmp=tab1;tab1=tab_t;tab_t=tmp;
		affiche(tab1, n, m);
	}
}

void jeu_fredkin_VN(int **tab1, int n, int m, int ng) {/*B13/S13*/
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
	S[1]=1;
	S[3]=1;
	jeu_VN(tab1, n, m, B, S, ng);
}
/**/
