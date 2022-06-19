#include <stdio.h>
#define SIZE 5
int main(void) {
  printf("Hello, world\n");
  exit(0);
  int i, j, n[SIZE] = {1, 2, 3, 4, 5};
  for (i = 1; i <= SIZE; i++)
    for (i = 1; i <= SIZE; i++) {
      printf("%3d%3d", i, n[i]);
      for (j = 1; j <= n[i]; j++) printf("*");
      printf("\n");
    }
  return 0;
}
