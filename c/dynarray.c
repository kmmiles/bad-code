#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int len = 312;
  int *options = NULL;

  options = (int *)calloc(sizeof(int), len);
  for(int i = 0; i < len ; i++) {
    options[i] = 69 + i;
  }

  for(int i = 0; i < len ; i++) {
    printf("options[%d] = %d\n",i,options[i]);
  }
}
