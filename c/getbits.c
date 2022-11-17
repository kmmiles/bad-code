#include <stdio.h>

int main(void) {
  int num = 420;
  int k = 1;

  // int n = ((num & ((1<<44) - 1)) >> 32);
  //
  int n = (num & (1 << k)) >> k;

  printf("n=%d\n", n);
}
