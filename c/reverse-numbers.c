#include <stdio.h>

unsigned int GetReverse(unsigned int n) {
  unsigned int reverse = 0;
  for (unsigned int i = n; i != 0; i /= 10) {
    reverse = reverse * 10 + i % 10;
  }
  return reverse;
}

int main(void) {
  printf("reverse 4321: %u\n", GetReverse(4321));
  printf("reverse 1234: %u\n", GetReverse(1234));
}
