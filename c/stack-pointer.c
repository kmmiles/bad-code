#include <stdio.h>

int main() {
  int offset = 32;
  char message[500] = "in main";  // pomenat

  // printf("Enter offset number: ");
  // scanf("%d", &offset);
  // printf("Enter message: ");
  // scanf("%s", message);

  register void *stackPointer asm("esp");
  void *frameAdd = __builtin_frame_address(0);
  printf("Stack (offset: %d): %s\n", offset, message);
  printf("Frame pointer: %p \n", frameAdd);
  printf("Stack pointer: %p \n", stackPointer);
}
