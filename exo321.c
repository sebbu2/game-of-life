#include "exo321.h"

void dimensionnement(int *n, int *m) {
	printf("Veuillez saisir le nombre de lignes et de colonnes :\n");
	scanf("%d %d", n, m);
	CLEARBUF();
}

void initialisation(int **tab, int n, int m) {
	/*init*/
	int i=0;
	int j=0;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			tab[i][j]=0;
		}
	}
	/*saisie*/
	int a=0;
	int nb=0;
	while(nb<=0) {
		printf("Veuillez saisir le nombre de cellules vivantes à la première génération :\n");
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
			tab[i][j]=1;
			++a;
		}
	}
}

void _initialisation2(int **tab, int n, int m) {
	/*init*/
	int i=0;
	int j=0;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			tab[i][j]=0;
		}
	}
}

int nb_generation() {
	int nb=0;
	while(nb < 1) {
		nb=0;
		printf("Veuillez saisir le nombre de générations :\n");
		scanf("%d", &nb);
		CLEARBUF();
	}
	return nb;
}

void affiche(int **tab, int n, int m) {
	int i=0;
	int j=0;
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			if(tab[i][j]==1) {
				printf("o");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}

void affiche_fichier(int **tab, int n, int m, char *nom) {
	FILE* fp=fopen(nom, "w");
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			if(tab[i][j]==1) {
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

void saisie_B_M(int B[9]) {
	int nb=-1;
	for(int i=0;i<9;++i) {
		nb=-1;
		while(nb<0||nb >1) {
			nb=-1;
			printf("Une cellule vivante ayant %d voisins sera-t-elle morte ou vivante à la génération suivante ? (0 morte 1 vivante)\n", i);
			scanf("%d", &nb);
			CLEARBUF();
		}
		B[i]=nb;
	}
}

void saisie_S_M(int S[9]) {
	int nb=-1;
	for(int i=0;i<9;++i) {
		nb=-1;
		while(nb<0||nb >1) {
			nb=-1;
			printf("Une cellule morte ayant %d voisins sera-t-elle morte ou vivante à la génération suivante ? (0 morte 1 vivante)\n", i);
			scanf("%d", &nb);
			CLEARBUF();
		}
		S[i]=nb;
	}
}
/**/
