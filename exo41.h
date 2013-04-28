#ifndef EXO41_H
#define EXO41_H

#include "common.h"
#include "exo321.h"
#include "exo322.h"
#include "exo323.h"
#include "exo33.h"

/*3 etats*/
void affiche3(int **tab, int n, int m);
void affiche3_fichier(int **tab, int n, int m, char *nom);
void _initialisation3(int **tab, int n, int m);
void generation_suivante_M3(int **tab1, int **tab2, int n, int m, int B[9], int S[9]);
void jeu_M3(int **tab1, int n, int m, int B[9], int S[9], int ng);
void jeu_silverman(int **tab1, int n, int m, int ng);/*B3/S*/

#endif
/**/
