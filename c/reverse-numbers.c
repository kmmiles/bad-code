#include <stdio.h>

unsigned int reverse_num(unsigned int n) {
  unsigned int reverse = 0;
  for (unsigned int i = n; i != 0; i /= 10) {
    reverse = reverse * 10 + i % 10;
  }
  return reverse;
}

int main(void) {
  printf("reverse 4321: %u\n", reverse_num(4321));
  printf("reverse 1234: %u\n", reverse_num(1234));
}
