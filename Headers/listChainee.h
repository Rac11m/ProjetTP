#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "mesFonctionsFichier.h"
#define MAX 255

typedef struct element* listeMots;
typedef struct element
{
    // data
    char s[MAX];
    // pointer to next
    listeMots suivant; 
} element;


void SuppDbl(listeMots );
char* toLower(char* );
void Decoupe(char* , char* ,int ,int );
listeMots creerNoeud();
listeMots motsDe(char* ); 
void ajoutNoeud(listeMots , listeMots *);
bool isPoint(char );
void triListeMots(listeMots );
// bool isDoublon(char* ,listeMots );


#endif // LIST_H_INCLUDED