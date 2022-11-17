#include <stdio.h>

int main(void) {
  const char *str = "\nhello\nworld\n";
  if (str[0] == '\n') str += 1;
  printf("%s", str);
}
