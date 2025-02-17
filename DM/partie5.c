#include <stdio.h>
#include <stdlib.h>

int calculer_cidr(unsigned int mask) {
    int count = 0;
    while (mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

int main() {
    unsigned int mask;

    printf("Saisir un masque de sous-réseau (32 bits): ");
    scanf("%u", &mask);

    printf("CIDR: /%d\n", calculer_cidr(mask));
    return 0;
}