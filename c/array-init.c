#include <stdio.h>

#define ARRAY_SIZE 10

int main(void) {
  char foo[ARRAY_SIZE] = {5};
  for(int i=0; i < ARRAY_SIZE; i++) {
    printf("foo[%d] = %d\n", i, foo[i]);
  }
}
