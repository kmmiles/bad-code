#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
  int c, wl, w, maxfound;
  int wh[10] = {0};

  wl = w = maxfound = 0;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || c != '\n' || c != '\t') {
      ++wl;
    }

    if (wh[w] < wl) {
      wh[w] = wl;
      wl = 0;
      ++wh[w];
    }
  }

  printf("Character length of the largest 10 words:");

  for (int i = 0; i <= 9; ++i) printf(" %d", wh[i]);
}
