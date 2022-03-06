#include <stdio.h>
#include <string.h>

int bintodec(char *str) {
  int x = 0;
  int i = 0;
  while (str[i] != '\0') {
    x = (str[i] - '0') + x * 2;
    i++;
  }
  return x;
}

int main(void) {
  int decRep = 0;
  char *binaryMsg =
      "010110010110111101110101001000000110011001101111011101010110111001100100"
      "001000000111010001101000011001010010000001110011011001010110001101110010"
      "011001010111010000100000011011010110010101110011011100110110000101100111"
      "011001010010111";
  int length = strlen(binaryMsg);

  for (int i = 0; i < length / 8; i++) {
    char binaryRep[9] = {0};
    strncpy(binaryRep, binaryMsg + (i * 8),
            8);  // copies the first byte of binaryMSG to binaryRep
    decRep =
        bintodec(binaryRep);  // You can print the character value of decRep for
                              // the first character of the secret message
    printf("%c", decRep);
  }
  printf("\n");
  return 0;
}
