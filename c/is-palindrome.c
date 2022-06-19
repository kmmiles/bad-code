/*
 * | K | A | Y | A | K | \0
 */

#include <stdio.h>
#include <string.h>

int is_palindrome(const char *string) {
  int string_len = strlen(string);      // 5
  int string_end_idx = string_len - 1;  // 4
  int string_half = string_len / 2;     // 2

  for (int i = 0; i <= string_half; i++) {
    if (string[i] != string[string_end_idx]) {
      return (0);
    }
  }
  return (1);
}

int main(int argc, char *argv[]) {
  if (is_palindrome(argv[1])) {
    printf("yes, palindrome\n");
  } else {
    printf("no, not a palindrome\n");
  }
}
