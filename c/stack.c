#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int capacity;
  int size;
  double* data;
} Stack;

Stack* stack_create(void) {
  Stack* stk = (Stack*)malloc(sizeof(Stack));

  stk->capacity = 5;
  stk->size = -1;
  stk->data = (double*)calloc(stk->capacity, sizeof(double));

  return stk;
}
// Destroy the stack.
void stack_destroy(Stack* s) {
  free(s->data);
  free(s);
}

// Push a value onto the stack.
void stack_push(Stack* s, double value) {
  if (s->size == s->capacity - 1) {
    s->capacity *= 2;
    s->data = (double*)realloc(
        s->data,
        s->capacity * sizeof(double));  // i am wondering what i am doing wrong?
  }

  s->data[++s->size] = value;
}

// Check if the stack is empty.
bool stack_is_empty(const Stack* s) {
  if (s->size == -1) {
    return true;
  } else {
    return false;
  }
}

// Pop the value at the top of the stack.
double stack_pop(Stack* s) {
  double val = -1;
  if (!stack_is_empty(s)) {
    val = s->data[s->size--];
  }

  return val;
}

int main(void) {
  // Create an empty stack.
  Stack* s = stack_create();

  // Push some values.
  for (int i = 0; i < 100; i++) {
    stack_push(s, i);
  }

  // Pop and print.
  while (!stack_is_empty(s)) {
    printf("%8.2lf\n", stack_pop(s));
  }

  // Clean up.
  stack_destroy(s);

  return 0;
}
