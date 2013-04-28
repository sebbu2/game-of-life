#ifndef EXO322_H
#define EXO322_H

#include "common.h"
#include "exo321.h"

int nb_voisins_M(int **tab, int i, int j, int n, int m);
void duplication(int **tab1, int **tab2, int n, int m);
void generation_suivante_M(int **tab1, int **tab2, int n, int m, int B[9], int S[9]);

#endif
/**/
