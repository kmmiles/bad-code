#include <stdio.h>

int main(void) {
  int nTile = 0;

  printf("Enter a tile: ");
  scanf("%d", &nTile);

  if (nTile == 5 * nTile - 4) {
    // 1,6,11,16,21
    printf("H\n");
    printf("val: %d\n", 5 * nTile - 4);
  } else if (nTile == 5 * nTile - 3) {
    // 2,7,12,17,22
    printf("D\n");
  } else if (nTile == 5 * nTile - 2) {
    printf("C\n");
  } else if (nTile == 5 * nTile - 1) {
    // 4,9,14,19,24
    printf("S\n");
    printf("val: %d\n", 5 * nTile - 4);
  } else if (nTile == 5 * nTile) {
    printf("H\n");
  } else if (nTile <= 0 || nTile >= 26) {
    printf("?\n");
  } else {
    printf("nTile: '%d'\n", nTile);
    printf("val: %d\n", 5 * nTile - 4);
  }
}
