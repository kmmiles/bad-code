#if 0
#include <stdio.h>

int main() {
    double xn = 4.1, h = .01;
    int xn100 = xn*100;

    for (int x = 400, i = 1; x < xn100; x += 1, i++) {
        printf("%2d x=%d xn=%lf x+h=%lf\n", i, x, xn, x + h);
    }
}
#else
#include <stdio.h>

int main() {
  double xn = 4.1, h = .01;
  int xn100 = xn * 100;
  int h100 = 1;
  int i = 1;

  for (int x = 400; x < xn100; x += h100) {
    printf("%2d x=%d xn=%lf x+h=%lf\n", i, x, xn, x + h);
    i++;
  }
}
#endif
