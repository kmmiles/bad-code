#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
  struct passwd *root;
  struct passwd *me;

  root = getpwuid(0);
  me = getpwuid(1000);

  printf("root=%s, me=%s\n", root->pw_name, me->pw_name);

  /*
  printf("%s %s\n",
      getpwuid(1000)->pw_name,
      getpwuid(0)->pw_name);
      */
}
