#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int a;
  int b;
} example_t;

example_t *example_init(void) {
  example_t *example = calloc(1, sizeof(example_t));
  if (example) {
    example->a = 1;
    example->b = 2;
  }
  return (example);
}

void example_destroy(example_t *example) {
  if (example) {
    free(example);
  }
}

int main(void) {
  example_t *example = example_init();
  if (example) {
    printf("a: %d\n", example->a);
    printf("b: %d\n", example->b);
    example_destroy(example);
  }
}
