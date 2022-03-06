#include <assert.h>
#include <stdio.h>
#include <string.h>

char *strurlify(const char *s, size_t len) {
  if (!s || !len) {
    return (NULL);
  }

  /* find length of string, not counting trailing spaces */
  size_t len_trimmed = len;
  for (int i = len - 1; i >= 0 && s[i] == ' '; i--) {
    printf("s[%d] = \"%c\"\n", i, s[i]);
    len_trimmed--;
  }

  printf("len: %lu\nlen_trimmed: %lu\n", len, len_trimmed);

  /*
  for(int i = 0; i < len; i++) {
    printf("s[%d] = %c\n", i, s[i]);
  }
  //printf("s=%s\n", s);
  */

  return (NULL);
}

int main(int argc, char **argv) {
  // char *input = "Mr John Smith    ";

  assert(argv[1]);
  char *output = strurlify(argv[1], strlen(argv[1]));
  printf("output: %s\n", output);
}
