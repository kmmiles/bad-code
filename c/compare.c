#include <stdio.h>

int main(void) {
  char *foo = NULL;

  foo = strdup("bar");
  if (!foo) {
    fprintf(stderr, "bad things\n");
    exit(1);
  }
}
