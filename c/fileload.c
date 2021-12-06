#include <stdio.h>
#include <stdlib.h>

char *file_load(const char *filename) {
  FILE *_file;

  _file = fopen(filename, "rb");
  if (_file == NULL) return NULL;
  // Get file length
  if (fseek(_file, 0, SEEK_END) != 0) return NULL;

  long len = ftell(_file);

  if (len < 0) return NULL;

  rewind(_file);

  /* Allocate enough memory for the file and the null terminator.*/
  char *tmp_buffer = malloc(sizeof(char) * (len + 1));
  if (tmp_buffer == NULL) {
    return NULL;
  }

  size_t n_bytes_read = fread(tmp_buffer, sizeof(char), len, _file);
  tmp_buffer[len] = '\0';
  fclose(_file);

  return tmp_buffer;
}

int main(int argc, char **argv) {
  char *str = file_load("fileload.c");
  printf("%s", str);
}
