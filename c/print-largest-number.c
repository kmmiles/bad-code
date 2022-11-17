#include <stdio.h>

#define NUMBER_COUNT 3

int main() {
  int num_array[NUMBER_COUNT - 1], largest_idx = 0;

  for (int i = 0; i < NUMBER_COUNT; ++i) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &num_array[i]);
    if (num_array[i] > num_array[largest_idx]) {
      largest_idx = i;
    }
  }

  printf("%d is the largest number.\n", num_array[largest_idx]);
}
