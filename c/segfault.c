#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *s = malloc(1);
  strcpy(s, "hello worldaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  printf("s = %s\n", s);
}
