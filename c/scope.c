#include <stdio.h>

int main() {
  int* a;
  {
    int b = 20;
    a = &b;
  }
  printf("%d\n", *a);
  return 0;
}
