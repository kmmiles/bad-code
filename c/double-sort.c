#include <stdio.h>
#include <stdlib.h>

int compar(const void* elem1, const void* elem2) {
  if (*(const double*)elem1 < *(const double*)elem2) return -1;
  return *(const double*)elem1 > *(const double*)elem2;
}

int main() {
  double array[] = {4.1, 2.6, 1.4, 9.4, 2.1, 9.2, 6.0, 3.8};
  const int array_size = sizeof(array) / sizeof(array[0]);

  qsort(array, array_size, sizeof(double), compar);

  for (int i = 0; i < array_size; i++) printf("%f\n", array[i]);

  return 0;
}
