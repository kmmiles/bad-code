#include <stdio.h>

unsigned long _arg2codes(const char *input) {
  unsigned long result = 0;
  for (size_t i = 0; input[i]; i++) {
    result *= 1000;
    result += (unsigned long)input[i];
  }
  return result;
}

int main(void) { printf("%lu\n", _arg2codes("111")); }
