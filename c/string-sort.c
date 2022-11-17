#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

void qqsort(char *s) {
  size_t len = strlen(s);
  for (int i = 0; i < len; i++) {
    // for (int j = i + 1; j < len; j++) {
    for (int j = 0; j < len - i - 1; j++) {
      // printf("Swapping %c and %c\n", s[i], s[j]);
      // printf("%c vs %c - ", s[i], s[j]);
      if (s[i] > s[j]) {
        // printf("swapping %c and %c", s[i], s[j]);
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
      } else {
        // printf("not swapping");
      }
      // printf("\n");
    }
  }
}

char *qqqsort(const char *s, bool desc) {
  size_t len = strlen(s);
  char *st = calloc(len, sizeof(char));
  strcpy(st, s);

  for (int i = 0; i < len; i++) {
    for (int x = i + 1; x < len; x++) {
      if (desc ? st[i] < st[x] : st[i] > st[x]) {
        char temp = st[i];
        st[i] = st[x];
        st[x] = temp;
      }
    }
  }

  return (st);
}

void swapchars(char *c1, char *c2) {
  if (c1 && c2) {
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
  }
}

void qqqqsort(char *s) {
  size_t len = strlen(s);

  while (1) {
    bool didswap = false;
    for (int i = 0; i < len - 1; i++) {
      if (s[i] > s[i + 1]) {
        swapchars(&s[i], &s[i + 1]);
        didswap = true;
      }
    }

    if (!didswap) {
      return;
    }
  }
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

  strcpy(s, argv[1] ? argv[1] : "");
  qqqqsort(s);
  printf("qqqqsort\t=\t%s\n", s);
}
