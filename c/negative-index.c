#include <stdio.h>
#include <stdlib.h>

#define NMEMB 1024

int main(void) {
  char *buffer = calloc(NMEMB, sizeof(char));
  char *b_end = &buffer[NMEMB];
  for (int i = 0; i >= -1024; i--) b_end[i] = 'y'; /* whee */
  printf("%s\n", buffer);
}
