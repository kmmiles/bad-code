#include <stdio.h>

int main(void) {
  int num = 0;
  int i = 0;

  printf("Enter a number: ");
  scanf("%d", &num);

  i = num;

  do {
    printf("%d ", i);
    if(num > 0) {
      //printf("num (%d) is greater than 0, decrement\n", num);
      i--;
    } else {
      //printf("num (%d) is not greater than 0, increment\n", num);
      i++;
    }

  } while (i != 0);


}
