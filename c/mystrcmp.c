#include <stdio.h>

int mystrcmp(const char *s1, const char *s2) {
  printf("%c (%d) - %c (%d)\n", *s1, *s1, *s2, *s2);
  while (*s1 && *s1 == *s2) {
    s1++;
    s2++;
    printf("%c (%d) - %c (%d)\n", *s1, *s1, *s2, *s2);
  }
  return (*s1 - *s2);
}

int badstrcmp(const char *a, const char *b) {
  for (int i = 0; a[i] != 0; i++) {
    if (a[i] != b[i]) {
      return (1);
    }
  }
  return (0);
}

int main(void) {
  const char *str1 = "foooobar";
  const char *str2 = "f";
  int rc = -1;

  rc = mystrcmp(str1, str2);
  printf("returned: %d\n", rc);

  // rc = badstrcmp(str1, str2);
  // printf("returned: %d\n", rc);
}
