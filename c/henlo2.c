#include <stdio.h>

int main() {
  char input[30];
  char output[30];
  printf("Enter a text:\n");
  fgets(input, 30, stdin);

  printf("input: <%s>\n", input);

  // int i = 0;

  /*while(input[i] != '\0') {
      printf("Printing");
      i++;
  }*/

  for (int i = 0; input[i] != '\0'; i++) {
    output[i] = input[i];
    printf("[%d] [%c] %s\n", i, input[i], output);
  }
}
