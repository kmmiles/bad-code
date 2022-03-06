#include <stdio.h>
#include <time.h>

int main() {
  int seconds = 0;
  unsigned int myTime;

  while (1) {
    myTime = time(0) + 1;
    while (time(0) < myTime)
      ;
    printf("%d", seconds);
    fflush(stdout);
    seconds++;
  }

  return 0;
}
