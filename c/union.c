#include <stdio.h>
#include <string.h>

union EXAMPLE2 {
  int digit;
  char letter;
  float number;
};

union EXAMPLE3 {
  int digit;
  char letter;
  float number;
};

#if 0
Uh, why ask here? Anyway, in C an array can't be on the left side of an assignment except on declaration.
So this is valid:
```c
union EXAMPLE3 ex3[100] = {0};
```
And alternatively with `memset`:
```c
union EXAMPLE3 ex3[100];
memset(&ex3, 0, sizeof(ex3));
```
#endif

int main(void) {
  // union EXAMPLE2 ex2;
  union EXAMPLE3 ex3[100] = {0};

  // ex2 = (union EXAMPLE2) {0};

  // ex3 = (union EXAMPLE3) {0};
  //
  memset(&ex3, 0, sizeof(ex3));

  // ex3 = {0};
}
