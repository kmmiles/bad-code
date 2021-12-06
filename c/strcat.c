#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strsep(char **stringp, const char *delim);

int main(void) {
  char *path = "/home/kmmiles/Code:/bad-code/c";
  char *file = "fuck";

  char *pathCopy = strdup(path);
  char *found;
  // while( (found = strsep(&pathCopy,":")) != NULL ) {
  while ((found = strsep(&pathCopy, ":") != NULL)) {
    char *pathname = malloc(100);
    memset(pathname, 0, 100);
    printf("found: %s\n", found);
    strcat(pathname, found);
    strcat(pathname, "/");
    strcat(pathname, file);
    printf("%s\n", pathname);
    free(pathname);
  }
}
