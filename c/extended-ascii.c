#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main(void) { printf("\u250C\n"); }

#if 0
int main(void) {
  wchar_t c;
  setlocale(LC_ALL, "C");

  for (c = 128; c < 256; c++) {
      wprintf(L"char nr %d: %lc\n", c, c);
  }
  printf("\n%s\n", setlocale(0, NULL));

  return 0;
}
#endif

#if 0
int main(void) {
unsigned char c;

for (c = 32; c <= 255; c++) {
  putc(c, stdout);
}

return 0;
}
#endif
