#include <stdio.h>

#if 0
int main(void)
{
  return(0);
}
#else
#include <stdio.h>
int main() {
  char G;
  int Time;
  int wage;
  printf("Enter your gender (M/F): \n");
  scanf("%c", &G);
  printf("Enter the time you worked for (in hrs): \n");
  scanf("%d", &Time);
  switch (G == 'M') {
    case 1:
      if (Time < 6) {
        wage = 50 * Time;
      } else if (Time <= 10) {
        wage = 50 * 6 + 80 * (Time - 6);
      } else if (Time > 10) {
        wage = 50 * 6 + 80 * 4 + 150 * (Time - 10);
      }
      break;
    case 0:
      if (Time < 6) {
        wage = 40 * Time;
      } else if (Time <= 10) {
        wage = 40 * 6 + 60 * (Time - 6);
      } else if (Time > 10) {
        wage = 40 * 6 + 60 * 4 + 150 * (Time - 10);
      }
      break;
  }
  printf("Your wages are %d", wage);
}
#endif
