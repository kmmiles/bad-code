#include <stdio.h>

void foo(a, b) int a;
int b;
{ printf("a: %d, b: %d\n", a, b); }

int main(void) { foo(4, 2); }
