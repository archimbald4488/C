#include <stdio.h>
#include <stdlib.h>

int valikko(int *pLuku, char *sNimi);

void kirjoita(int *pLuku, char *sNimi);

void tulosta(char *sNimi);

int main(void) {

    int iLuku, iValinta;
    char sNimi[30];

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", sNimi);
    getchar();

    do {

        iValinta = valikko(&iLuku, sNimi);

    } while (iValinta != 0);

    printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.");

    return(0);
}

int valikko(int *pLuku, char *sNimi) {

    int iValinta;

    printf("\nValitse haluamasi toiminto:\n");
    printf("1) Lisää lukuun\n");
    printf("2) Tulosta tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);

    if (iValinta == 1) {

        kirjoita(pLuku, sNimi);

    } else if (iValinta == 2) {

        tulosta(sNimi);

    } else if (iValinta == 0) {

        return(0);

    } else {
        printf("\nTuntematon valinta, yritä uudestaan.\n");
    }

    return(1);
}

void kirjoita(int *pLuku, char *sNimi) {

    int iLuku2;
    FILE *tiedosto;

    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLuku2);

    *pLuku = *pLuku + iLuku2;
    
    printf("%d+%d=%d\n", *pLuku - iLuku2, iLuku2, *pLuku);

    if ((tiedosto = fopen(sNimi, "a")) == NULL) {
    perror("Tiedoston avaaminen epäonnistui, lopetetaan");
    exit(0);
    }
    tiedosto = fopen(sNimi, "a");
    fprintf(tiedosto, "%d+%d=%d\n", *pLuku - iLuku2, iLuku2, *pLuku);
    fclose(tiedosto);
}

void tulosta(char *sNimi) {

    FILE *tiedosto;
    char rivi[30];

    if ((tiedosto = fopen(sNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fopen(sNimi, "r");
    printf("\nTiedostossa oleva laskuhistoria:\n");
    while (fscanf(tiedosto, "%s", rivi) != -1) {
        printf("%s\n", rivi);
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", sNimi);
}