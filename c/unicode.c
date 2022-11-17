#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main(void) {
  wchar_t diamond = 0x2660;
  wchar_t club = 0x2663;
  wchar_t star = 0x2605;

  setlocale(LC_CTYPE, "");
  wprintf(L"%lc\n", diamond);
  wprintf(L"%lc\n", club);
  wprintf(L"%lc\n", star);
}
