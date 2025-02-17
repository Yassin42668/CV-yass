#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

unsigned int ip_to_int(const char *ip_str) {
    struct in_addr addr;
    inet_pton(AF_INET, ip_str, &addr);
    return ntohl(addr.s_addr);
}

unsigned int calculer_adresse_reseau(unsigned int ip, unsigned int mask) {
    return ip & mask;
}

unsigned int calculer_adresse_broadcast(unsigned int ip, unsigned int mask) {
    return ip | ~mask;
}

int calculer_cidr(unsigned int mask) {
    int count = 0;
    while (mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

int main() {
    char ip_str[16], mask_str[16];
    unsigned int ip, mask, reseau, broadcast;

    printf("Saisir une adresse IP: ");
    scanf("%15s", ip_str);
    ip = ip_to_int(ip_str);

    printf("Saisir un masque de sous-réseau: ");
    scanf("%15s", mask_str);
    mask = ip_to_int(mask_str);

    reseau = calculer_adresse_reseau(ip, mask);
    broadcast = calculer_adresse_broadcast(ip, mask);

    printf("Adresse réseau: %u /%d\n", reseau, calculer_cidr(mask));
    printf("Adresse broadcast: %u\n", broadcast);

    return 0;
}