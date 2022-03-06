#include <stdio.h>

void foo(int x) {
  static int y = 606;
  printf("y=%d\n", y);
  y = x;
}

int main(void) {
  for (int i = 0; i < 10; i++) {
    foo(-1);
  }
}
