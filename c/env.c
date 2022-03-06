#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *var = getenv("FOOBAR");

  if (var) {
    printf("var: %s\n", var);
  } else {
    printf("var: NULL\n");
  }
}
