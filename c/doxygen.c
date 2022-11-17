#include <stdio.h>
#include <stdlib.h>

/**
 * prints "Hello, world\n" <count> times.
 */
void hello_world(int count) {
  for (int i = 0; i < count; i++) {
    printf("Hello, world\n");
  }
}

int main(void) {
  hello_world(1);
  return 0;
}
