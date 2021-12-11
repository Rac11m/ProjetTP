#include "listChainee.h"


int main(){
        char t[MAX] ="Bonjour Aurevoir Bonsoir Bonjour Mot Mots Maux";
       listeMots tete=NULL,queue;
        int i=0;


        tete = motsDe(t);
        while (tete != NULL)
        {
            printf("%s\n", tete->s);
            tete= tete->suivant;
        }
        
        

   


  

    return 0;
}