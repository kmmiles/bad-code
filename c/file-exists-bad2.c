#include <stdio.h>

int main(int argc, char **argv) {
  FILE *file = NULL;

  if (file = fopen(argv[0], "r")) {
    printf("file doesn't exist\n");
    fclose(file);
  } 
}
