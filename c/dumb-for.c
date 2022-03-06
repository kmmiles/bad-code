#include <stdio.h>

int main() {
  int b = 5;
  int i = 0;

  for (; b; i++) {
    b = b + 1;
    // printf("b = %d\n", b);
  }

  return 0;
}
