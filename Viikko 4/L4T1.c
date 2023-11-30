#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct musiikki {
    char sNimi[MAX];
    char sEsittaja[MAX];
    char sPituus[MAX];
    int iJulkaisu;
} MUSIIKKI;

int main(void) {
    MUSIIKKI biisi;

    printf("Anna kappaleen nimi: ");
    fgets(biisi.sNimi, 52, stdin);
    biisi.sNimi[strlen(biisi.sNimi) - 1] = '\0';

    printf("Anna kappaleen esittäjä: ");
    fgets(biisi.sEsittaja, 52, stdin);
    biisi.sEsittaja[strlen(biisi.sEsittaja) - 1] = '\0';

    printf("Anna kappaleen pituus: ");
    scanf("%s", biisi.sPituus);
    getchar();

    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%d", &biisi.iJulkaisu);
    
    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", biisi.sNimi, biisi.sEsittaja);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %d.\n", biisi.sPituus, biisi.iJulkaisu);

    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}