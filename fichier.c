#include "Headers/mesFonctionsFichier.h"


char* allouerChaine(int n) {
    char* p;
    p = (char*)malloc(n*sizeof(char));
    if(p == NULL) {
        printf("Erreur");
        exit(-1);
    }
    return p;
}

long taille(FILE* fich){
   fseek(fich,0,SEEK_END);
   return ftell(fich);
}


char* lire(FILE* fich){
    long x;
    long lg= taille(fich);
    char *s= allouerChaine(lg+1);
    rewind(fich);
    x=fread(s,1,lg,fich);
    s[x] ='\0';
    if (x < lg) {
       x= fread(s+x,1,lg,fich);
       s[lg] ='\0';
        }
    return s;
}

int nbLignes(FILE* fich) {
    int cpt=1;
    char c;
    rewind(fich);
    if (fich != NULL) {
        do{
            c=fgetc(fich);
            if (c == '\n') {cpt++;}
        } while(!feof(fich));
}
return cpt;
 }


