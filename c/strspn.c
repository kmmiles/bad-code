#include <stdio.h>
#include <string.h>

char *inputs[] = {"command 1:x", "command 2:y", "unknown 1:x", "exit"};

int main(void) {
  for (int i = 0; i < sizeof(inputs) / sizeof(char *); i++) {
    size_t idx = strspn(inputs[i], "command ");
    if (idx) {
      printf("<%s>\n", inputs[i] + idx);
    }
  }
}
