#include <stdio.h>
#include <unistd.h>

int main(void) {
  long sz = sysconf(_SC_PAGESIZE);

  printf("PAGE_SIZE: %li\n", sz);
}
