#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // int count=0;
  char s[20];

  printf("Please enter a string\n");
  scanf("%s", &s);

  printf("the number of letters is: %d \n", strlen(s));

  int count[26] = {0};
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      count[s[i] - 'A']++;
    }
  }
  // printf("the number of upppercase letters is: %d \n", count);

  for (int i = 0; i < 26; i++) {
    printf("count[%d] = %d\n", i, count[i]);
  }

  return 0;
}
