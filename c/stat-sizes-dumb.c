#include <dirent.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

bool check_if_arg_is_file(char* arg);

// TODO: add getopt function.

int main(int argc, char** argv) {
  bool file_exists = check_if_arg_is_file(argv[1]);
  if (file_exists == true) {
    struct stat file_st;
    lstat(argv[1], &file_st);
    printf("file size = %ld\n", file_st.st_size);
  }
  if (file_exists == false) {
    struct dirent* dir_read;
    DIR* directory = opendir(argv[1]);

    if (directory == NULL) {
      perror("Something went wrong\n");
      exit(EXIT_FAILURE);
    }

    int total_size = 0;

    while ((dir_read = readdir(directory))) {
      struct stat file_dir;
      lstat(dir_read->d_name, &file_dir);
      total_size = file_dir.st_size + total_size;
    }

    printf("dir size %d\n", total_size);
  }
}

bool check_if_arg_is_file(char* arg) {
  struct stat st;
  stat(arg, &st);
  return S_ISREG(st.st_mode);
}
