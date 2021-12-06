/// PRIMESCALCULATOR///
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
//#define max 100
#define max 1000000

int main() {
  printf("SIZE_MAX: %lu\n", SIZE_MAX);

  clock_t begin = clock();
  unsigned long int div, cur = 2, ans, primecount = 0, skiplist[max], skk = 0,
                         primes[max], sks = 0;
  while (cur <= max) {
    div = 1;
    while (div <= (cur + 2) / 2) {
      ans = cur % div;
      if (ans == 0 && div != 1 && div != cur) break;
      div++;
    }

    if (ans != 0 || cur < div) primes[primecount++] = cur;

    skiplist[skk] = skk = cur;

    while (skk < max) {
      if (skk < max) {
        skiplist[skk] = skk;
        skk = skk + cur;
        sks++;
      } else
        break;
    }

    while (cur == skiplist[cur]) cur++;
  }

  for (skk = 0; skk < primecount; skk++) printf("%llu\n", primes[skk]);
  clock_t end = clock();
  printf("%llu primes\n", primecount);
  printf("%f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
