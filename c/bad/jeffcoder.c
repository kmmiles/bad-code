#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("argc: %d\n", argc);
  for (int i = 1; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }
}
