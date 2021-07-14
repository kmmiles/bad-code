#include <stdio.h>

#define MAC_ADDRESS "98:fa:9b:d5:d7:f2"

int main(void) {

    unsigned int mac_address[6];

    sscanf(MAC_ADDRESS, "%x:%x:%x:%x:%x:%x",
                  &mac_address[0], &mac_address[1],
                  &mac_address[2], &mac_address[3],
                  &mac_address[4], &mac_address[5]);

    for (int i = 0; i < 6; i++) {
        printf("%u\n", mac_address[i]);
    }
}

