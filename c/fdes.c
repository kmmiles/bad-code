#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <unistd.h>

int main(void) {
  fprintf(stderr, "stdout: %d\n", fileno(stdout));
  fprintf(stderr, "isatty: %d\n", isatty(fileno(stdout)));
}
