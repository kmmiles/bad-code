#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

int main(void) {
  char fileLocation[PATH_MAX] = {0};
  char *home = getenv("HOME");
  if(!home) {
    fprintf(stderr, "bad\n");
    exit(1);
  }

  snprintf(fileLocation, sizeof(fileLocation)-1, "%s/.shuck_history", home);
  printf("fileLocation: %s\n", fileLocation);
}
