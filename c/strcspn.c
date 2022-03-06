#include <stdio.h>
#include <string.h>

int main(void) {
  char foo[] = "name";
  // foo[strcspn(foo, "\n")] = 0;

  size_t len = strcspn(foo, "\n");
  printf("len: %lu\n", len);

  //  printf("foo: \"%s\"\n", foo);
  // printf("%lu", strcspn(foo, "\n\n"));
}
