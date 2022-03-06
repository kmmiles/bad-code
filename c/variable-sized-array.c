#include <string.h>

int main(void) {
  int n = 3;
  int due_date[3][n];

  memset(due_date, 0, 3 * n * sizeof(int));
}
