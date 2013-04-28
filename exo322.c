#include "exo322.h"

int nb_voisins_M(int **tab, int i, int j, int n, int m) {
	int a=0;
	int b=0;
	int nb=0;
	int lmin=MAX(0, i-1);
	int lmax=MIN(n, i+2);
	int cmin=MAX(0, j-1);
	int cmax=MIN(m, j+2);
	assert(lmax-lmin<=3);
	assert(cmax-cmin<=3);
	int countl=0;
	int countc=0;
	int count=0;
	for(a=lmin;a<lmax;++a) {
		countc=0;
		for(b=cmin;b<cmax;++b) {
			if(a==i&&b==j) continue;
			if(tab[a][b]==1) {
				++nb;
			}
			++countc;
			++count;
		}
		assert(countc<=3);
		++countl;
	}
	assert(countl<=3);
	assert(count<=8);
	return nb;
}

void duplication(int **tab1, int **tab2, int n, int m) {
	int i=0;
	int j=0;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			tab2[i][j]=tab1[i][j];
		}
	}
}

void generation_suivante_M(int **tab1, int **tab2, int n, int m, int B[9], int S[9]) {
	_initialisation2(tab2, n, m);
	int i=0;
	int j=0;
	int nb=-1;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			nb=nb_voisins_M(tab1, i, j, n, m);
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
/**/
