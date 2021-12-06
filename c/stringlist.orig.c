#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define INITIAL_THRESHOLD 1

char *strdup(const char *s);

typedef struct slist {
  char **list;
  size_t size;
  size_t threshold;
} StringList_t, *StringList;

StringList newStringList(size_t threshold) {
  StringList myStringList = calloc(1, sizeof(StringList_t));
  myStringList->threshold = threshold;
  myStringList->size = 0;
  myStringList->list = calloc(threshold, sizeof(char *));
  return myStringList;
}

int appendStringList(StringList sl, const char *string) {
  if (!string) {
    return (1);
  }

  if ((sl->size + 1) == sl->threshold) {
    sl->threshold *= 2;
    printf("sl->threshold: %lu\n", sl->threshold);
    sl->list = realloc(sl->list, sl->threshold * sizeof(char *));
  }

  sl->list[sl->size] = strdup(string);
  sl->size++;

  return (0);
}

int destroyStringList(StringList sl) {
  if (sl) {
    free(sl);
  }
  return (0);
}

int printStringList(StringList sl) {
  for (int i = 0; i <= (sl->size - 1); i++) {
    printf("list[%d] = %s\n", i, sl->list[i]);
  }

  return (0);
}

int main(void) {
  StringList myStringList = newStringList(1);
  appendStringList(myStringList, "hello");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  appendStringList(myStringList, "world");
  printStringList(myStringList);
  destroyStringList(myStringList);

  return (0);
}
