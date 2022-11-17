#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool file_exists(const char* filepath) {
  struct stat st_target;
  if (stat(filepath, &st_target) == -1) {
    fprintf(stderr, "%s: %s\n", filepath, strerror(errno));
    return false;
  }
  return true;
}

int main(int argc, char** argv) {
  if (!argv[1]) {
    fprintf(stderr, "Usage: %s <file1>\n", argv[0]);
    exit(1);
  }

  printf("file_exists(%s) = %d\n", argv[1], file_exists(argv[1]));
}
