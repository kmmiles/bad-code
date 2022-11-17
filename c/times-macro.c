#include <stdio.h>

#define times(x, y) (x * y)

int main(void) {
  int b;
  int a = 2;

  b = times(a + 1, 3);

  printf("b=%d\n", b);
  printf("hello: %d\n", 2 + 1 * 3);
}
