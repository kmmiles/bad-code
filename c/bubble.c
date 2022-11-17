#include <stdio.h>
#include <stdlib.h>

double array[8] = {4.1, 2.6, 1.4, 9.4, 2.1, 9.2, 6.0, 3.8};
int size = 8;

int main() {
  double sortedarray[size];
  for (int i = 0; i < 8; i++) sortedarray[i] = array[i];
  int repeatcheck = size;  // Numeric track of how many comparison sets are
                           // left.
  int offset = 0;  // This is used to determine which number the program is on.
  int offsetrestore = offset;  // This is used to 'restore' the offset operator;
                               // as it will change.
  // int loopcheck = 0;			//This is used to prevent logic loops.
  double alpha, beta;  // These are used to temporarily store values.
  double currentnumber = sortedarray[0];  // This is the number we'll compare:
  double nextnumber =
      sortedarray[1];  // and this is the number to be compared to.
  do {
    while (1) {
      if (currentnumber > nextnumber) {  // In the case that the numbers are
        alpha = currentnumber;           // to be swapped...
        beta = nextnumber;
        sortedarray[offset + 1] = alpha;
        sortedarray[offset] = beta;
        offset++;
        nextnumber = sortedarray[offset + 1];
      } else {  // Otherwise...
        sortedarray[offset] = currentnumber;
        offsetrestore++;
        offset = offsetrestore;
        break;
      }
    }
    currentnumber = sortedarray[offset];
    nextnumber = sortedarray[offset + 1];
    repeatcheck--;
  } while (repeatcheck >
           0);  // This loop is done as to recursively sort all integers.

  for (int i = 0; i < 8; i++)
    printf("\nEntry %d:	%lf", i, sortedarray[i]);
  return 0;
}
