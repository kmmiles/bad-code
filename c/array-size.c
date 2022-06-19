#include <stdio.h>

void method1(int arr[], size_t arr_sz) {
  for (int i = 0; i < arr_sz; i++) {
    printf("method1: arr[%d] = %d\n", i, arr[i]);
  }
}

void method2(int arr[], size_t arr_sz) {
  for (int i = 0; i < arr_sz; i++) {
    printf("method2: arr[%d] = %d\n", i, arr[i]);
  }
}

void method3(void) {
  int numbers[] = {55, 3, 434, 22, 55, 22};
  size_t numbers_sz = sizeof(numbers) / sizeof(int);

  method1(numbers, numbers_sz);
  method2(numbers, numbers_sz);
}

int main(void) { method3(); }
