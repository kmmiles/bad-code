#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define LINE_MAX 100

int main(void) {
  char line[LINE_MAX] = {0};
  int counter = 0;
  char *location;
  char **city_array = malloc(MAX_ENTRIES * sizeof(char *));

  FILE *fp = NULL;
  fp = fopen("strtok.txt", "r+");

  while (fgets(line, LINE_MAX, fp) != NULL) {
    if (!strtok(line, ",")) {
      continue;
    }

    if (!(location = strtok(NULL, "\n"))) {
      continue;
    }

    printf("location: %s\n", location);
    city_array[counter] = strdup(location);
    printf("%s\n", city_array[counter]);
    counter++;  // returns total amount lines that can be used by a later
                // function to iterate through the array
  }

  for (int t = 0; t < counter; t++) {
    printf("%s\n", city_array[t]);
  }

  free(city_array);
}
