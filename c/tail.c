#include <stdio.h>
#include <stdlib.h>

char *fgets_backwards(char *str, int size, FILE *fp) {
  if (ftell(fp) == 0) {
    return NULL;
  }

  int i;
  for (i = 0; ftell(fp) != 0 && i < size; i++) {
    fseek(fp, -1, SEEK_CUR);
    str[i] = (char)fgetc(fp);
    if (str[i] == '\n' && i != 0) {
      break;
    }
    fseek(fp, -1, SEEK_CUR);
  }
  str[i] = '\0';
  return str;
}

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  int bufLen = 1024;
  char line[bufLen];
  int lineCount = 5;

  fp = fopen(argv[1], "r");
  fseek(fp, 0, SEEK_END);

  for (int i = 0; i < lineCount && fgets_backwards(line, bufLen, fp) != NULL;
       i++) {
    printf("%s", line);
  }

  fclose(fp);
}
