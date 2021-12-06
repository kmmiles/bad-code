#include <stdio.h>

int main(void) {
  char *string = "foo";
  printf("string: %s\n", string);
  printf("*string: %c\n", *string);
  printf("string[0]: %c\n", string[0]);
  printf("string[1]: %c\n", string[1]);
  printf("string[2]: %c\n", string[2]);
}
