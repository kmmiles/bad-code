#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define INITIAL_THRESHOLD 1

char *strdup(const char *s);

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

int stringListAppend(StringList sl, char *string) {
  if(!string) {
    return(-1);
  }

  if((sl->count + 1) == sl->threshold) {
    sl->threshold *= 2;
    printf("sl->threshold: %lu\n", sl->threshold);
    sl->list = realloc(sl->list, sl->threshold * sizeof(char *));
  }

  //sl->list[sl->count] = strdup(string);
  sl->list[sl->count] = string;
  if(sl->list[sl->count] == NULL) {
    return(-2);
  }
  sl->count++;

  return(0);
}

void stringListDestroy(StringList sl) {
  /* free the strings */
#if 0
  for(int i=0; i <= (sl->count-1); i++) {
    if(sl->list[i]) {
      free(sl->list[i]);
    }
  }
#endif

  /* free the array */
  if(sl->list) {
    free(sl->list);
  }

  /* free the string list */
  if(sl) {
    free(sl);
  }
}

void stringListPrint(StringList sl) {
  for(int i=0; i <= (sl->count-1); i++) {
    //printf("%s\n", sl->list[i]);
    printf("list[%d] = %s\n", i, sl->list[i]);
  }
}

void doit(StringList sl, char *string) {
  char this[256] = {0};

  strcpy(this, string);
  stringListAppend(sl, this);
}

int main(void) {
  StringList myStringList = stringListNew();

  doit(myStringList, "hello");
  for(int i=1; i <= 1000; i++) {
    stringListAppend(myStringList, "world");
  }

  stringListPrint(myStringList);
  stringListDestroy(myStringList);

  return(0);
}
