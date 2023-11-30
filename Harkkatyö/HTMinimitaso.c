/*************************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
* Tekijä: Ari Holahan
* Opiskelijanumero: 0567782
* Päivämäärä: 05.07.2023
* Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
* lähteet ja henkilöt, ja se näkyy tehtävässä seuraavalla tavalla: 
* Ei ole käytetty muita lähteitä kuin ohjelmointiopasta.
* Mahdollisen vilppiselvityksen varalta vakuutan, että olen tehnyt itse
* tämän tehtävän ja vain yllä mainitut henkilöt sekä lähteet ovat
* vaikuttaneet siihen yllä mainituilla tavoilla.
*/
/*************************************************************************/

/* Tehtävä: Harjoitustyö Minimitaso, tiedoston nimi: HTMinimitaso.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIMILEN 52
#define RIVILEN 255

typedef struct tiedot {
    char pNimi[NIMILEN];
    long int liLkm;
    struct tiedot *pSeuraava;
} NIMET;

typedef struct analyysi {
    float keskiNimiP;
    char pisinNimi[NIMILEN], lyhyinNimi[NIMILEN], yleisinNimi[NIMILEN];
    long int alkioLkm, yleisinLkm, pisinLkm, lyhyinLkm;
    int pisinPituus, lyhyinPituus;
} ANALYYSI;


int valikko();

char *kysyTiedostoNimi(char *pNimi);

NIMET *lueTiedosto(char *pNimi, NIMET *pAlku);

ANALYYSI analysoiTiedot(NIMET *pAlku);

void kirjoitaTulokset(char *pTulosNimi, char *pNimi, ANALYYSI analysis);

NIMET *lisaaSolmu(NIMET *pAlku, char *pRivi);

NIMET *tyhjennaLista(NIMET *pAlku);


int main(void) {
    int iValinta;
    char sNimi[NIMILEN];
    char sTulosNimi[NIMILEN];
    char *pTulosNimi = sTulosNimi;
    char *pNimi = sNimi;
    NIMET *pAlku = NULL;
    ANALYYSI tulokset;
    // Alustus virheitä varten
    tulokset.alkioLkm = -1;

    do {
        iValinta = valikko();
        if (iValinta == 1) {
            pAlku = tyhjennaLista(pAlku);
            pNimi = kysyTiedostoNimi(sNimi);
            pAlku = lueTiedosto(pNimi, pAlku);
        } else if (iValinta == 2) {
            if (pAlku == NULL) {
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n");
            } else {
                tulokset = analysoiTiedot(pAlku);
            }
        } else if (iValinta == 3) {
            if (tulokset.alkioLkm == -1) {
                printf("Ei kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n");
            } else {
                pTulosNimi = kysyTiedostoNimi(sTulosNimi);
                kirjoitaTulokset(pTulosNimi, pNimi, tulokset);
            }
        } else if (iValinta == 0) {
            printf("Lopetetaan.\n");
            break;
        } else {
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("\n");
    } while (iValinta != 0);

    pAlku = tyhjennaLista(pAlku);

    printf("\nKiitos ohjelman käytöstä.\n");

    return(0);
}

int valikko() {
    int iValinta;

    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");

    scanf("%d", &iValinta);
    getchar();

    return iValinta;
}

char *kysyTiedostoNimi(char *pNimi) {
    printf("Anna tiedoston nimi: ");
    scanf("%s", pNimi);
    return pNimi;
}

NIMET *lueTiedosto(char *pTiedostoNimi, NIMET *pAlku) {

    FILE *tiedosto;
    char aRivi[RIVILEN];
    char *pOtsikkorivi;
    int iLaskin = 0;

    if ((tiedosto = fopen(pTiedostoNimi, "r")) == NULL ) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    } 

    while (fgets(aRivi, RIVILEN, tiedosto) != NULL) {
        if (iLaskin == 0) {
            // Ohitetaan otsikkorivi
            if ((pOtsikkorivi = strtok(aRivi, ";")) == NULL) {
                printf("Merkkijonon pilkkominen epäonnistui, lopetetaan\n");
                exit(0);
            }
            if (strcmp(pOtsikkorivi, "Sukunimi") == 0) {
                iLaskin++;
                continue;
            }
        } else {
            // lisätään tiedot listaan
            pAlku = lisaaSolmu(pAlku, aRivi);
        }
        iLaskin++;
    }

    fclose(tiedosto);
    printf("Tiedosto '%s' luettu.\n", pTiedostoNimi);
    return(pAlku);
}

ANALYYSI analysoiTiedot(NIMET *pAlku) {

    NIMET *pLiukuri = pAlku;
    ANALYYSI analysis;
    // Alustetaan tulokset virheiden välttämiseksi
    analysis.alkioLkm = 0;
    analysis.keskiNimiP = 0;
    analysis.lyhyinPituus = NIMILEN;
    analysis.lyhyinLkm = 0;
    analysis.pisinPituus = 0;
    analysis.pisinLkm = 0;
    analysis.yleisinLkm = 0;
    float fYhteinenPituus = 0, fAlkioLkm = 0;

    while (pLiukuri != NULL) {
        // lisätään alkioiden lukumäärää ja yhteistä pituutta keskimäärää varten
        analysis.alkioLkm++;
        fYhteinenPituus += strlen(pLiukuri->pNimi);

        if (strlen(pLiukuri->pNimi) >= analysis.pisinPituus) {
            // Onko nimi yhtä pitkä? Jos joo, onko se yleisempi?
            if (strlen(pLiukuri->pNimi) == analysis.pisinPituus) {
                if (pLiukuri->liLkm > analysis.pisinLkm) {
                    analysis.pisinPituus = strlen(pLiukuri->pNimi);
                    analysis.pisinLkm = pLiukuri->liLkm;
                    strcpy(analysis.pisinNimi, pLiukuri->pNimi);                   
                }
            } else {
                analysis.pisinPituus = strlen(pLiukuri->pNimi);
                analysis.pisinLkm = pLiukuri->liLkm;
                strcpy(analysis.pisinNimi, pLiukuri->pNimi);
            }
        }
        if (strlen(pLiukuri->pNimi) <= analysis.lyhyinPituus) {
            if (strlen(pLiukuri->pNimi) == analysis.lyhyinPituus) {
                if (pLiukuri->liLkm > analysis.lyhyinLkm) {
                    analysis.lyhyinPituus = strlen(pLiukuri->pNimi);
                    analysis.lyhyinLkm = pLiukuri->liLkm;
                    strcpy(analysis.lyhyinNimi, pLiukuri->pNimi);                    
                }
            } else {
                analysis.lyhyinPituus = strlen(pLiukuri->pNimi);
                analysis.lyhyinLkm = pLiukuri->liLkm;
                strcpy(analysis.lyhyinNimi, pLiukuri->pNimi);
            }
        }
        if (pLiukuri->liLkm > analysis.yleisinLkm) {
            analysis.yleisinLkm = pLiukuri->liLkm;
            strcpy(analysis.yleisinNimi, pLiukuri->pNimi); 
        }
        // seuraava alkio
        pLiukuri = pLiukuri->pSeuraava;
    }

    // lasketaan keskimääräinen pituus
    fAlkioLkm += analysis.alkioLkm;
    analysis.keskiNimiP = fYhteinenPituus / fAlkioLkm;

    printf("Analysoitu %ld nimeä.\n", analysis.alkioLkm);

    return(analysis);
}

void kirjoitaTulokset(char *pTulosNimi, char *pNimi, ANALYYSI analysis) {
    FILE *tiedosto;

    if ((tiedosto = fopen(pTulosNimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);        
    }

    fprintf(tiedosto, "Analysoitiin tiedosto '%s'.\n", pNimi);
    fprintf(tiedosto, "Tiedostossa on yhteensä %li eri nimeä.\n", analysis.alkioLkm);
    fprintf(tiedosto, "Yleisin nimi on '%s', joka on %li ihmisellä.\n", analysis.yleisinNimi, analysis.yleisinLkm);
    fprintf(tiedosto, "Lyhyin nimi '%s' on %d merkkiä pitkä.\n", analysis.lyhyinNimi, analysis.lyhyinPituus);
    fprintf(tiedosto, "Pisin nimi '%s' on %d merkkiä pitkä.\n", analysis.pisinNimi, analysis.pisinPituus);
    fprintf(tiedosto, "Keskimääräinen nimen pituus on %.1f merkkiä.\n", analysis.keskiNimiP);

    fclose(tiedosto);
    printf("Tiedosto '%s' kirjoitettu.\n", pTulosNimi);

    return;
}

NIMET *lisaaSolmu(NIMET *pAlku, char *pRivi) {
    NIMET *pUusi, *pLiukuri;
    char *pSukunimi, *pLkm;

    if ((pUusi = (NIMET*)malloc(sizeof(NIMET))) == NULL) {
        perror("Muistinvaraus epäonnistui, lopetetaan");
        exit(0);
    }

    if ((pSukunimi = strtok(pRivi, ";")) == NULL) {
        printf("Merkkijonon '%s' pilkkominen epäonnistui, lopetetaan\n", pRivi);
        exit(0);
    }
    if ((pLkm = strtok(NULL, ";")) == NULL) {
        printf("Merkkijonon '%s' pilkkominen epäonnistui, lopetetaan\n", pRivi);
        exit(0);
    }
    
    strcpy(pUusi->pNimi, pSukunimi);
    pUusi->liLkm = atol(pLkm);
    pUusi->pSeuraava = NULL;

    if (pAlku == NULL) {
        pAlku = pUusi;
    } else {
        pLiukuri = pAlku;
        while (pLiukuri->pSeuraava != NULL) {
            pLiukuri = pLiukuri->pSeuraava;
        }
        pLiukuri->pSeuraava = pUusi;
    }

    return(pAlku);
}

NIMET *tyhjennaLista(NIMET *pAlku) {
    NIMET *pLiukuri = pAlku;

    while (pLiukuri != NULL) {
        pAlku = pLiukuri->pSeuraava;
        free(pLiukuri);
        pLiukuri = pAlku;
    }

    return(pAlku);
}


/* eof */