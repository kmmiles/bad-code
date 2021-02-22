#define _POSIX_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

int main(void) {
  int num_fork = 0;
  pid_t pid;

  while (1) {
    pid = fork();
    if (pid == -1) {
        // error
        fprintf(stderr, "fork: %s\n", strerror(errno));
        printf("total processes: %d\n", num_fork);
        kill(0, SIGHUP);
        exit(1); 
    } else if (pid == 0) {
        // child
        num_fork++;
    } else {
        // parent
        wait(NULL);
    }
  }
}
