#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int64_t millis() {
  struct timespec now;
  timespec_get(&now, TIME_UTC);
  return ((int64_t)now.tv_sec) * 1000 + ((int64_t)now.tv_nsec) / 1000000;
}

int64_t measure_cmd(const char *cmd) {
  int64_t start = millis();
  system(cmd);
  int64_t end = millis();
  return (end - start);
}

int main(void) {
  const char *cmd = "sleep 2";

  int64_t time = measure_cmd(cmd);
  printf("execution time of \"%s\": %ld ms\n", cmd, time);
}
