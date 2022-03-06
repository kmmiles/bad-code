#include <stdio.h>

/*
enum bar { spam, eggs, test };

typedef struct FooStruct {
  enum bar breakfast;
} FooType;
*/

typedef struct FooStruct {
  enum { spam, eggs, test } bar;
} FooType;

int main(void) {
  FooType myFoo;

  myFoo.bar = test;
  printf("Hello, world: %d\n", myFoo.bar);
}
