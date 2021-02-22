#include <stdio.h>
#include <string.h>

int main(void) {
    char distro[20] = {0};

    fgets(distro, sizeof(distro), stdin);
    distro[strlen(distro)-1] = '\0';
    if (!strcmp(distro, "Arch Linux"))
        printf("btw I use arch\n");
    else
        printf("btw I don't use arch\n");
}
