#include <stdio.h>
#define MAX 10
#define MIN 3

int main(void) {

    int iLuku;

    printf("Anna kokonaisluku väliltä 3 - 10: ");
    scanf("%d", &iLuku);
    printf("\n");

    if (iLuku > MAX || iLuku < MIN) {
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
    } else {
        int i, j;
        for (i = 0; i < iLuku; i++) {
            for (j = 0; j < iLuku; j++) {
                printf("*");
            }
        printf("\n");
        }

    }

    return(0);
}