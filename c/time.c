#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a function that measures how long a system command takes to execute
// it will return the time in milliseconds
double measure(char *command) {
  clock_t start, end;
  double time_taken;
  start = clock();
  system(command);
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  return time_taken * 1000;
}

// a function that will format the time in milliseconds into a format of
// MM:SS:MS
void format(long time) {
  long minutes = time / 60000;
  long seconds = (time % 60000) / 1000;
  long milliseconds = (time % 1000);
  printf("%ld:%ld:%ld\n", minutes, seconds, milliseconds);
}

int main() {
  // measure the time it takes to execute the file
  double time = measure("sleep 2");

  printf("time: %f\n", time);
  // format the time into a format of MM:SS:MS
  format(time);
  return 0;
}
