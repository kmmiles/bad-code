#include <stdio.h>

int main(int argc, char *argv[]) {
  char *prog = argv[0];
  char *source = argv[1];
  char *dest = argv[2];

  printf("argc: %d\n", argc);
  if (!source || !dest) {
    fprintf(stderr, "Usage: %s <source> <destination>\n", prog);
    return (1);
  }

  printf("source = %s\ndestination = %s\n", source, dest);
}
