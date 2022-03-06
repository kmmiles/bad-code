#include <stdio.h>

int main() {
  char input[12];
  printf("Enter a text:\n");
  fgets(input, 12, stdin);

  int length = 0;

  while (input[length] != '\0') {
    length++;
  }

  int space_idx = 0;
  for (int j = 0; j <= length; j++) {
    if (input[j] == ' ') {
      space_idx = j;
      continue;
    }

    for (int i = 0; i < j; i++) {
      printf("%c", input[i]);
    }

    printf("\n");
  }
  printf("\n");
}
