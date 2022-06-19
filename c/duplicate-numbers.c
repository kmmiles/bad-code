#include <stdio.h>
#include <string.h>
#define SIZE 30

int main() {
  int a, b;
  char inBuf[SIZE];

  // Input
  printf("Enter the lower bound A [1-5000]");
  fgets(inBuf, SIZE, stdin);
  sscanf(inBuf, "%d", &a);
  if (a < 1 || a > 5000)
    printf("Input Error! Be sure to input a number between 1-5000");
  printf("Enter the upper bound B [1-5000]");
  fgets(inBuf, SIZE, stdin);
  sscanf(inBuf, "%d", &b);
  if (a > b)
    printf("Input Error! Be sure A <= B");
  else if (b < 1 || b > 5000)
    printf("Input Error! Be sure to input a number between 1-5000");

  // Check for duplicate
  char duplicateCheck[SIZE] = {0};
  int count;
  int n = 0;                    // Counter for possible numbers
  for (int i = a; i <= b; i++)  // Loops through a-b range
  {
    count = 0;
    sprintf(duplicateCheck, "%d", i);  // Converts
    // Change int i to string in order to run duplicate check on i
    for (int j = 0; j < strlen(duplicateCheck);
         j++)  // loops through the string version i
    {
      count = 1;  // Count for duplicates
      for (int k = j + 1; k < strlen(duplicateCheck);
           k++)  // Loop to check if there is duplicate char in string
      {
        if (duplicateCheck[j] ==
            duplicateCheck[k])  // If there is a matching char
        {
          count++;
          duplicateCheck[k] = 0;  // Change to zero so it's already checked
        }
      }
      if (count > 1 &&
          duplicateCheck[j] !=
              0)  // If the count is greater than one then there is a duplicate
        n--;
    }
    n++;  // Must be part of outer for loop
    printf("%s\n", duplicateCheck);
  }
  printf("\nThe amount of possible numbers are ");
  printf("%i", n);
  return 0;
}
