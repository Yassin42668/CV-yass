#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

unsigned int mask_to_int(const char *mask_str) {
    struct in_addr addr;
    if (inet_pton(AF_INET, mask_str, &addr) != 1) {
        printf("Erreur saisie incorrecte: %s\n", mask_str);
        exit(1);
    }
    return ntohl(addr.s_addr);
}

int main() {
    char mask_str[16];
    unsigned int mask;

    printf("Saisir un masque de sous-réseau: ");
    scanf("%15s", mask_str);
    mask = mask_to_int(mask_str);

    printf("Masque sous-réseau (32 bits): %u\n", mask);
    return 0;
}