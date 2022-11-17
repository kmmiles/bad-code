#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int index;
  char bar[15];
} example_t;

int compare_chars(const void *a, const void *b) {
  return *(const char *)a - *(const char *)b;
}

int compare_ints(const void *a, const void *b) {
  return *(const int *)a > *(const int *)b;
}

int compare_examples(const void *a, const void *b) {
  const example_t *aa = a;
  const example_t *bb = b;
  return aa->index > bb->index;
}

int main(void) {
  /* sort array of chars */
  char chars_a[] = "hello";
  qsort(chars_a, strlen(chars_a), sizeof(char), compare_chars);
  printf("%s\n", chars_a);

  /* sort array of ints */
  int nums_a[] = {5, 1, 3};
  qsort(nums_a, sizeof(nums_a) / sizeof(nums_a[0]), sizeof(int), compare_ints);
  printf("%d,%d,%d\n", nums_a[0], nums_a[1], nums_a[2]);

  /* sort array of structs */
  example_t example_a[3];
  example_a[0].index = 5;
  example_a[1].index = 1;
  example_a[2].index = 3;
  qsort(example_a, 3, sizeof(example_t), compare_examples);
  printf("%d,%d,%d\n", example_a[0].index, example_a[1].index,
         example_a[2].index);
}
