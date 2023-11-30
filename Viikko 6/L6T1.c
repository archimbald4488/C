#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct kirjaimia {
    char cKirjain;
    struct kirjaimia *pSeuraava;
} KIRJAIMET;

int main(void) {

    KIRJAIMET *pAlku = NULL, *pLoppu = NULL;
    KIRJAIMET *pLiukuri, *pUusi;
    char cMerkki;

    printf("Anna listan kirjaimet.\n");
    do {
        printf("Anna kirjain, q lopettaa: ");
        scanf("%c", &cMerkki);
        getchar();

        if (cMerkki == 'q') {
            break;
        }

        if ((pUusi = (KIRJAIMET*)malloc(sizeof(KIRJAIMET))) == NULL) {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }

        pUusi->cKirjain = cMerkki;
        pUusi->pSeuraava = NULL;

        if (pAlku == NULL) {
            pAlku = pUusi;
            pLoppu = pUusi;
        } else {
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }

    } while (cMerkki != 'q');

    pLiukuri = pAlku;
    printf("Listassa on seuraavat kirjaimet:\n");
    while (pLiukuri != NULL) {
        printf("%c ", pLiukuri->cKirjain);
        pLiukuri = pLiukuri->pSeuraava;
    }

    pLiukuri = pAlku;
    while (pLiukuri != NULL) {
        pAlku = pLiukuri->pSeuraava;
        free(pLiukuri);
        pLiukuri = pAlku;
    }

    printf("\n\nMuisti vapautettu.\nKiitos ohjelman käytöstä.\n");

    return(0);
}