#include <linux/magic.h>
#include <stdio.h>
#include <sys/statfs.h>

int is_procfs(const char *filename) {
  struct statfs buf;
  if (statfs(filename, &buf) == -1) {
    return (-1);
  }
  // fprintf(stderr, "%li\n", buf.f_type);
  return (buf.f_type == PROC_SUPER_MAGIC);
}

int main(int argc, char *argv[]) {
  printf("is_procfs(%s) == %d\n", argv[1], is_procfs(argv[1]));
}
