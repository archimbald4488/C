#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    FILE *tiedosto;
    int i = 0;
    char sRivi[54], sNimi[54] = "L4T2D1.txt";

    if (argc != 3) {
        if (argc < 3) {
            printf("Et antanut tarpeeksi parametreja.\n");
        } else if (argc > 3) {
            printf("Annoit liikaa parametreja.\n");
        }
    } else {

        tiedosto = fopen(argv[1], "r");

        if ((tiedosto = fopen(argv[1], "r")) == NULL) {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }

        while (fgets(sRivi, 52, tiedosto) != NULL && i < atoi(argv[2])) {
            printf("%s", sRivi);
            i++;
        }

        fclose(tiedosto);

        if (i != atoi(argv[2])) {
            printf("\nTiedostossa ei ole enempää rivejä luettavaksi.\n");
            printf("Tiedostosta '%s' luettu %d riviä.\n", sNimi, i);
        } else {  
            printf("\nTiedostosta '%s' luettu %d riviä.\n", sNimi, i);
        }
    }

    return(0);
}