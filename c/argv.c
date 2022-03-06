#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("number of args: %d\n", argc);
  printf("program name: %s\n", argv[0]);

  for (int i = 1; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
}
