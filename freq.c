#include <stdlib.h>
#include <stdio.h>
#include "Headers/freq.h"
#include "Headers/listChainee.h"
#include "Headers/mesFonctionsFichier.h"

listeFreq creerNoeud2(){
  listeFreq noeud=(listeFreq)malloc(sizeof(elem)); 
  strcpy(noeud->s," ");
  noeud->freq=0;
  noeud->suivant=NULL;
  return noeud;
}

void ajoutELem(listeFreq tete,listeFreq *prd){
  if(tete->suivant == NULL){
    *prd=tete;
  }
    listeFreq nouv=creerNoeud2();
    (*prd)->suivant=nouv;
    *prd = nouv;

}

int frequence(listeMots maliste,char* t){
  
  if(maliste == NULL) return 0;
  
  if((strcmp(maliste->s,t)!=0)) return frequence(maliste->suivant,t);
    else return frequence(maliste->suivant,t)+1;
}



listeFreq frequencesDe(char* t){
    listeMots lMots = motsDe(t);
    triListeMots(lMots);
    listeFreq lFreq=creerNoeud2(),queue=NULL;
    if(lMots != NULL){
            strcpy(lFreq->s,lMots->s);
            lFreq->freq=1;
            lFreq->suivant=NULL;
            queue=lFreq;
            lMots=lMots->suivant;
    }    

   while(lMots != NULL){
    if (strcmp(queue->s,lMots->s) == 0){
        queue->freq++;
        
    } else {
        ajoutELem(lFreq,&queue);
        strcpy(queue->s,lMots->s);
        queue->freq=1;
    }
        lMots=lMots->suivant;
    }  
   
   trierListeFReq(lFreq);

    return lFreq;
}



void trierListeFReq(listeFreq tete) {
    listeFreq pc,pr,ps;
    char x[MAX];
    int u;
    pc=tete;
    while (pc != NULL){
        pr=pc;
        ps=pc->suivant;
        while(ps != NULL){
            if(ps->freq >= pc->freq){
                ps=ps->suivant;
            }else{
                    strcpy(x,ps->s);
                    u=ps->freq;
                    strcpy(ps->s,pc->s);
                    ps->freq=pc->freq;
                    strcpy(pc->s,x);
                    pc->freq = u;
                    ps=ps->suivant;
            } 
        }
        pc=pc->suivant;
    }
}

listeFreq contexte(char*t, char* m){
      listeFreq lcontexte=NULL,queue=NULL;
      listeMots motCtxt=Contexte(t,m);
      
      if(motCtxt != NULL){
        lcontexte=creerNoeud2();
        strcpy(lcontexte->s,motCtxt->s);
        lcontexte->freq=frequence(motCtxt,motCtxt->s);
        queue=lcontexte;
        motCtxt=motCtxt->suivant;
      }
      
      while(motCtxt != NULL){
        if(strcmp(motCtxt->s,queue->s)!=0){
            ajoutELem(lcontexte,&queue);
            strcpy(queue->s,motCtxt->s);
            queue->freq=frequence(motCtxt,motCtxt->s);
        }
          motCtxt=motCtxt->suivant;
      }
      return lcontexte;
}

listeMots Contexte(char* t,char* m){
  listeMots motCtxt=NULL,lMots= motsDe(t),ps,queue=NULL;

  while(lMots->suivant != NULL){
    ps=lMots->suivant;
    if(strcmp(lMots->s,m)==0){
          if (motCtxt == NULL){
            motCtxt=creerNoeud();
            strcpy(motCtxt->s,ps->s);
            queue=motCtxt;
          } else {
            ajoutNoeud(motCtxt,&queue);
            strcpy(queue->s,ps->s);
          }
    }
    lMots=lMots->suivant;
  }
  triListeMots(motCtxt);
  return motCtxt;
}

/*
listeFreq trierListeFReq(listeFreq liste){
  listeFreq p=liste,q=p->suivant,perm;
  
  if(p==NULL) return liste;
  

  if(p->freq > q->freq) {
    p->suivant = q->suivant;
    q->suivant = p;
    return trierListeFReq(p);
  }
  else {
    q=q->suivant;
    trierListeFReq(p);
  }
}
*/