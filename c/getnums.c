#include <stdio.h>
#include <string.h>

int getnum(void) {
  int num = 0;

  while (1) {
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    if (num % 10 != 0) {
      printf("Number must be a multiple of 10!\n");
    } else {
      break;
    }
  }
  return num;
}

int main() {
  int vnumeros[100];
  int num2, a, o, num, i, opi, suma;

  for (a = 0; a < 20; a++) {
    vnumeros[a] = getnum();
  }

  suma = 0;
  printf("Sumatorioa de todos los numeros\n");
  printf("Numeros entre 30-90\n");
  printf("Numeros en posiciones impares de la cadena\n");
  scanf("%d", &opi);
  switch (opi) {
    case 1: {
      for (i = 0; i < 20; i++) {
        suma += vnumeros[i];
      }
      printf("%d", suma);
      break;
    }

    case 2: {
      for (i = 0; i < 20; i++) {
        suma = vnumeros[i];
        if (suma > 30 && 90 > suma) {
          printf("%d\n", suma);
        }
      }

      break;
    }
    case 3: {
      for (i = 0; i < 20; i++) {
        if (i % 2 == 0) {
          printf("%d ", vnumeros[i]);
        }
      }
      break;
    }
  }
  return 0;
}
