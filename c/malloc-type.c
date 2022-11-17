#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* String;

int main(void) {
  String s1 = ((char*)malloc(10), 0, 10);
  // String s1 = malloc(10);
  strcpy(s1, "hello");
  printf("%s\n", s1);
  free(s1);
}
