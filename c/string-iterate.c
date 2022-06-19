#include <stdio.h>
#include <string.h>

int main(void) {
  char *mystring = "hello world";
  size_t mystring_len = strlen(mystring);
  for (int i = 0; i < mystring_len; i++) {
    printf("%s'%c'%s%s", i == 0 ? "[" : "", mystring[i],
           mystring[i + 1] ? "," : "", i == mystring_len - 1 ? "]\n" : "");
  }
}
