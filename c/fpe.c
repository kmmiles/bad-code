#include <stdio.h>

int main(void) {
  int number;
  int i;
  int j;

  do {
    printf("enter a number: ");
    scanf("%d", &number);
  } while (number <= 0);

  for (i = 1; i <= number; i++) {
    printf("divisors of %d = ", i);
    for (j = 1; j <= i; j++) {
      if (i % j == 0) {
        printf("%d%s", j, (i > j ? " " : ""));
      }
    }
    printf("\n");
  }
  return 0;
}
