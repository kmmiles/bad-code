#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define INITIAL_THRESHOLD 1

char *strdup(const char *s);

/*
typedef struct sstring {
  char *string;
  bool
}
*/

typedef struct slist {
  char **list;
  size_t count;
  size_t threshold;
} StringList_t, *StringList;

StringList stringListNew(void) {
  StringList sl = malloc(sizeof(StringList_t));
  sl->count = 0;
  sl->threshold = INITIAL_THRESHOLD;
  sl->list = NULL;
  return sl;
}

int _stringListAppend(StringList sl, char *string, bool copy) {
  if (!string) {
    return (-1);
  }

  if ((sl->count + 1) == sl->threshold) {
    sl->threshold *= 2;
    // printf("sl->threshold: %lu\n", sl->threshold);
    sl->list = realloc(sl->list, sl->threshold * sizeof(char *));
  }

  sl->list[sl->count] = copy ? strdup(string) : string;
  if (sl->list[sl->count] == NULL) {
    return (-2);
  }
  sl->count++;

  return (0);
}

int stringListAppend(StringList sl, char *string) {
  return _stringListAppend(sl, string, false);
}

int stringListAppendCopy(StringList sl, char *string) {
  return _stringListAppend(sl, string, true);
}

void stringListDestroy(StringList sl) {
  if (!sl) {
    /* we can't do anything here. */
    return;
  }

  /* free the strings */
  for (int i = 0; i < sl->count; i++) {
    if (sl->list && sl->list[i]) {
      free(sl->list[i]);
    }
  }

  /* free the array */
  if (sl->list) {
    free(sl->list);
  }

  /* free the string list */
  free(sl);
}

void stringListPrint(StringList sl) {
  for (int i = 0; i <= (sl->count - 1); i++) {
    // printf("%s\n", sl->list[i]);
    printf("list[%d] = %s\n", i, sl->list[i]);
  }
}

const char *stringListGet(StringList sl, int index) {
  if (index > sl->count) {
    return (NULL);
  }
  return sl->list[index];
}

size_t stringListCount(StringList sl) { return (sl->count); }

int main(void) {
  printf("Feeling bad...\n");
  free("hello");

  StringList myStringList = stringListNew();
  stringListAppendCopy(myStringList, "hello");
  stringListAppendCopy(myStringList, "world");
  stringListAppendCopy(myStringList, "this");
  stringListAppendCopy(myStringList, "is");
  stringListAppendCopy(myStringList, "my");
  stringListAppendCopy(myStringList, "reality");
  /*
  for (int i = 1; i <= 1000; i++) {
    stringListAppend(myStringList, "world");
  }
  */

  printf("count: %lu\n", stringListCount(myStringList));
  printf("%s\n", stringListGet(myStringList, 5));

  // stringListPrint(myStringList);
  stringListDestroy(myStringList);

  return (0);
}
