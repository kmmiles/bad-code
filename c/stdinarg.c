#include <stdio.h>

int main() {
  char *line = NULL;
  size_t size;

  while (getline(&line, &size, stdin) != -1) {
    printf("%s", line);
  }
  return 0;
}
