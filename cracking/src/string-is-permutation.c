#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

bool strisperm(const char *s1, const char *s2) {
  /* make and sort a copy of s1 */
  assert(s1);
  size_t s1_len = strlen(s1);
  char *s1_copy = calloc(s1_len + 1, sizeof(char));
  assert(s1_copy);
  strncpy(s1_copy, s1, s1_len);
  qsort(s1_copy, s1_len, sizeof(char), compar);

  /* make and sort a copy of s2 */
  assert(s2);
  size_t s2_len = strlen(s2);
  char *s2_copy = calloc(s2_len + 1, sizeof(char));
  assert(s2_copy);
  strncpy(s2_copy, s2, s2_len);
  qsort(s2_copy, s2_len, sizeof(char), compar);

  /* do the compare, free stuff and return */
  bool retval = strcmp(s1_copy, s2_copy) == 0 ? true : false;
  free(s1_copy);
  free(s2_copy);
  return (retval);
}

int main(int argc, char **argv) {
  if (strisperm(argv[1], argv[2])) {
    printf("yes, it's a perm\n");
  } else {
    printf("no, it's not a perm\n");
  }
}
