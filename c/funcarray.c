#include <stdio.h>

typedef struct {
  float x, y;
} v2;

void testit(v2 simplex[3]) {
  for (size_t i = 0; i < 3; i++) {
    printf("simplex[%lu].x = %f\n", i, simplex[i].x);
  }
}

int main(void) {
  v2 simplex[3];
  simplex[0].x = 1.0;
  simplex[0].y = 2.0;
  simplex[1].x = 3.0;
  simplex[1].y = 4.0;
  simplex[2].x = 5.0;
  simplex[2].y = 6.0;
  testit(simplex);
}
