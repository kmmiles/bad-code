#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a[100][100], i, j;
  int m = 0;
  int n = 0;

  srand((unsigned int)time((long *)0));

  do {
    printf("first num: ");
    // scanf("%d", &m);
  } while (m < 0 || m >= 3);

  do {
    printf("second num: ");
    // scanf("%d", &n);
  } while (n < 0 || n >= 3);

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      do {
        a[i][j] = rand();
      } while (a[i][j] <= 10 || a[i][j] >= 20);
    }
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d   ", a[i][j]);
    }
  }

  return 0;
}
