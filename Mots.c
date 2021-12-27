#include <stdlib.h>
#include <stdio.h>
#include "Headers/listChainee.h"
#include "Headers/mesFonctionsFichier.h"

bool isPoint(char c) {
    if (c== '.') {
        return true;
    }
    return false;
}

listeMots creerNoeud() {
    listeMots noeud = (listeMots)malloc(sizeof(element));
    strcpy(noeud->s," ");
    noeud->suivant=NULL;
    return noeud;
}

void ajoutNoeud(listeMots tete, listeMots *prd){
     if (tete->suivant == NULL) {
         *prd=tete;
     }
    listeMots nouv=creerNoeud();
         (*prd)->suivant =nouv;
         *prd = nouv;
}

char* toLower(char *chaine) {
    int i=0;
    int taille = strlen(chaine);
    char *s = malloc(taille+1);
    
    for (i=0;i<taille;i++) {
      s[i] = tolower(chaine[i]);
    }  
               
    s[taille]='\0';
    return s;
}

void Decoupe(char* T, char* S,int d,int f) {
    int k=0;

    char temp[100];
    for(d;d<=f;d++) { 
        temp[k]=S[d]; 
        k++;
    }
    temp[k]='\0';
    strcpy(T,toLower(temp));
}


void SuppDbl (listeMots tete) {
        listeMots pc,pr,ps;

        pc = tete;
        while (pc != NULL)
        {
            pr=pc;
            ps=pc->suivant;
            while (ps != NULL) {
                if (strcmp(ps->s,pc->s) == 0) {
                    pr->suivant = ps->suivant;
                    free(ps);
                    ps = pr->suivant; 
                } else {
                    pr = ps;
                    ps = ps ->suivant;
                }
            }
            pc = pc->suivant;
        }
          
}

void triListeMots(listeMots tete) {
    listeMots pc,pr,ps;
    char x[MAX];
    pc=tete;
    while (pc != NULL){
        pr=pc;
        ps=pc->suivant;
        while(ps != NULL){
            if(strcmp(ps->s,pc->s) == 0){
                ps=ps->suivant;
            }else if(strcmp(pc->s,ps->s) > 0) {
                    strcpy(x,ps->s);
                    strcpy(ps->s,pc->s);
                    strcpy(pc->s,x);
                    ps=ps->suivant;
            } else {
                    ps=ps->suivant;
            }
        }
        pc=pc->suivant;
    }
    
}


listeMots motsDe(char* t) {     // Probleme des la fonction pour l'instant : elle contient les doublons.
    int i=0,d=0,f=0,taille=strlen(t);
    listeMots tete=NULL,queue=NULL;
    char p[MAX];
    bool doublon=false;
  while (i<taille){
       if(isalpha(t[i]) || isPoint(t[i])){
                d=i; // d=0
                f=d; // f=0
                i++;  
               while (isalpha(t[i])){
                    f++;
                    i++;
                }
                    Decoupe(p,t,d,f);
                        if (tete == NULL) {
                                tete=creerNoeud();
                                strcpy(tete->s,p);
                                queue=tete; 
                        } else{
                                    ajoutNoeud(tete,&queue);
                                    strcpy(queue->s,p); 
  
                            }
        }  else {
                i++; }  
         
  }
 // triListeMots(tete);  
    return tete;
}


/*
bool isDoublon(char *t,listeMots liste) {
        bool x=false;
        while (liste != NULL && x == false) {
             if (strcmp(toLower(t),toLower(liste->s))){
               x=true;
             } else {
                    liste=liste->suivant;
             }
        }   
        return x;
}

*/



