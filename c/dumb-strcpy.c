#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELLO "HELLO"

void fillString(char *str, size_t size) {
  if (str && size) {
    strncpy(str, "Hello, world", size - 1);
  }
}

void copyString(char *str) {
  char *tmp = malloc(100);
  strcat(tmp, "HELLO");
  strcpy(str, tmp);
  free(tmp);
}

char *getHello(void) { return strdup("Hello, world"); }

int main() {
  printf("%s\n", HELLO);
  exit(0);

  /*
  char *hello = getHello();
  printf("%s\n", hello);
  free(hello);
  */

  char string[10] = {0};
  fillString(string, sizeof(string));
  printf("%s\n", string);

  /*
  char *result = strdup("");
  copyString(result);
  printf("%s\n", result);
  */
}
