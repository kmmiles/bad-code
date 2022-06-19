#include <math.h>
#include <stdio.h>
#include <string.h>

void countOccurrence(char s[], char c, int *numOccu) {
  for (int i = 0; i <= strlen(s); i++) {
    if (s[i] == c) {
      (*numOccu)++;
    }
  }
}

int main(void) {
  char str[100], c;
  int numOccu = 0;

  printf("Enter a string(ex:catttt bot) : ");
  scanf("%s", str);
  getc(stdin);

  printf("\n\nEnter an character (ex:t): ");
  scanf("%c", &c);
  getc(stdin);

  countOccurrence(str, c, &numOccu);

  printf("\nThe total number of the characters is %d\n", numOccu);
}
