#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char string[] = "256 Hello World";
  long partInt;
  char* partStr;

  partInt = strtol(string,&partStr,10);

  printf("partStr = \"%s\"\n", partStr);


  if (strcmp(partStr,"Hello World")==0) {
    printf("Hello world!\n");
  } else {
    printf("Not equal.\n");
  }
  return 0;
}
