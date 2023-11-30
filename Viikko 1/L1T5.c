#include <stdio.h>


int main(void) {

    char sLemNimi[30];
    char sLemRotu[30];
    int iIka;
    float fPaino;

    printf("Anna lemmikin nimi: ");
    scanf("%s", sLemNimi);
    getchar();

    printf("Anna lemmikin rotu: ");
    scanf("%s", sLemRotu);
    getchar();

    printf("Anna lemmikin ikä: ");
    scanf("%d", &iIka);

    printf("Anna lemmikin paino: ");
    scanf("%f", &fPaino);

    printf("Lemmikin nimi on %s ja rotu on %s.\n", sLemNimi, sLemRotu);
    printf("Sen ikä on %d vuotta ja paino %.1f kg.", iIka, fPaino);

    return(0);
}