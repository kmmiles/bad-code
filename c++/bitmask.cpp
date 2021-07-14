#include <stdio.h>

int main(void) {
  int num=42;
  constexpr int mask_offset = 16;
  constexpr int mask = 0x7f << mask_offset;
  printf("%x\n", ( num & mask ) >> mask_offset);
}
