#include "Headers/listChainee.h"
#include "Headers/freq.h"
#include "Headers/mesFonctionsFichier.h"

int main(){
        FILE *fich;
        fich = fopen("C:/Users/Racim/Desktop/testProjet.txt","r");

       char t[MAX] ="salut Bonjour salut Aurevoir  salut Bonjour salut demain salut racim salut racim";
       char m[MAX]= "salut";
       listeMots tete=NULL,queue;
       listeFreq teteF=NULL;
       listeFreq teteC=NULL;
      //  tete = motsDe(lire(fich));

         tete = motsDe(t);

      //  SuppDbl(tete);
         printf("la fonciton motsDe : \n");
      while (tete != NULL){
            printf("%s\n", tete->s);
            tete= tete->suivant;
        }  

       printf("la fonction frequencesDe : \n");

      //  teteF=frequencesDe(lire(fich));
         teteF=frequencesDe(t);

       while(teteF != NULL) {
           printf("%s\n", teteF->s);
        printf("%d\n", teteF->freq);
        teteF = teteF ->suivant;
       }  


        listeMots context;       

        printf("Contexte Ctxt : \n");
        context=Contexte(t,m);
        while (context != NULL)
        {
            printf("%s\n", context->s);
            context=context->suivant;
        }
        
          printf("la fonction Contexte : \n");

        teteC = contexte(t,m);

        while(teteC != NULL){
            printf("%s\n", teteC->s);
        printf("%d\n", teteC->freq);
        teteC = teteC ->suivant;
        }

    return 0;
}