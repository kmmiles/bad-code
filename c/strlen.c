#include <stdio.h>

int len(char *str) {
  int l = 0;
  while(*str++ != '\0') 
    l++;
  return l;
}

int main(void) {
  char *foo = "bar";
  printf("Length of %s: %d\n", foo, len(foo));
}

