#include <stdio.h>

void func(char *s) { printf("s: %s\n", s); }

int main(void) {
  char array[] = "asdfasfasdf";
  func(array);
}
