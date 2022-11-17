#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid;

  if (argc < 3) {  // Check if arguments equal to 1.
    printf("USAGE:\n  parta <WORD> <FILE>\n");
    exit(1);
  }

  pid = fork();
  if (pid == -1) {
    // if child process = -1 then there's error, can't fork.
    exit(1);
  } else if (pid == 0) {
    int grep_ret = execv("/bin/grep", argv);
    printf("grep returned %d: %s\n", grep_ret, strerror(errno));
    if (grep_ret == -1) {
      printf("%s + not found.\n", argv[1]);
      exit(1);
    } else if (grep_ret == 0) {
      printf("%s + found.\n", argv[1]);
      exit(0);
    }
  } else {
    exit(0);
  }
  return 1;
}
