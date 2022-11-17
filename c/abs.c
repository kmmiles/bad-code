#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int tempDifference = 1;
  int smallestDifference = 26;
  int total = 0;
  char S[100] = {0};
  char F[100] = {0};

  strcpy(S, "hello");
  strcpy(F, "world");

  for (int i = 0; S[i] != '\0'; i++) {
    for (int j = 0; F[j] != '\0'; j++) {
      const char s = S[i];
      const char f = F[j];

      if ((abs(f - s) < (abs(s - f)))) {
        if (abs(f - s) > 13) {
          tempDifference = 26 - abs(f - s);
        } else if (abs(f - s) < 13) {
          tempDifference = abs(f - s);
        }
      } else if ((abs(s - f) < (abs(f - s)))) {
        if (abs(s - f) > 13) {
          tempDifference = 26 - abs(s - f);
        } else if (abs(s - f) < 13) {
          tempDifference = abs(s - f);
        }
      } else {
        tempDifference = f - s;
      }
      // executes if it's a smaller difference
      if (tempDifference < smallestDifference) {
        smallestDifference = tempDifference;
      }
    }
    total += smallestDifference;  // add to total difference
    smallestDifference = 26;      // set value back
  }

  printf("total: %d\n", total);
}
