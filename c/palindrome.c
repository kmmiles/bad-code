#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *word) {
  size_t len = strlen(word);
  for (size_t i = 0; i <= len-1; i++) {
    if(word[i] != word[len-i-1]) {
      return(false);
    }
  }
  return(true);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <word>\n", argv[0]);
    exit(1);
  }

  if(is_palindrome(argv[1])) {
    printf("yes, palindrome\n");
  } else {
    printf("no, not a palindrome\n");
  }
}