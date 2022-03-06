#include <stdio.h>

void switchNum(int *a, int *b) {
  int temp;

  printf("switchNum(a=%p, b=%p)\n", a, b);
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a = 5;
  int b = 2;

  printf("before swap\ta=%d\tb=%d\n", a, b);
  switchNum(&a, &b);
  printf("after swap\ta=%d\tb=%d\n", a, b);
}
