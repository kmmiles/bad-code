/*
Make a C program that allows one person to input three numbers, and
then allows another person to input another set of three numbers, and
the program determines if each person inputted all three numbers that
the other person inputted (in any sequence). After inputting all
numbers, there should be only one output and if the program gives an
incorrect output even once this can get a failing grade for this
exercise.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PLAYER_COUNT 3
#define NUM_COUNT 3
typedef int Players[PLAYER_COUNT][NUM_COUNT];

void sort_int_array(int *nums, size_t size) {
  for (int i = 0; i < size; i++) {
    for (int x = i + 1; x < size; x++) {
      /* swap i and x */
      if (nums[i] > nums[x]) {
        int temp = nums[i];
        nums[i] = nums[x];
        nums[x] = temp;
      }
    }
  }
}

void print_int_array(int *nums, size_t size) {
  for(int i=0; i < size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

int prompt_for_int(int num) {
  int x = 0;
  printf("Enter number %d: ", num);
  scanf("%d", &x);
  return x;
}

int main() {
  Players players = {0};

  /* get player input */
  for (int i = 0; i < PLAYER_COUNT; i++) {
    printf("Player %d please input the numbers below\n", i + 1);
    for (int j = 0; j < NUM_COUNT; j++) {
      players[i][j] = prompt_for_int(j + 1);
    }
  }

  /* for each player, sort input and compare to previous */
  for (int i = 0; i < PLAYER_COUNT; i++) {
    sort_int_array(players[i], NUM_COUNT);

    /* skip the first player */
    if (i == 0) {
      continue;
    }

    for (int j = 0; j < NUM_COUNT; j++) {
      if (players[i - 1][j] != players[i][j]) {
        printf("They are not the same! (player %d and %d do not match)\n", i, i + 1);
        return (EXIT_FAILURE);
      }
    }
  }

  printf("They are the same!\n");
  return (EXIT_SUCCESS);
}
