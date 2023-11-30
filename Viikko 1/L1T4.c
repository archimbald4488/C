#include <stdio.h>


int main(void) {

    char cMerkki;
    char sMjono[22] = "haloo";

    printf("Anna merkki: ");
    scanf("%c", &cMerkki);
    getchar();

    printf("Annoit merkin '%c'.\n", cMerkki);

    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", sMjono);
    getchar();

    printf("Annoit merkkijonon '%s'.\n", sMjono);


    return(0);
}