#include <stdint.h>
#include <stdio.h>

static void *H(const void *x, const size_t xlen, const void *y,
               const size_t ylen, void *out, const size_t outlen) {
  const size_t buflen = xlen + ylen;
  uint8_t buf[buflen];

  memcpy(buf, x, xlen);
  memcpy(buf + xlen, y, ylen);

  return sha256(buf, buflen * sizeof(uint8_t), out, outlen);
}

int main(void) {}
