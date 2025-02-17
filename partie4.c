#include <stdio.h>
#include <stdlib.h>

unsigned int calculer_adresse_broadcast(unsigned int ip, unsigned int mask) {
    return ip | ~mask;
}

int main() {
    unsigned int ip, mask, broadcast;

    printf("Saisir une adresse IP (32 bits): ");
    scanf("%u", &ip);
    printf("Saisir un masque de sous-réseau (32 bits): ");
    scanf("%u", &mask);

    broadcast = calculer_adresse_broadcast(ip, mask);
    printf("Adresse broadcast (32 bits): %u\n", broadcast);
    return 0;
}