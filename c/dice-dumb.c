#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_even(int dice);
int total_even(unsigned int dices[6]);
int even;
int total;

int main() {
  int dice;
  unsigned int dices[6] = {};
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    dice = 1 + rand() % 6;
    even = count_even(dice);
    switch (dice) {
      case 1:
        dices[0]++;
        break;
      case 2:
        dices[1]++;
        break;
      case 3:
        dices[2]++;
        break;
      case 4:
        dices[3]++;
        break;
      case 5:
        dices[4]++;
        break;
      case 6:
        dices[5]++;
        break;
      default:
        break;
    }
    total = total_even(dices);
    printf("Dice Roll %d = %d\n", i + 1, dice);
  }
  printf("Number\tFrequency\n");
  printf("1\t\t%u\n", dices[0]);
  printf("2\t\t%u\n", dices[1]);
  printf("3\t\t%u\n", dices[2]);
  printf("4\t\t%u\n", dices[3]);
  printf("5\t\t%u\n", dices[4]);
  printf("6\t\t%u\n", dices[5]);
  printf("\nTotal times of even number rolled = %d", even);
  printf("\nTotal number of even number rolled = %d", total);
}

int count_even(int dice) {
  static int n = 0;
  if (dice % 2 == 0) {
    n++;
  }
  return n;
}

int total_even(unsigned int dices[6]) {
  int m = 0;
  for (int i = 0; i < 6; i++) {
    if ((i + 1) % 2 == 0) {
      if (dices[i] != 0) {
        m++;
      }
    }
  }
  return m;
}
