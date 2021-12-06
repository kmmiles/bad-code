#include <stdio.h>

int main(void) {
  int n = 10;
  int iterations = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        iterations++;
      }
    }
  }

  printf("Iterations: %d\n", iterations);
}
