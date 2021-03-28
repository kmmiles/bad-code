#include <stdio.h>
#include <string.h>

void * dumb_malloc(int nbytes){
    char variable[nbytes];
    return &variable;
}

int main(void) {

  char *dumb = dumb_malloc(20);

  strcpy(dumb, "dumb");

  printf("dumb: %s\n", dumb);
}
