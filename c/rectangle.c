#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

bool isRectangleOverlap(int rec1[], int rec2[]) {
  bool widthIsPositive = MIN(rec1[2], rec2[2]) > MAX(rec1[0], rec2[0]);
  bool heightIsPositive = MIN(rec1[3], rec2[3]) > MAX(rec1[1], rec2[1]);
  return ( widthIsPositive && heightIsPositive);
}

char * intArrayToString(char *string, size_t string_sz, int arr[], size_t arr_sz) {
  strcpy(string, "");
  for(size_t i = 0; i < arr_sz; i++) {
    char temp[256] = {0};
    snprintf(temp, sizeof(temp), "%s%d%s%s",
        i == 0 ? "[" : "",
        arr[i],
        i < arr_sz-1 ? ", " : "",
        i == arr_sz-1 ? "]" : ""
        );
    strncat(string, temp, string_sz);
  }
  return string;
}

int main(void) {
  int rec1[] = {1,1,5,5};
  int rec2[] = {1,7,10,12};

  char mystr[256] = {0};
  printf("Rectangle 1 - %s\n", intArrayToString(mystr, sizeof(mystr), rec1, sizeof(rec1) / sizeof(rec1[0])));
  printf("Rectangle 2 - %s\n", intArrayToString(mystr, sizeof(mystr), rec2, sizeof(rec2) / sizeof(rec2[0])));

  printf("The rectangles are%s overlapping\n",
      isRectangleOverlap(rec1, rec2) ? "" : " not");
}
