#include <stdlib.h>
#include <stdio.h>
#include "listChainee.h"
 
// t = "Bonjour je m'appelle racim."     d='B'  f=6                          1er cellule -> info = "Bonjour", *suivant = Null 
 //  ecrire une fonction qui retourne une sous-chaine de S dans T en connaissant l'indice d et f .


listeMots creerNoeud() {
    listeMots noeud = (listeMots)malloc(sizeof(element));
    strcpy(noeud->s," ");
    noeud->suivant=NULL;
    return noeud;
}

/*
void ajoutNoeud(listeMots *tete,listeMots *queue){
    listeMots new = creerNoeud();
    if (*tete == NULL) {   
         *tete=new;
         *queue=*tete;
    } else { 
            (*queue)->suivant=new;
            *queue=new;
    }
}
*/


void ajoutNoeud(listeMots tete, listeMots *prd){
     if (tete->suivant == NULL) {
         *prd=tete;
     }
    listeMots nouv=creerNoeud();
         (*prd)->suivant =nouv;
         *prd = nouv;
}




void Decoupe(char* T, char* S,int d,int f) {
    int k=0,j=d;

    char temp[100];
    for(j;j<=f;j++) { /// Bon   d=3 f=6
        temp[k]=S[j];  // temp[0]= S[3];
        k++;
    }
    temp[k]='\0';
    strcpy(T,temp);
}
// strtok

///    Bonjour

listeMots motsDe(char* t) {
    int i=0,d=0,f=0,taille=strlen(t);
    listeMots tete=NULL,queue=NULL,temp;
    char p[MAX];
    
    while (!isspace(t[i]))
    {
        if (isalpha(t[i])){
                d=i; // d=0
                f=d; // f=0
                i++;
                while (isalpha(t[i])){
                    f++;  //f=6
                    i++;   // i=4
                }       
                  tete=creerNoeud();
                 // strcpy(tete->s,"Bonjour");
                 Decoupe(tete->s, t, d, f);
                 queue=tete; 
        } else {
            i++;
            
        }
    }
 
  while (i<taille)
    {
        if (tolower(t[i]) >= 'a' && tolower(t[i] <= 'z')){
                d=i; // d=0
                f=d; // f=0
                i++;
                while(tolower(t[i]) >= 'a' && tolower(t[i] <= 'z')) {
                    f++;
                    i++;
                }
                Decoupe(p,t,d,f);
                while (tete != NULL && !strcmp(p,tete->s)) {
                    if (!strcmp(p,tete->s)) {
                        
                    }
                }
                
                
        } else {
            i++;

        }
        
    }
   

    return tete;
}



/*
listeMots motsDe(char *t) {
    listeMots tete=NULL,queue=NULL,temp;
    int len=strlen(t),f=0,d=0,i=0;
       

    while (!isspace(t[i])) {
        if (tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z') {
                d=i;
                f=d; 
                while(tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z') {
                    f++;
                    i++;
                }
                ajoutNoeud(&tete,&queue);
                Decoupe(tete->s, t, d, f);
                                        
        }else {
            i++;
            
        }
    }
        temp =tete;
     while (i<len) {
        if (tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z') {
                d=i;
                f=d; 
                while(tolower(t[i]) >= 'a' && tolower(t[i]) <= 'z') {
                    f++;
                    i++;
                }
                 ajoutNoeud(&temp,&queue);
                 Decoupe(queue->s, t, d, f);
                                        
        }else {
            i++; 
        }
    }             
    return tete;
}
*/