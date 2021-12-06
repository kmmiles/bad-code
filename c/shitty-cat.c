#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *f;
  int c;

  f = fopen(argv[1], "r");
  while ((c = getc(f)) != EOF) putchar(c);
}
