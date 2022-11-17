#include <dirent.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define DEBUG 1

#define debug_print(fmt, ...)                                           \
  do {                                                                  \
    if (DEBUG)                                                          \
      fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, \
              __VA_ARGS__);                                             \
  } while (0)

long int file_size_recursive(const char* path, bool inblocks) {
  long int total_size = 0;

  // bad arguments
  if (!path || !*path) {
    debug_print("%s\n", "bad arguments");
    return 0;
  }

  // first, find out what type of path was provided
  struct stat path_st;
  if (lstat(path, &path_st) == -1) {
    perror(path);
    return 0;
  }

  // not actually a directory, return the file size and done.
  if (!S_ISDIR(path_st.st_mode)) {
    return inblocks ? path_st.st_blocks : path_st.st_size;
  }

  // we're working with a valid directory

  // include size of the directory itself.
  total_size += inblocks ? path_st.st_blocks : path_st.st_size;

  DIR* directory = opendir(path);
  if (directory == NULL) {
    perror(path);
    return 0;
  }

  for (struct dirent* dir_read = NULL; (dir_read = readdir(directory));) {
    if (!strcmp(dir_read->d_name, "..") || !strcmp(dir_read->d_name, "."))
      continue;

    struct stat file_dir;
    char newpath[PATH_MAX] = {0};
    sprintf(newpath, "%s%s%s", !strcmp(path, "/") ? "" : path,
            !strcmp(path, "/") ? "" : "/", dir_read->d_name);

    if (lstat(newpath, &file_dir) == -1) {
      perror(newpath);
      continue;
    }

    if (S_ISDIR(path_st.st_mode)) {
      // is a directory
      total_size += file_size_recursive(newpath, false);
    } else if (S_ISREG(path_st.st_mode)) {
      // is a regular file
      total_size += inblocks ? file_dir.st_blocks : file_dir.st_size;
    } else {
      debug_print("skipping entry %s with mode %d\n", newpath,
                  file_dir.st_mode);
    }
  }

  closedir(directory);
  return total_size;
}

int main(int argc, char** argv) {
  const char* progname = argv[0];
  const char* path = argv[1];

  if (argc < 2 || !path || !*path) {
    printf("Usage: %s <path>\n", progname);
    exit(EXIT_FAILURE);
  }

  printf("total: %ld\n", file_size_recursive(path, false));
}
