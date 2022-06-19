#include <stdio.h>
#include <strings.h>

int main(void) {
  char *string = "command 1: write";
  printf("<%s>\n", index(string, ' ') + 1);
}
