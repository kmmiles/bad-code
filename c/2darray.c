#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

int main(void) {
  // allocate board
  int **board = malloc(ROWS * sizeof(int *));
  for (int row = 0; row < ROWS; row++) {
    board[row] = malloc(COLS * (sizeof(int)));
  }

  // populate board
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = 3;
    }
  }

  // print board
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%d", board[row][col]);
    }
    printf("\n");
  }

  // free board
  for (int row = 0; row < ROWS; row++) {
    free(board[row]);
  }
  free(board);
}
