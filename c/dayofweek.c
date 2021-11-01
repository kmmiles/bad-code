#include <stdio.h>

int main(void) {
  int choice = 0;

  printf("insert a number from 1 to 7: ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Monday\n");
  } else if (choice == 2) {
    printf("Tuesday\n");
  } else if (choice == 3) {
    printf("Wednesday\n");
  } else if (choice == 4) {
    printf("Thursday\n");
  } else if (choice == 5) {
    printf("Friday\n");
  } else if (choice == 6) {
    printf("Saturday\n");
  } else if (choice == 7) {
    printf("Sunday\n");
  } else {
    printf("Invalid\n");
  }
}
