#include <stdint.h>
#include <stdio.h>

struct Arguments {
  int i;
  float f;
  char *str;
};

void do_thing(struct Arguments args) {
  printf("%d, %f, %s\n", args.i, args.f, args.str);
}

void call(void (*fn)(), int argc, ...) {
  va_list l;
  va_start(l, argc);

  struct {
    uint64_t segs[argc];
  } args;
  for (int i = 0; i < argc; i++) args.segs[i] = va_arg(l, uint64_t);

  fn(args);
}

int main() { call((void *)do_thing, 2, 10, 3.14, "Hello!"); }
