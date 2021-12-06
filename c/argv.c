#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  printf("Hello world: %c\n", argv[1][strlen(argv[1]) - 1]);
}
