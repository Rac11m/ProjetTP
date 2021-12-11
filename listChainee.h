#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string.h>
#include <ctype.h>
#define MAX 255

typedef struct element* listeMots;
typedef struct element
{
    // data
    char s[MAX];
    // pointer to next
    listeMots suivant; 
} element;


void Decoupe(char* , char* ,int ,int );
listeMots creerNoeud();
// void ajoutNoeud(listeMots *, listeMots *);
listeMots motsDe(char* ); 
listeMots ajoutTete(listeMots );
void ajoutNoeud(listeMots , listeMots *);

#endif // LIST_H_INCLUDED