#include <stdio.h>

int main(void) {
  for (int i = 0; i <= 256; i++) {
    char letter = (char)i;
    printf("%c", letter);
  }
  printf("\n");
}
