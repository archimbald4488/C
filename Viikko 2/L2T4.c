#include <stdio.h>
#define PII 3.141

int main(void) {

    float fSade;
    int iValinta;

    printf("Anna ympyrän säde: ");
    scanf("%f", &fSade);

    printf("\nValikko:\n");
    printf("1) Laske ympyrän kehän pituus\n");
    printf("2) Laske ympyrän pinta-ala\n");
    printf("Valitse: ");
    scanf("%d", &iValinta);

    switch (iValinta) {
        case 1:
            printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.", fSade, 2 * fSade * PII);
            break;
        case 2:
            printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.", fSade, fSade * fSade * PII);
            break;
        default:
            printf("Tuntematon valinta.");
            break;
    }

    return(0);
}