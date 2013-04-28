#include "exo41.h"

void affiche3(int **tab, int n, int m) {
	int i=0;
	int j=0;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			if(tab[i][j]==2) {
				printf("x");
			}
			else if(tab[i][j]==1) {
				printf("o");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}

void affiche3_fichier(int **tab, int n, int m, char *nom) {
	FILE* fp=fopen(nom, "w");
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			if(tab[i][j]==2) {
				fprintf(fp, "x");
			}
			else if(tab[i][j]==1) {
				fprintf(fp, "o");
			}
			else {
				fprintf(fp, ".");
			}
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void _initialisation3(int **tab, int n, int m) {
	int a=0;
	int nb=0;
	int i=0;
	int j=0;
	while(nb<=0) {
		printf("Veuillez saisir le nombre de cellules fantomes à la première génération :\n");
		scanf("%d", &nb);
		CLEARBUF();
	}
	while(a<nb) {
		i=-1;
		j=-1;
		printf("Coordonnées de la %de cellule :\n", a+1);
		scanf("%d %d", &i, &j);
		CLEARBUF();
		--i;
		--j;
		if(i<0 || i>=n || j<0 || j>=m) {
			printf("Mauvaises coordonnées, veuillez recommencer.\n");
		}
		else {
			tab[i][j]=2;
			++a;
		}
	}
}

void generation_suivante_M3(int **tab1, int **tab2, int n, int m, int B[9], int S[9]) {
	_initialisation2(tab2, n, m);
	int i=0;
	int j=0;
	int nb=-1;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			nb=nb_voisins_M(tab1, i, j, n, m);
			if(tab1[i][j]==0) {//cellule morte devient vivante (ou reste morte)
				if(B[nb]==1) {
					tab2[i][j]=1;
				}
				else {
					tab2[i][j]=0;
				}
			}
			else if(tab1[i][j]==1) {//cellule vivante reste vivante (ou devient fantome)
				if(S[nb]==1) {
					tab2[i][j]=1;
				}
				else {
					tab2[i][j]=2;
				}
			}
			else if(tab1[i][j]==2) {//cellule fantome devient morte
				tab2[i][j]=0;
			}
		}
	}
}

void jeu_M3(int **tab1, int n, int m, int B[9], int S[9], int ng) {
	printf("génération n°1 :\n");
	affiche3(tab1, n, m);
	int **tab_t=calloc(n, sizeof(int*));
	for(int i=0;i<n;++i) {
		tab_t[i]=calloc(m, sizeof(int));
	}
	_initialisation2(tab_t, n, m);
	int **tmp;
	for(int i=2;i<=ng;++i) {
		printf("génération n°%d :\n", i);
		generation_suivante_M3(tab1, tab_t, n, m, B, S);
		tmp=tab1;tab1=tab_t;tab_t=tmp;
		affiche3(tab1, n, m);
	}
}

void jeu_silverman(int **tab1, int n, int m, int ng) {/*B3/S*/
	int B[9];
	for(int i=0;i<9;++i) {
		B[i]=0;
	}
	int S[9];
	for(int i=0;i<9;++i) {
		S[i]=0;
	}
	B[3]=1;
	jeu_M3(tab1, n, m, B, S, ng);
}
/**/
