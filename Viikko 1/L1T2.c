#include <stdio.h>

int main(void) {

    int luku1;
    float luku2;

    printf("Anna kokonaisluku: ");
    scanf("%d", &luku1);

    printf("Anna liukuluku: ");
    scanf("%f", &luku2);

    printf("Annoit luvut %d ja %.2f.\n", luku1, luku2);


    return(0);
}