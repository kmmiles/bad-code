#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SProducts {
  char *name;
  struct SProducts *next;
} Products;

Products *Add(Products *list, char *file) {
  Products *el = (Products *)malloc(sizeof(Products));
  if (el != NULL) {
    el->name = strdup(file);
    el->next = list;
  }
  return el;
}

void PrintList(Products *list) {
  while (list != NULL) {
    printf("%s", list->name);
    list = list->next;
  }
}

int main(void) {
  Products *list = NULL;
  char file[255];
  while (fgets(file, sizeof(file), stdin) != NULL) {
    list = Add(list, file);
    if (file[0] == '\n') {
      break;
    }
  }

  PrintList(list);
}
