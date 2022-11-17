#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(void) {
  char buf[SIZE + 1];

  FILE *fp = fopen("utf8.txt", "r");
  if (!fp) {
    perror("Failed to open");
    return (1);
  }

  while (fgets(buf, SIZE, fp)) {
    char *x = strstr(buf, "∮ E⋅da = Q,  n → ∞");
    if (x) {
      printf("I found cool formula: %s\n", x);
    }
    // printf("%s", buf);
  }

  fclose(fp);
  return (0);
}
