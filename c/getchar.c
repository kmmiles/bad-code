#include <stdio.h>

#define MAX_PROMPTS 10

// read one char from stdin and flush the rest.
int read_char(void) {
  int ch = getchar();
  switch (ch) {
    case EOF:
    case '\n':
      ch = 0;
      break;
    default:
      for (int c = 0; c != EOF && c != '\n'; c = getchar()) {
        ;
      }
      break;
  }
  return ch;
}

int main(void) {
  int total = 0;
  int curr = 0;

  for (int i = 1; i <= MAX_PROMPTS; i++) {
    printf("dame una letra: ");
    curr = read_char();
    total += curr;
    printf("[%d of %d] current = %d (%c), total = %d\n", i, MAX_PROMPTS, curr,
           curr, total);
  }
}
