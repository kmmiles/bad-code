#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void thing(char *input) {
  char new_string[strlen(input)];
  printf("%lu\n", sizeof(new_string));
}

void better_thing(const char *s) {
  size_t s_len = s ? strlen(s) : 0;
  const char *s_new = calloc(1, s_len);
  printf("%lu\n", s_len);
}

int main(int argc, char **argv) {
  printf("doing better things\n");
  better_thing("another string");
  better_thing("");
  better_thing(NULL);

  printf("doing original things\n");
  thing("another string");
  thing("");
  thing(NULL);

  return 0;
}
