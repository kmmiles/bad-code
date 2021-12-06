#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fpr;
  char c;
  fpr = fopen("ascii.txt", "r");

  if (fpr == NULL) {
    puts("error while opening file");
    exit(1);
  }

  while ((c = fgetc(fpr)) != EOF) {
    printf("%c", c);
  }

  fclose(fpr);
  return 0;
}
