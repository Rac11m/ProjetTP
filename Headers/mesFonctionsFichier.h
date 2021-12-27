#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 512

char* allouerChaine(int );
char* lire(FILE* );
long taille(FILE* );
int nbLignes(FILE* );


#endif // FICHIER_H_INCLUDED
