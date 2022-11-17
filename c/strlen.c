#include <stdio.h>

int len2(const char *s) {
  const char *a = s;
  for (; *s; s++)
    ;
  return s - a;
}

int len(const char *str) {
  size_t l = 0;
  for (; *str++ != '\0'; l++)
    ;
  return l;
}

int main(void) {
  char *foo = "bar";
  printf("Length of %s: %d\n", foo, len(foo));
  printf("Length of %s: %d\n", foo, len2(foo));
}
