#include <stdbool.h>
#include <stdio.h>

bool is_palindrome_num(unsigned int num) {
  unsigned int num_reverse = 0;
  for (unsigned int i = num; i != 0; i /= 10) {
    num_reverse = num_reverse * 10 + i % 10;
    printf("i=%d\n", i);
    printf("num_reverse=%d\n", num_reverse);
  }

  return (num == num_reverse);
}

bool is_palindrome_num2(unsigned int num) {
  unsigned int num_reverse = 0;
  for (unsigned int i = num; i != 0; i /= 10) {
    num_reverse = num_reverse * 10 + i % 10;
    printf("i=%d\n", i);
    printf("num=%d\n", num);
    printf("num_reverse=%d\n", num_reverse);
    printf("\n");
  }
  return (true);
}

int main(void) {
  printf("is_palindrome_num2(%d) = %d\n", 1441, is_palindrome_num2(1441));
  printf("is_palindrome_num2(%d) = %d\n", 522, is_palindrome_num2(522));
}
