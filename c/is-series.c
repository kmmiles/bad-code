#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void is_series(int numbers[], int n);

int main() {
  int n = 5;
  int numbers[] = {1, 1, 2, 3, 5, 8};
  is_series(numbers, n);
}

void is_series(int numbers[], int n) {
  double sum = 0;
  for (int i = 1; i < n; i++) {
    if ((numbers[i] + numbers[i - 1]) == (numbers[i + 1]))
      printf("working\n");
    else
      printf("not a  series");
  }
  for (int j = 0; j < n; j++) {
    sum = sum + numbers[j];
  }
  printf("%lf\n", sum);
  double avg = sum / n;
  printf("%lf\n", avg);
}
