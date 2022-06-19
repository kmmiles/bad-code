#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *input = argv[1];
  size_t len = strlen(input);

  for (size_t i = 0; i < len - 1; i++) {
    int num = input[i] - '0';
    int next_num = input[i + 1] - '0';

    if (num == 1 && next_num == 3) {
      printf("holy shit it's an unlucky number!\n");
      break;
    }
  }
}
