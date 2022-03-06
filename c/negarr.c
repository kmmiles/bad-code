#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *buffer = calloc(1024, sizeof(int));
  int *b_end = &buffer[1024];
  for (int i = 0; i >= -1024; i--) b_end[i] = 'y'; /* whee */

  for (int i = 0; i <= 1024; i++) printf("%c ", b_end[i]);
}
