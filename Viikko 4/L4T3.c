#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

typedef struct lukuja {
    int iLuku1, iLuku2, iSumma;
}  LASKU;

void kysyTiedosto(char *pNimi);

void valikko(LASKU *pLasku, char *pNimi, int *pI);

void lisays(LASKU *pLasku);

void kirjoita(LASKU *pLasku, char *pNimi, int *pI);

void lue(char *sNimi);

int main(void) {

    LASKU lasku[SIZE]; //= {{22, 45, 67}, {10, 10, 20}};
    //LASKU *pLasku = lasku;
    //LASKU *pLasku2 = &pLasku[1];
    int iI = 0;
    char sNimi[SIZE];

/*     printf("Eka on %d toka on %d\n", pLasku->iLuku1, pLasku2->iSumma);
    exit(0); */

    printf("Anna kokonaisluku: ");
    scanf("%d", &lasku[0].iLuku1);

    kysyTiedosto(sNimi);

    valikko(lasku, sNimi, &iI);

    return(0);
}

void kysyTiedosto(char *pNimi) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    getchar();
}

void valikko(LASKU *pLasku, char *pNimi, int *pI) {

    int iValinta;

    do {
        printf("\nValitse haluamasi toiminto:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Kirjoita historia tiedostoon\n");
        printf("3) Lue historia tiedostosta\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
        case 1:
            lisays(&pLasku[*pI]);
            *pI = *pI + 1;
            pLasku[*pI].iLuku1 = pLasku[*pI - 1].iSumma;
            pLasku[*pI].iLuku2 = 0;
            pLasku[*pI].iSumma = -1;
            break;
        case 2:
            kirjoita(pLasku, pNimi, pI);
            break;
        case 3:
            lue(pNimi);
            break;
        case 0:
            printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.\n");
            break;
        default:
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            break;
        }

    } while (iValinta != 0);

    return;
}

void lisays(LASKU *pLasku) {

    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &pLasku->iLuku2);

    pLasku->iSumma = pLasku->iLuku1 + pLasku->iLuku2;

    printf("%d+%d=%d\n", pLasku->iLuku1, pLasku->iLuku2, pLasku->iSumma);
}

void kirjoita(LASKU *pLasku, char *pNimi, int *pI) {

    FILE *tiedosto;
    int a;

    if ((tiedosto = fopen(pNimi, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    for (a=0; a<sizeof(pLasku); a++) {
        LASKU *pLasku2 = &pLasku[a]; 
        if (pLasku2->iSumma == -1) {
            break;
        }
        fprintf(tiedosto, "%d+%d=%d\n", pLasku2->iLuku1, pLasku2->iLuku2, pLasku2->iSumma);
    }
    fclose(tiedosto);

    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
}

void lue(char *sNimi) {

    FILE *tiedosto;
    char rivi[30];

    if ((tiedosto = fopen(sNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fopen(sNimi, "r");
    printf("\nTiedostossa oleva laskuhistoria:\n");
    while (fgets(rivi, 28, tiedosto) != NULL) {
        printf("%s", rivi);
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", sNimi);
}