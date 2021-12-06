#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct block {
  bool gym;
  bool school;
  bool store;
} block_t;

int min_dist_block(block_t *blocks, size_t size) {
  int max_dist = size - 1;
  int min_dist = max_dist;

  for (int i = 0; i <= size - 1; i++) {
    printf("[%d].gym = %d\n", i, blocks[i].gym);
    printf("[%d].school = %d\n", i, blocks[i].school);
    printf("[%d].store = %d\n", i, blocks[i].store);
  }

  return (-1);
}

int main(void) {
  block_t blocks[5];

  /*
    0 [0,1,0] = 4 - 0,1,0 - 1,1,1
    1 [1,0,0] = 3 - 1,1,0 - 1,1,1
    2 [1,1,0] = 2 - 1,1,0 - 1,1,1*
    3 [0,1,0] = 1 - 1,1,0 - 0,1,1
    4 [0,1,1] = 2 - 1,1,1* - 0,1,1
  */

  blocks[0].gym = false;
  blocks[0].school = true;
  blocks[0].store = false;

  blocks[1].gym = true;
  blocks[1].school = false;
  blocks[1].store = false;

  blocks[2].gym = true;
  blocks[2].school = true;
  blocks[2].store = false;

  blocks[3].gym = false;
  blocks[3].school = true;
  blocks[3].store = false;

  blocks[4].gym = false;
  blocks[4].school = true;
  blocks[4].store = true;

  int m = min_dist_block(blocks, 5);
  printf("Minimum distance is block %d\n", m);
}
