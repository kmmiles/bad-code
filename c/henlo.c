#include <stdio.h>

void print_chars(char *s) {
  int space_idx = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ') {
      space_idx = i;
      continue;
    }

    printf("%.*s\n", space_idx ? i - space_idx : i + 1,
           space_idx ? s + space_idx + 1 : s);
  }
}

/*
void print_chars_basic(char *s) {
  for(int i = 0; s[i] != '\0'; i++) {
    printf("%.*s\n", i+1, s);
  }
}
*/

int main(void) {
  char *string = "Hello World Again";

  print_chars(string);
}
