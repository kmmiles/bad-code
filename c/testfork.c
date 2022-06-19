#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid;
  printf("firstapp\n");
  pid = fork();
  if (pid) {
    printf("parent process. sleeping..\n");
    sleep(10);
    printf("parent exiting\n");
  } else {
    printf("child process. sleeping..\n");
    sleep(20);
    printf("child exiting\n");
  }
}
