#include <stdio.h>

#define MIN_BOLT_SIZE 1.90
#define MAX_BOLT_SIZE 2.10

int main() {
  int count, boltAmount;
  float boltSize;
  printf("How many bolts are to be inspected: ");
  scanf(" %d", &boltAmount);
  count = 0;
  while (count < boltAmount) {
    printf("Plese enter the size of the bolt in inches: ");
    scanf(" %2f", &boltSize);
    if (boltSize >= MIN_BOLT_SIZE && boltSize <= MAX_BOLT_SIZE) {
      printf("The bolt size %.2f inches is ACCEPTED\n", boltSize);
    } else {
      printf("The bolt size %.2f is REJECTED\n", boltSize);
    }
    count++;
  }
  // getc();
  return 0;
}
