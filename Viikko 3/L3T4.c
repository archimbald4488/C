#include <stdio.h>

#define LEN 60

int pituus(char *pJono1, char *pJono2);

char *yhdista(char sJono1[], char sJono2[]);

int main(void) {

    char sJono1[LEN], sJono2[LEN];
    int iPituus;

    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(sJono1, LEN, stdin);
    
    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(sJono2, LEN, stdin);

    iPituus = pituus(sJono1, sJono2);

    if (iPituus > 60) {
        printf("Merkkijonojen yhteenlaskettu pituus on liian");
        printf(" pitkä ohjelman muistialueelle.\n");
    } else {
        yhdista(sJono1, sJono2);
        printf("Yhdistetty merkkijono on:\n");
        printf("'%s'\n", sJono1);
    }

    printf("Kiitos ohjelman käytöstä.");

    return(0);
}

int pituus(char *pJono1, char *pJono2) {
    int i = 0, j = 0, iPituus1 = 0, iPituus2 = 0, iPituus;

    while (pJono1[i] != '\n') {
        i++;
        iPituus1++;
    }
    //printf("Ekan pituus oli %d\n", iPituus1);
    while (pJono2[j] != '\n') {
        j++;
        iPituus2++;
    }
    //printf("Tokan pituus oli %d\n", iPituus2);
    iPituus = iPituus1 + iPituus2;
    return(iPituus);
}

char *yhdista(char sJono1[], char sJono2[]) {

    int i = 0, j = 0;

    while (sJono1[i] != '\n') {
        i++;
    }
    //printf("i on %d\n", i);

    while (sJono2[j] != '\n') {
        sJono1[i] = sJono2[j];
        j++;
        i++;
        //printf("sJono1 on nyt %s\n", sJono1);
    }
    sJono1[i] = '\0';

    return(sJono1);
}