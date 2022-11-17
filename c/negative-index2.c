#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // int a[5] = {4, 3, 2, 1, 0};
  int a[5] = {9, 8, 7, 6, 5};
  int *p = a + 3;
  int x = *(p - p[-1]);

  printf("*p = %d\n", *p);
  printf("p[-1] = %d\n", p[-1]);
  printf("x: %d\n", x);
}
