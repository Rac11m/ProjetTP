#include <stdlib.h>
#include <stdio.h>
#include "listChainee.h"
 
// t = "Bonjour je m'appelle racim."     d='B'  f=6                          1er cellule -> info = "Bonjour", *suivant = Null 


        //  ecrire une fonction qui retourne une sous-chaine de S dans T en connaissant l'indice d et f .
listeMots creerNoeud(char *S) {
    listeMots noeud = (listeMots)malloc(sizeof(element));
    strcpy(noeud->s,S);

    noeud->suivant=NULL;
    return noeud;
}


listeMots ajoutTete(listeMots tete,char* S) {
    listeMots t = creerNoeud(S);
    tete = t;
}

/*
void ajoutNoeud(listeMots *queue, char* S){
    listeMots new = creerNoeud(S);
    if (tete == NULL) {   
        tete=new;
        (*queue=tete;
    } else { 
            queue->suivant=new;
            queue=new;
    }
}
*/

void ajoutNoeud(listeMots tete, listeMots *prd, char *S)
 {
     if (tete->suivant == NULL) {
         *prd=tete;
     }
    listeMots nouv=creerNoeud(S);
         (*prd)->suivant =nouv;
         *prd = nouv;
}


void Decoupe(char* T, char* S,int d,int f) {
    int i=0;
    for(d;d<=f;d++) {
        T[i]=S[d];
        i++;
    }
    T[f]='\0';
}

listeMots motsDe(char* t) {
    int i=0,d=0,f=0,taille=strlen(t);
    listeMots Liste=NULL,Q;
  /*  while (i<taille)
    {
        ajoutNoeud(Liste,Q);
        if (tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z'){
                d=i; // d=0
                f=d; // f=0
                while (tolower(t[f]) >= 'a' && tolower(t[f]) <= 'z' ){
                    f++;  //f=6
                }
                Decoupe(Liste->s, t, d, f);  
        } else {
            i++;
            
        }
        
    }
     */


    return Liste;
}
