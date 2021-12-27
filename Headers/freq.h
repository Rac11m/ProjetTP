#ifndef FREQ_H_INCLUDED
#define FREQ_H_INCLUDED
#include <string.h>
#include <ctype.h>
#include "listChainee.h"
#include "mesFonctionsFichier.h"
#define MAX 255


typedef struct elem* listeFreq;
typedef struct elem{
  int freq;
  char s[MAX];  
  listeFreq suivant;
}elem;

listeFreq creerNoeud2();
listeFreq frequencesDe(char* );
listeFreq contexte(char* ,char* );
void ajoutELem(listeFreq ,listeFreq* );
void trierListeFReq(listeFreq );
int frequence(listeMots ,char* );


listeMots Contexte(char* ,char* );

#endif // FREQ_H_INCLUDED