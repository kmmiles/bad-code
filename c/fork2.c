#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t pid;
  int status = 0;

  pid = fork();
  if (pid == -1) {
    status = 2;
    return status;
  }
  if (pid == 0) {
    status = 3;
    execlp("true", "true", NULL);
    return 20;
  }
  (void)waitpid(pid, &status, 0);
  return WEXITSTATUS(status);
}
