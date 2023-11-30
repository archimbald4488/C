#include <stdio.h>
#include <string.h>

int main(void) {

    char cMerkki;
    char sMjono[15];
    int iASCII, iSumma = 0;

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);
    getchar();

    iASCII = cMerkki;
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", cMerkki, iASCII);

    printf("Anna merkkijono: ");
    scanf("%s", sMjono);
    getchar();

    int i;
    for (i = 0; i < strlen(sMjono); i++) {
        iASCII = sMjono[i];
        iSumma = iSumma + iASCII;
        // printf("iASCII on %d ja summa on %d.\n", iASCII, iSumma);
    }

    printf("Merkkijonon '%s' merkkien summa on %d.", sMjono, iSumma);

    return(0);
}