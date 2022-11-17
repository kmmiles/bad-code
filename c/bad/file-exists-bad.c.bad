#include <stdio.h>

int main(int argc, char **argv) {
  FILE *file;

  if ((file = fopen(argv[0], "r")) != NULL) {
    fclose(file);
    return (0);
  }

  file = fopen(argv[0], "r");
  if (!file) {
    fclose(file);
    return (0);
  }

  if (file = fopen(argv[0], "r")) {
    fclose(file);
  } else {
    printf("Unable to open filename %s", argv[0]);
    for (int i = 0; i < argc; i++) {
      printf("%s", argv[i]);
    }

    printf("\n%s\n", "./tv state.csv tgoransaction.csv");
    printf("%s\n", "./tv ../state.csv /data/log/transaction.csv");
    return 2;
  }
}
