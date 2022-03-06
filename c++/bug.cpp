#include <cstring>
#include <iostream>

int main(void) {
  int n = 3;
  int due_date[3][n];

  memset(due_date, 0, 3 * n * sizeof(int));
  due_date[0][0] = 0;
  due_date[0][1] = 1;
  due_date[0][2] = 2;
  due_date[0][3] = 3;

}
