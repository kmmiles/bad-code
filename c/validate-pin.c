// help, it must return true if pin is 4 digit and 6 digit and false if it has
// character besides numbers
//
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validate_pin(const char *pin) {
  if (pin == NULL) {
    return false;
  }

  size_t pinsize = strlen(pin);
  if (pinsize != 4 && pinsize != 6) {
    return false;
  }

  for (int i = 0; i < pinsize; i++) {
    if (!isdigit(pin[i])) {
      return false;
    }
  }

  return true;
}

int main(int argc, char **argv) {
  if (!validate_pin(argv[1])) {
    printf("validate_pin failed\n");
    exit(1);
  } else {
    printf("validate_pin succeeded\n");
    exit(0);
  }
}
