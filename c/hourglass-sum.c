#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

#if 0
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
#endif

int hourglassSum(int arr_rows, int arr_columns, int** arr) {
  int largest_sum = -63;

  // iterate rows and columns, ignoring the outer edges
  for (int row = 0 + 1; row < arr_rows - 1; row++) {
    for (int col = 0 + 1; col < arr_columns - 1; col++) {
      // each of the values is an hourglass "center" (c)
      // there are six additional values (v) in this hourglass
      // v v v
      //   c
      // v v v
      //
      // [row-1][col-1]     [row-1][col]   [row-1][col+1]
      //                     [row][col]
      // [row+1][col-1]     [row+1][col]   [row+1][col+1]
      int curr_sum = arr[row - 1][col - 1] + arr[row - 1][col] +
                     arr[row - 1][col + 1] + arr[row][col] +
                     arr[row + 1][col - 1] + arr[row + 1][col] +
                     arr[row + 1][col + 1];
      if (curr_sum > largest_sum) largest_sum = curr_sum;
    }
  }
  return largest_sum;
}

int main() {
  FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

  int** arr = malloc(6 * sizeof(int*));

  for (int i = 0; i < 6; i++) {
    *(arr + i) = malloc(6 * (sizeof(int)));

    char** arr_item_temp = split_string(rtrim(readline()));

    for (int j = 0; j < 6; j++) {
      int arr_item = parse_int(*(arr_item_temp + j));

      *(*(arr + i) + j) = arr_item;
    }
  }

  int result = hourglassSum(6, 6, arr);

  fprintf(fptr, "%d\n", result);

  fclose(fptr);

  return 0;
}

char* readline() {
  size_t alloc_length = 1024;
  size_t data_length = 0;

  char* data = malloc(alloc_length);

  while (true) {
    char* cursor = data + data_length;

    char* line = fgets(cursor, alloc_length - data_length, stdin);

    if (!line) {
      break;
    }

    data_length += strlen(cursor);

    if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
      break;
    }

    alloc_length <<= 1;

    data = realloc(data, alloc_length);

    if (!data) {
      data = 0;

      break;
    }
  }

  if (data && data[data_length - 1] == '\n') {
    data[data_length - 1] = 0;

    data = realloc(data, data_length);

    if (!data) {
      data = NULL;
    }

  } else {
    data = realloc(data, data_length + 1);

    if (!data) {
      data = 0;
    } else {
      data[data_length] = 0;
    }
  }

  return data;
}

char* ltrim(char* str) {
  if (!str) {
    return 0;
  }

  if (!*str) {
    return str;
  }

  while (*str != '\0' && isspace(*str)) {
    str++;
  }

  return str;
}

char* rtrim(char* str) {
  if (!str) {
    return 0;
  }

  if (!*str) {
    return str;
  }

  char* end = str + strlen(str) - 1;

  while (end >= str && isspace(*end)) {
    end--;
  }

  *(end + 1) = 0;

  return str;
}

char** split_string(char* str) {
  char** splits = NULL;

  char* token = strtok(str, " ");

  int spaces = 0;

  while (token) {
    splits = realloc(splits, sizeof(char*) * ++spaces);

    if (!splits) {
      return splits;
    }

    splits[spaces - 1] = token;

    token = strtok(NULL, " ");
  }

  return splits;
}

int parse_int(char* str) {
  char* endptr;
  int value = strtol(str, &endptr, 10);

  if (endptr == str || *endptr != '\0') {
    exit(EXIT_FAILURE);
  }

  return value;
}
