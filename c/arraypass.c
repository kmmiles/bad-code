#include <stdio.h>

void myfunc(int *bar, int len) {
  for (int i = 0; i <= len; i++) {
    printf("i: %d\n", i);
  }

  *bar = 1;
}

int main(void) {
  int foo[] = {1, 2, 3, 4, 5, 6};
  myfunc(foo, sizeof(foo) / sizeof(int));
}
