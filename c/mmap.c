#include <fcntl.h>
#include <stdio.h>
#include <sys/io.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  unsigned char *f;
  int size;
  struct stat s;
  const char *filename = argv[1];
  int fd = open(filename, O_RDONLY);

  fstat(fd, &s);
  size = s.st_size;
  f = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
  for (int i = 0; i < size; i++) {
    putchar(f[i]);
  }

  return 0;
}
