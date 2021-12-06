#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void write_uint32(stream *s, u_int32_t val) {
  s->buff[s->pos] = (val >> 24);
  s->buff[s->pos + 1] = (val & 0x00FF0000) >> 16;
  s->buff[s->pos + 2] = (val & 0x0000FF00) >> 8;
  s->buff[s->pos + 3] = (val & 0x000000FF) >> 0;
  s->pos += 4;
}
#endif

typedef struct stream_t {
  uint8_t *buff;
  size_t pos;
} stream;

int main(void) {
  uint32_t val = 1525934176;

  stream mystream;
  mystream.buff = calloc(10, sizeof(uint8_t));
  mystream.buff[4] = (val >> 24);
  //  printf("hello %u\n", mystream.buff[4]);

  free(mystream.buff);

  //  printf("hello world: %u\n", val);
  //  printf("hello world: %u\n", (val & 0x00FF0000) >> 16);
}
