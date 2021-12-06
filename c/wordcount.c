#include <stdio.h>
#include <string.h>

int main(void) {  // Ask for  user's input
  char *text = "hello world this is a program.";
  printf("%s\n", text);

  int n = strlen(text);

  // Count and print the number of letters in the text
  int letters = 0;
  for (int i = 0; i < n; i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      letters = letters + 1;
    } else {
      if (text[i] >= 'A' && text[i] <= 'Z') {
        letters = letters + 1;
      }
    }
  }
  printf("%i letter(s)\n", letters);

  // TODO: Count and print the number of words in the text
  int words = 0;
  for (int i = 0; i < n; i++) {
    if (text[i] == ' ') {
      printf("hello space\n");
      if (text[i + 1] >= 'a' && text[i + 1] <= 'z') {
        words = words + 1;
      } else if (text[i + 1] >= 'A' && text[i + 1] <= 'Z') {
        words = words + 1;
      }
    }
  }
  printf("%i word(s)\n", words);
}
