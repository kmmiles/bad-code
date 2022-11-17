#include <stdbool.h>
#include <stdio.h>

void tryit(void) {
  static bool doit = true;

  if (doit) {
    printf("hello, world\n");
    doit = false;
  }
}

int main(void) {
  tryit();
  tryit();
  tryit();
}
