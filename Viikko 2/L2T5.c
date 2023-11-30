#include <stdio.h>


int main(void) {

    int iLuku1, iLuku2, iValinta;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku1);

    do {
        printf("\nValikko:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Vähennä luvusta\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &iValinta);

        if (iValinta == 1) {

            printf("\nAnna lukuun lisättävä kokonaisluku: ");
            scanf("%d", &iLuku2);

            iLuku1 = iLuku1 + iLuku2;
            printf("Luku on nyt %d.\n", iLuku1);

        } else if (iValinta == 2) {

            printf("\nAnna luvusta vähennettävä kokonaisluku: ");
            scanf("%d", &iLuku2);

            iLuku1 = iLuku1 - iLuku2;
            printf("Luku on nyt %d.\n", iLuku1);

        } else if (iValinta == 0) {
            break;
        } else {
            printf("\nTuntematon valinta, yritä uudestaan.\n");
        }

    } while (iValinta != 0);

    printf("\nLopetetaan.\n\nKiitos ohjelman käytöstä.");

    return(0);
}