#include <stdio.h>

#define NUMBER_COUNT 3

int main() {
  int r[NUMBER_COUNT - 1], minindex = 0, maxindex = 0;

  printf("Enter 10 real numbers:\n");
  for (int i = 0; i < NUMBER_COUNT; ++i) {
    scanf("%d", &r[i]);
    if (r[i] < r[minindex]) {
      minindex = i;
    } else if (r[i] > r[maxindex]) {
      maxindex = i;
    }
  }

  printf("minimum: r[%d] = %d\n", minindex, r[minindex]);
  printf("maximum: r[%d] = %d\n", maxindex, r[maxindex]);
}
