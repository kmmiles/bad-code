#include <stdio.h>
#include <string.h>

int main(void) {
  struct _data {
    char first[255];
    char last[255];
  };

  struct _data data;

  strcpy(data.first, "hello");
  strcpy(data.last, "world");

  FILE *fp = fopen("struct.txt", "w");
  fwrite(&data, sizeof(data), 1, fp);
  fclose(fp);
}
