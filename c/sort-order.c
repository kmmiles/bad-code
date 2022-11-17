#include <stdio.h>
#include <stdbool.h>

bool do_thing(int num1, int num2, bool lesser) {
  return(lesser ? num1 < num2 : num1 > num2);
}

int main(void) {

  if(do_thing(2, 1, false)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  if(do_thing(2, 1, true)) {
    printf("true\n");
  } else {
    printf("false\n");
  }


}
