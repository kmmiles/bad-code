#include <stdio.h>
#include <string.h>

typedef struct {
  int a;
  int b;
} example_t;

void init_example(example_t *example) {
  if (example) {
    memset(example, 0, sizeof(example_t));
    example->a = 1;
    example->b = 2;
  }
}

void do_thing(void *data) {
  /* access by typecasting */
  ((example_t *)data)->a = 10;

  /* OR bettter access by assigning to a new variable */
  example_t *example = data;
  example->a = 10;
}

int main(void) {
  example_t example;

  init_example(&example);
  do_thing(&example);
  printf("example.a: %d\n", example.a);
  printf("example.b: %d\n", example.b);
}
