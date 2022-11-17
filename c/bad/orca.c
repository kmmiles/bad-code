//#include <orca/log.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#include <orca/discord.h>

void init_spam(const char *floc) {
  FILE *fp;
  if ((fp = fopen(floc, "r")) == NULL) {
    // log_fatal("unable to open %s", floc);
    exit(1);
  }

  printf("fp: %x\n", &fp);

  int i = 0;
  int o = 2;

  char *buf = malloc(1);
  printf("buf: %x\n", &buf);
  char *bufbuf = malloc(1);
  printf("bufbuf: %x\n", &bufbuf);

  while (!feof(fp)) {
    printf("next alloc: %d\n", o);
    bufbuf[i] = fgetc(fp);
    strcpy(buf, bufbuf);
    printf("buf: %x\n", &buf[o - 1]);
    printf("buf: %x\n", &buf);
    printf("bufbuf: %x\n", &bufbuf[o - 1]);
    printf("bufbuf: %x\n", &bufbuf);
    bufbuf = realloc(bufbuf, o);
    printf("bufbuf: %x\n", &bufbuf[o]);
    printf("bufbuf: %x\n", &bufbuf);
    strcpy(bufbuf, buf);
    printf("buf: %x\n", &buf[o - 1]);
    printf("buf: %x\n", &buf);
    printf("bufbuf: %x\n", &bufbuf[o]);
    printf("bufbuf: %x\n", &bufbuf);
    buf = realloc(buf, o);
    printf("buf: %x\n", &buf[o]);
    printf("buf: %x\n", &buf);
    printf("fp: %x\n", &fp);
    printf("----------------\n");
    o++;
    i++;
  }

  for (int i = 0; bufbuf[i] != (char)0xFF;
       i++) {  // For some reason printf always ends up printing 0xFF
    sprintf(buf[i], "%c",
            bufbuf[i]);  // to stdout; it has nothing to do with the file
    if (i >= o) {
      break;
    }
  }
  printf("%s", bufbuf);

  free(buf);
  free(bufbuf);

  fclose(fp);
}

int main(void) {
  init_spam("helloworld");
  return 0;
}
