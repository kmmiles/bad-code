#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gets(char *s);

int main() {
  int i = 0;
  char t[80], q[2];

  char s[80];
  char r[] = "";

  printf("sizeof r: %lu\n", sizeof(r));
  printf("sizeof s: %lu\n", sizeof(s));
  // printf("sizeof r: %lu\n", sizeof(r));
  strcat(r, "hello");
  printf("r: %s\n", r);
  exit(1);

  // printf("**Press Enter to Start** ");
  // do
  // {
  int start = -1;
  // gets(j);
  printf("Enter string: ");
  gets(s);
  printf("Enter sub-string: ");
  gets(t);
  i = 0;
  while (s[i]) {
    if (s[i] == t[0]) {
      start = i;
      while ((s[i] != ' ') && (s[i]) != '\0') {
        printf("s[%d]=%c t[0]=%c\n", i, s[i], t[0]);
        q[0] = s[i];
        strcat(r, q);
        printf("  q=%s,r=%s\n", q, r);
        i++;
      }
      puts(r);
      puts(t);
      if (strcmp(r, t) == 0) {
        printf("%d", start);
        break;
      }
    }

    i++;
  }
  //     printf("\nPress 1 to continue: ");
  //     scanf("%d",&y);
  // } while (y=1);
  return 0;
}
