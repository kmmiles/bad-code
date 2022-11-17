#include <stdio.h>

void f(int *x) {
  if(x) {
    *x += 5;
  }
}

int main(void) {
  int x = 5;
  f(&x);
  printf("%d\n",x);
}
