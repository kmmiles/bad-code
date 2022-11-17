#include <stdio.h>
#include <stdlib.h>

int main(void) {

  const char *num = "12345.11";

  printf("atoi=%d\n", atoi(num));
  printf("strtol=%d\n", (int)strtol(num, NULL, 10));

  /*
  printf("atoi=%d\nstrtol=%ld\n",
      atoi(num),
      strtol(num, NULL, 10));
      */
}
