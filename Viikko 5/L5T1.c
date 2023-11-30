#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *varaaMuisti(char *ptr);

void kysyMjono(char *ptr);

int main(void) {

    char *ptr = NULL;

    ptr = varaaMuisti(ptr);

    kysyMjono(ptr);

    free(ptr);
    ptr = NULL;
    printf("Muisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");

    return(0);
}

char *varaaMuisti(char *ptr) {

    if ((ptr = (char *)malloc(30 * sizeof(char))) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }

    printf("Muisti varattu 30 merkille.\n");

    return ptr;
}

void kysyMjono(char *ptr) {
    char lukupuskuri[255];

    printf("Anna merkkijono: ");
    fgets(lukupuskuri, 30, stdin);
    lukupuskuri[strlen(lukupuskuri) - 1] = '\0';

    strcpy(ptr, lukupuskuri);

    printf("Annoit merkkijonon '%s'.\n", ptr);

}