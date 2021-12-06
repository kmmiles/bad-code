#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

void qqsort(char *s) {
  int len = strlen(s);
  for (int i = 0; i <= len - 1; i++) {
    for (int x = i + 1; x <= len - 1; x++) {
      if (s[i] > s[x]) {
        char temp = s[i];
        s[i] = s[x];
        s[x] = temp;
      }
    }
  }
}

char *qqqsort(const char *s, bool desc) {
  int len = strlen(s);
  char *st = calloc(len, sizeof(char));
  strcpy(st, s);

  for (int i = 0; i <= len - 1; i++) {
    for (int x = i + 1; x <= len - 1; x++) {
      if (desc ? st[i] < st[x] : st[i] > st[x]) {
        char temp = st[i];
        st[i] = st[x];
        st[x] = temp;
      }
    }
  }

  return (st);
}

int main(int argc, char **argv) {
  char s[256] = {0};
  strcpy(s, argv[1] ? argv[1] : "");
  printf("s\t=\t%s\n", s);
  qsort(s, strlen(s), sizeof(char), compar);
  printf("qsort\t=\t%s\n", s);

  strcpy(s, argv[1] ? argv[1] : "");
  qqsort(s);
  printf("qqsort\t=\t%s\n", s);

  strcpy(s, argv[1] ? argv[1] : "");

  char *st = qqqsort(s, true);
  printf("qqqsort\t=\t%s\n", st);
  free(st);
}
