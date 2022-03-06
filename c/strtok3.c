#include <stdio.h>
#include <string.h>

int main() {
  const char *delim = ",";
  char str[] = "mary,had,a,little,lamb";

  for (char *t = strtok(str, delim); t != NULL; t = strtok(NULL, delim)) {
    printf("t: \"%s\"\n", t);
  }

  return (0);
}
