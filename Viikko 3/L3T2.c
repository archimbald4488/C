#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int lukee(char *sNimi);

void kirjoittaa(int iSumma, char *sNimi);

int main(void) {

    char sNimi[MAX];
    int iSumma;

    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", sNimi);
    getchar();

    iSumma = lukee(sNimi);
    printf("Tiedosto '%s' luettu, lukujen summa oli %d.\n", sNimi, iSumma);

    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", sNimi);
    getchar();

    kirjoittaa(iSumma, sNimi);
    printf("Tiedosto '%s' kirjoitettu.\n", sNimi);
    printf("\nKiitos ohjelman käytöstä.");

    return(0);
}

int lukee(char *sNimi) {

    FILE *tiedosto;
    int iSumma = 0, rivi;

    if ((tiedosto = fopen(sNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    tiedosto = fopen(sNimi, "r");
    while (fscanf(tiedosto, "%d", &rivi) != -1) {
        iSumma = iSumma + rivi;
    }
    fclose(tiedosto);

    return(iSumma);
}

void kirjoittaa(int iSumma, char *sNimi) {
    
    FILE *tiedosto;

    if ((tiedosto = fopen(sNimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui");
        exit(0);
    }

    tiedosto = fopen(sNimi, "w");

    fprintf(tiedosto, "Lukujen summa oli %d.\n", iSumma);
    
    fclose(tiedosto);
}