#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tulosta(char *pJono, int x);

void atsolut(char *pJono, int x);

int main(int argc, char *argv[]) {
    int iValinta;

    if (argc != 2) {
        if (argc < 2) {
            printf("Et antanut tarpeeksi parametreja.");
        } else {
            printf("Annoit liikaa parametreja.");
        }
        exit(0);
    }

    do {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Tulosta merkkijono\n");
        printf("2) Tulosta merkkijono takaperin\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &iValinta);

        switch (iValinta) {
            case 1:
                tulosta(argv[1], 0);
                printf("\n");
                break;
            case 2:
                atsolut(argv[1], strlen(argv[1]) - 1);
                printf("\n");
                break;

            case 0:
                printf("Lopetetaan.\n");
                break;

            default:
                printf("Ei tunnistettu. Yritä uudelleen.\n");
                break;
        }
    } while (iValinta != 0);

    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}

void tulosta(char *pJono, int x) {
    if (x == strlen(pJono) - 1) {
        printf("%c\n", pJono[x]);
        return;
    } else {
        printf("%c\n", pJono[x]);
    }
    tulosta(pJono, x + 1);
}

void atsolut(char *pJono, int x) {
    if (x == 0) {
        printf("%c\n", pJono[x]);
        return;
    } else {
        printf("%c\n", pJono[x]);
    }
    atsolut(pJono, x - 1);
}