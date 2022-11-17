#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char x[1024] = {0};

  char* filename = "./stat.c";
  FILE* f = fopen(filename, "r");
#if 0
    while (fscanf(f, "%s\n", x) == 1) {
        //printf("%d\n", strlen(x));
        printf("%s\n", x);
    }
#else
  while (fgets(x, 1024, f) != NULL) {
    printf("%s", x);
  }
#endif
}
