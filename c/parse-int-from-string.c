#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int main(void) {
  char *string = "count=20";

  printf("string: %s\n", string);

  char *p = rindex(string, '=');
  if(!p) {
    printf("token not found\n");
    exit(EXIT_FAILURE);
  }
  p += 1;
  if(!p) {
    printf("nothing after token\n");
    exit(EXIT_FAILURE);
  }

  printf("p: %s\n", p);
}

