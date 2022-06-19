#include <stdio.h>

int main() {
  int integer1;
  int integer2;
  printf("öğrencinin ilk notunu giriniz \n");  // prompt
  scanf("%d", &integer1);                      // read integer
  if (integer1 > 100) {
    printf("geçerli bi not giriniz ");
  }

  printf("öğrencinin ikinici notunu giriniz\n");  // prompt
  scanf("%d", &integer2);                         // read
  if (integer2 > 100) {
    printf("geçerli bi not giriniz ");
  }

  int sum;  // variable in which sum will be stored
  sum = (((integer1 * 40) / 100) +
         ((integer2 * 60) / 100));  // assign total to sum

  if (sum <= 100) {
    printf("not ortalaması %d dir \n", sum);
  } else {
    printf("geçerli bi not giriniz");
  }
}
