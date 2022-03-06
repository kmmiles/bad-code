#include <stdio.h>
#include <unistd.h>

int main() {
  char *line = NULL;
  size_t size;

  if (!isatty(fileno(stdin))) {
    printf("we've got input on stdin, read it\n");
    while (getline(&line, &size, stdin) != -1) {
      printf("%s", line);
    }
  } else {
    printf("no stdin, do the REPL thing\n");
  }

  return 0;
}
