#include <stdio.h>

float suorakulmio(float kanta, float korkeus);

int main(void) {

    float kanta, korkeus, vastaus;

    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &kanta);

    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &korkeus);

    vastaus = suorakulmio(kanta, korkeus);

    printf("Suorakulmion pinta-ala on %.2f.\n", vastaus);
    printf("Kiitos ohjelman käytöstä.");

    return(0);
}

float suorakulmio(float kanta, float korkeus) {
    
    float fPinta = kanta * korkeus;

    return(fPinta);
}