#include <stdio.h>

#define SWAPPINESS "/proc/sys/vm/swappiness"

int main(void) {
    FILE *fp = NULL;
    int num = 0;

    fp = fopen(SWAPPINESS, "r");
    fscanf(fp, "%d", &num);

    printf("Hello, World\n");

}
