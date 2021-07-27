#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// O(nn)
bool is_unique(const char *s)
{
  int len = strlen(s);
  for(int i=0; i <= len-1; i++) {
    for(int x=i+1; x <= len-1; x++) {
      if(s[i] == s[x]) {
        return(false);
      }
    }
  }
  return(true);
}

// O(n)
bool is_unique2(const char *s) {
  bool char_set[128] = {0};

  int len = strlen(s);
  if (len > 128) {
    return(false);
  }

  for(int i=0; i <= len-1; i++) {
    int val = s[i];
    if (char_set[val]) {
      return(false);
    }
    char_set[val] = true;
  }

  return(true);
}

int main(int argc, char **argv)
{
  char *s = argv[1] ? argv[1] : "";
  if(is_unique2(s)) {
    printf("[%s] All chars are unique\n",s);
  } else {
    printf("[%s] All chars are not unique\n",s);
  }
}
