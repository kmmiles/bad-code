#include <stdio.h>
#include <stdint.h>

struct numbers {
  uint8_t s_a;
  uint8_t s_b;
  uint8_t s_c;
  uint8_t s_d;
};

struct foo {
  uint32_t a;
  struct {
    uint8_t s_a;
    uint8_t s_b;
    uint8_t s_c;
    uint8_t s_d;
  } nums;
};

struct bar {
  uint32_t a;
  struct numbers nums;
};

struct anon {
  uint32_t a;
  struct {
    uint8_t s_a;
    uint8_t s_b;
    uint8_t s_c;
    uint8_t s_d;
  };
};

int main(void) {
  //

  struct foo f;
  struct bar b;
  struct anon a;

  printf("size of f: %lu\n", sizeof(f));
  printf("size of b: %lu\n", sizeof(b));
  printf("size of a: %lu\n", sizeof(a));

  return(0);
}
