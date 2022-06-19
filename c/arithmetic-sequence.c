#include <stdio.h>

int in_sequence(int num, int start, int end, int common_diff) {
  for (int i = 1; i <= end; i++) {
    if (num == start * 1 + (i - 1) * common_diff) {
      return (1);
    }
  }
  return (0);
}

int main(void) {
  int nTile = 0;

  printf("Enter a tile: ");
  scanf("%d", &nTile);

  if (in_sequence(nTile, 1, 24, 5)) {
    // 1,6,11,16,21
    printf("H\n");
  } else if (in_sequence(nTile, 2, 24, 5)) {
    // 2,7,12,17,22
    printf("D\n");
  } else if (in_sequence(nTile, 3, 24, 5)) {
    // 3,8,13,18,23
    printf("C\n");
  } else if (in_sequence(nTile, 4, 24, 5)) {
    // 4,9,14,19,24
    printf("S\n");
  } else if (nTile % 5 == 0) {
    printf("H\n");
  } else {
    printf("?\n");
  }
}
