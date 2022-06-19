#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_THRESHOLD 1

int main() {
  FILE *cfPtr = NULL;
  // char *words[1000000];
  // char *intoHere[1000];
  char **words = NULL;
  char buffer[255];
  size_t word_count = 0;

  cfPtr = fopen("test.txt", "r");
  if (!cfPtr) {
    perror("test.txt");
    exit(1);
  }

  size_t threshold = 1;
  for (int i = 0; fgets(buffer, sizeof(buffer), cfPtr); i++) {
    if ((i + 1) == threshold) {
      threshold *= 2;
      printf("reallocing to treshold %lu\n", threshold);
      words = realloc(words, threshold * sizeof(char *));
    }
    size_t word_len = strlen(buffer);
    if (buffer[word_len - 1] == '\n') {
      printf("found newline\n");
      word_len--;
    }
    words[i] = malloc(word_len + 1);
    memset(words[i], 0, word_len + 1);
    strncpy(words[i], buffer, word_len);
    word_count++;
  }

  printf("word_count: %lu\n", word_count);
  for (int i = 0; i < word_count; i++) {
    // printf("%s\n", sl->list[i]);
    printf("words[%d] = %s\n", i, words[i]);
  }

  return 0;
}
