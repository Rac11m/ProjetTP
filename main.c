#include "listChainee.h"


int main(){
    listeMots tete=NULL,queue;
    
    char T[20]="Bonjour";
    char N[20] ="Au Revoir";
    
    tete=ajoutTete(tete,T);
   // queue=tete;

    
    ajoutNoeud(tete,&queue,N);

   while (tete!=NULL)
    {
         printf("%s\n", tete->s);
         tete=tete->suivant;
    }
    



 


    
    
    return 0;
}