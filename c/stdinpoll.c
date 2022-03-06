#include <stdio.h>
#include <sys/poll.h>

int main(void) {
  struct pollfd fds;
  fds.fd = 0;
  fds.events = POLLIN;

  if (poll(&fds, 1, 0)) {
    printf("we've got input on stdin, read it\n");
  } else {
    printf("no stdin, do the REPL thing\n");
  }
  return 0;
}
