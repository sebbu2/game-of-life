#ifndef EXO33_H
#define EXO33_H

#include "common.h"
#include "exo321.h"
#include "exo322.h"
#include "exo323.h"

/*von neumann*/
int nb_voisins_VN(int **tab, int i, int j, int n, int m);
void generation_suivante_VN(int **tab1, int **tab2, int n, int m, int B[9], int S[9]);
void jeu_VN(int **tab1, int n, int m, int B[9], int S[9], int ng);
void jeu_fredkin_VN(int **tab1, int n, int m, int ng);/*B13/S13*/

#endif
/**/
