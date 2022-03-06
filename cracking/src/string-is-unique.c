#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_unique_forward(const char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    for (int x = i + 1; x < len; x++) {
      printf("s[%d] = %c, s[%d] = %c\n", i, s[i], x, s[x]);
      if (s[i] == s[x]) {
        return (false);
      }
    }
  }
  return (true);
}

bool is_unique(const char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    for (int x = len - 1; x - i > 0; x--) {
      printf("s[%d] = %c, s[%d] = %c\n", i, s[i], x, s[x]);
      if (s[i] == s[x]) {
        return (false);
      }
    }
  }
  return (true);
}

// O(n)
bool is_unique2(const char *s) {
  bool char_set[128] = {0};

  size_t len = strlen(s);
  if (len > 128) {
    return (false);
  }

  for (int i = 0; i < len; i++) {
    int val = s[i];
    if (char_set[val]) {
      return (false);
    }
    char_set[val] = true;
  }

  return (true);
}

int main(int argc, char **argv) {
  char *s = argv[1] ? argv[1] : "";
  if (is_unique(s)) {
    printf("[%s] All chars are unique\n", s);
  } else {
    printf("[%s] All chars are not unique\n", s);
  }
}
