#include <stdio.h>

void increment(int *ptr) {
  ++(*ptr);   // works 
  (*ptr)++;   // also works
  *ptr += 1;  // yes, i too work
}

int main(void) {
  int foo = 0;

  printf("foo: %d\n", foo);
  increment(&foo);
  printf("foo: %d\n", foo);
}
