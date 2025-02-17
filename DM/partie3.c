#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

unsigned int calculer_adresse_reseau(unsigned int ip, unsigned int mask) {
    return ip & mask;
}

int main() {
    unsigned int ip, mask, reseau;

    printf("Saisir une adresse IP (32 bits): ");
    scanf("%u", &ip);
    printf("Saisir un masque de sous-réseau (32 bits): ");
    scanf("%u", &mask);

    reseau = calculer_adresse_reseau(ip, mask);
    printf("Adresse réseau (32 bits): %u\n", reseau);
    return 0;
}