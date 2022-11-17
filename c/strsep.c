#include <stdio.h>
#include <string.h>

int main(void) {
  char* line = strdup(
      "000000000001;Luísa "
      "Almeida;19/09/1990;F;green;EV-54-07;Setúbal;05/07/2021;active");

  char* token;
  while ((token = strsep(&line, ";")) != NULL) {
    printf("%s\n", token);
  }
}
