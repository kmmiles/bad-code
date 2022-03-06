#include <stdio.h>

int main(void) {
  int x = 8;
  int y = ++x + ++x * x--;

  printf("x=%d, y=%d\n", x, y);
}
