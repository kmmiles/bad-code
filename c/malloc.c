#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *mander = calloc(1, 11);
  strncpy(mander, "charmander", 11);
  printf("%s\n", mander);
}
