#include <stdio.h>
#include <string.h>

char *inputs[] = {"command 1:x", "command 2:y", "unknown 1:x", "exit"};

int main(int argc, char **argv) {
  int i = 0, ret;
  char str[81];
  while (strcmp(inputs[i], "exit") != 0) {
    ret = sscanf(inputs[i], "command %s", str);
    printf("ret=%d\torig='%s'\tstr='%s'\n", ret, inputs[i],
           ret == 1 ? str : "Invalid");
    i++;
  }
  return 0;
}
