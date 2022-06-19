#include "TypingTutor.h"

int main(int argc, char const* argv[]) {
  char user_input[200];
  char* Words[] = {"word1",  "word2",  "word3",  "word4",  "word5",  "word6",
                   "word7",  "word8",  "word9",  "word10", "word11", "word12",
                   "word13", "word14", "word15", "word16", "word17", "word18"};
  size_t arr_size = sizeof(Words) / sizeof(Words[0]);
  Print_Sentence(Words, arr_size);
  User_Input(user_input);
  printf("a %s\n", user_input);
  Compare_Strings(user_input, Words);
  return 0;
}
