#include <stdio.h>

int main(void) {

    int iMaara, iArvosana;

    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d", &iMaara);

    if (iMaara < 30 * 0.5) {
        iArvosana = 0;
    } else if (iMaara < 30 * 0.6) {
        iArvosana = 1;
    } else if (iMaara < 30 * 0.7) {
        iArvosana = 2;
    } else if (iMaara < 30 * 0.8) {
        iArvosana = 3;
    } else if (iMaara < 30 * 0.9) {
        iArvosana = 4;
    } else if (iMaara <= 30) {
        iArvosana = 5;
    } else {
        iArvosana = -1;
    }

    if (iArvosana < 0) {
        printf("Kurssilla on vain 30 tehtävää.");
    } else {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.", iMaara, iArvosana);
    }


    return(0);
}