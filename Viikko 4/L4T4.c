#include <stdio.h>
#include <stdlib.h>

#define RIVI 3
#define SARAKE 3

void kysyNimi(char *pNimi);

void tulosta(int iMatriisi[RIVI][SARAKE], char *pMatriisiNimi, char *pNimi);

int main(void) {

    int matriisi[RIVI][SARAKE], i, j;
    char sNimi[30];
    char sMnimi[] = "Lähtömatriisi";

    kysyNimi(sNimi);

    printf("Anna arvot lähtömatriisille: \n");
    for (i=0; i<RIVI; i++) {
        for (j=0; j<SARAKE; j++) {
            printf("Rivi %d, alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi[i][j]);
        }
    }

    tulosta(matriisi, sMnimi, sNimi);

    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}

void kysyNimi(char *pNimi) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    getchar();    
}

void tulosta(int iMatriisi[RIVI][SARAKE], char *pMatriisiNimi, char *pNimi) {
    int i, j;
    FILE *tiedosto;
    tiedosto = fopen(pNimi, "w");

    if ((tiedosto = fopen(pNimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("\n%s: \n", pMatriisiNimi);
    for (i=0; i<RIVI; i++) {
        for (j=0; j<SARAKE; j++) {
            printf("%4d ", iMatriisi[i][j]);
        }
        printf("\n");
    }
    printf("\nLähtömatriisin transpoosi: \n");
    for (i=0; i<RIVI; i++) {
        for (j=0; j<SARAKE; j++) {
            printf("%4d ", iMatriisi[j][i]);
        }
        printf("\n");
    }

    fprintf(tiedosto, "%s: \n", pMatriisiNimi);
    for (i=0; i<RIVI; i++) {
        for (j=0; j<SARAKE; j++) {
            fprintf(tiedosto, "%4d ", iMatriisi[i][j]);
        }
        fprintf(tiedosto, "\n");
    }
    fprintf(tiedosto, "\nLähtömatriisin transpoosi: \n");
    for (i=0; i<RIVI; i++) {
        for (j=0; j<SARAKE; j++) {
            fprintf(tiedosto, "%4d ", iMatriisi[j][i]);
        }
        fprintf(tiedosto, "\n");
    }    
    fclose(tiedosto);

    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
}