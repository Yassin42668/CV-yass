#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

unsigned int ip_to_int(const char *ip_str) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip_str, &addr) != 1) {
        printf("Erreur saisie incorrecte: %s\n", ip_str);
        exit(1);
    }
    return ntohl(addr.s_addr);
}

int main() {
    char ip_str[16];
    unsigned int ip;

    printf("Saisir une adresse IP: ");
    scanf("%15s", ip_str);
    ip = ip_to_int(ip_str);

    printf("Adresse IP (32 bits): %u\n", ip);
    return 0;
}