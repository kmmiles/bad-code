#include <stdio.h>

int main(void) {
  //VARIABLES
  int a[10] = {'A','B','C','D','E','F','G','H','I','J'};
  char letra;
  int A ='A';
  int B ='B';
  int resultado = 0;
  //TODO
  printf("dame una letra");
  scanf("%c", &letra);
  for (int i = 0; i < 10; i ++){
    printf("dame una letra");
    scanf(" %c", &letra);
    resultado = letra + letra;
    printf("%d",resultado);
 }
  return 0;
}
