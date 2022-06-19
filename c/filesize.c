#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

long fsize_ftell(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    return (-1);
  }

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  if (!fsize) {
    return (-1);
  }
  fseek(fp, 0, SEEK_SET);
  fclose(fp);
  return (fsize);
}

ssize_t fsize(const char *filename) {
  ssize_t nread = 0;
  ssize_t nread_total = 0;
  char buf[4096] = {0};

  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    return -1;
  }

  while (nread = read(fd, buf, sizeof(buf)), nread > 0) {
    nread_total += nread;
  }

  close(fd);
  return nread_total;
}

int main(int argc, char *argv[]) {
  printf("size (read): %li\n", fsize(argv[1]));
  printf("size (ftell): %li\n", fsize_ftell(argv[1]));
}
