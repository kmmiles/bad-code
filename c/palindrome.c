#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
bool is_palindrome(const char *word) {
  assert(word);

  size_t last = strlen(word);
  if (!last) {
    return(false);
  }
  last--;
  size_t last_half = last / 2;

  for (size_t i = 0; i <= last_half; i++) {
    if(word[i] != word[last-i]) {
      return(false);
    }
  }
  return(true);
}
*/

/*
bool is_palindrome(const char * word) {
  assert(word);

  for (char *i = (char*)word, *end = (char*)word + strlen(word) - 1; i++ <=
end--;) { if(*i != *end) { return(false);
    }
  }
  return true;
}
*/

bool is_palindrome(const char *word) {
  assert(word);
  char *i = (char *)word;
  char *end = i + strlen(word) - 1;
  for (; i <= end && *i == *end; i++, end--)
    ;
  return i > end;
}

int main(int argc, char *argv[]) {
  /*
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <word>\n", argv[0]);
    exit(1);
  }
  */

  if (is_palindrome(argv[1])) {
    printf("yes, palindrome\n");
  } else {
    printf("no, not a palindrome\n");
  }
}
