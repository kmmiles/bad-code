#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* test for num with dup digits e.g. 122, 494, etc */
bool has_dup(int num) {
  char digit_count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char num_str[20] = {0};
  int num_str_len = 0;

  sprintf(num_str, "%d", num);
  num_str_len = strlen(num_str);

  for (int i = 0; i < num_str_len; i++) {
    if ('0' <= num_str[i] && num_str[i] <= '9') {
      if (++digit_count[num_str[i] - '0'] > 1) return true;
    }
  }
  return false;
}

int main(void) {
  for (int i = 0; i <= 100; i++) {
    if (!has_dup(i)) {
      printf("%d\n", i);
    }
  }
  // printf("has_dup(422): %d\n", has_dup(422));
  //  printf("has_dup(29): %d\n", has_dup(29));
}
