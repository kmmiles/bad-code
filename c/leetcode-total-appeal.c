#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
Input: s = "code"
Output: 20
Explanation: The following are the substrings of "code":
- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
The total sum is 4 + 6 + 6 + 4 = 20.
#endif

long long appealSum(char *s) {
  size_t len = strlen(s ? s : "");
  if (!len) {
    return (0);
  } else if (len == 1) {
    return (1);
  }

  printf("len = %lu\n", len);

  return (0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    exit(1);
  }
  printf("%lld\n", appealSum(argv[1]));
}
