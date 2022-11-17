#include <stdio.h>

void SmallerOf(double *a, double *b) {
  if (!a || !b || *a == *b) {
    return;
  } else if (*a < *b) {
    *b = *a;
  } else if (*a > *b) {
    *a = *b;
  }
}

int main(void) {
  double a = 3;
  double b = 2;

  SmallerOf(&a, &b);

  printf("a = %f, b = %f\n", a, b);
}
