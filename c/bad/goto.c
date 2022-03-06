#include <stdio.h>

int somecondition = 1;
int anothercondition = 1;

int dosomething(void) {
  char *foo = malloc(100);
  if (somecondition) {
    goto err;
  }

  if (anothercondition) {
    goto err;
  }

err:
  free(foo);
  // do some other stuff
  return (1);
}

int main(void) {}
