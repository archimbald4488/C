#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void asetaSiemen(void);

int kysyMaara(void);

char *arpoJaHyvaksy(int iMaara, char *pJono);

void tarkistaC(char *pJono);

int main(void) {
    int iLuku;
    char sJono[30];

    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");

    asetaSiemen();

    iLuku = kysyMaara();

    arpoJaHyvaksy(iLuku, sJono);

    tarkistaC(sJono);

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void asetaSiemen(void) {
    int iLuku;

    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &iLuku);

    srand(iLuku);
}

int kysyMaara(void) {
    int iLuku;

    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &iLuku);
    printf("\n");

    return(iLuku);
}

char *arpoJaHyvaksy(int iMaara, char *pJono) {
    int i, iArvo, j = 0;
    char cMerkki;

    for (i=0; i<iMaara; i++) {

        iArvo = (rand() % 95) + 32;
        cMerkki = iArvo;
        //printf("Merkki on '%c'.\n", cMerkki);
        //printf("'%s'\n", pJono);

        if (cMerkki != ' ' && islower(cMerkki) == 0 && isupper(cMerkki) == 0 && isdigit(cMerkki) == 0) {
            //printf("Ei lisätty merkkiä '%c'.\n\n", cMerkki);
            continue;
        } else {
            //printf("Jonoon lisättiin merkki '%c'\n", cMerkki);
            pJono[j] = cMerkki;
            j++;
            //printf("Jono on nyt '%s'\n\n", pJono);
        }
    }
    memset (pJono + strlen(pJono), '\0', 1 * sizeof(char));
    return(pJono);
}

void tarkistaC(char *pJono) {
    int iPituus;
    char merkki = 'c';

    if (strchr(pJono, merkki) == NULL) {
        printf("Merkkijonossa ei ollut merkkiä 'c'.\n");
    } else {
        printf("Merkkijonosta löydettiin merkki 'c'.\n");
    }

    iPituus = strlen(pJono);
    printf("Generoitiin merkkijono '%s', jossa on %d merkkiä.\n", pJono, iPituus);
}