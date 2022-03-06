#include <stdio.h>

void change_num(int *num) { *num = 420; }

int main(void) {
  int mynum = 0;

  printf("mynum: %d\n", mynum);
  change_num(&mynum);
  printf("mynum: %d\n", mynum);
}
