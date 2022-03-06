#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  char buffer[50];

  int fd = open("Hello.txt", O_RDONLY);
  ssize_t n = read(0, buffer, 10);

  fprintf(stderr, "fd=%d\nn=%lu\n", fd, n);
  return 0;
}
