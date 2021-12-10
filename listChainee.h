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
listeMots creerNoeud(char *);
listeMots ajoutTete(listeMots , char* );
// void ajoutNoeud(listeMots ,char* );
void ajoutNoeud(listeMots, listeMots* , char* );
listeMots motsDe(char* ); 


#endif // LIST_H_INCLUDED