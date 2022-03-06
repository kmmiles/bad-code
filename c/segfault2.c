int abc(char s[]) {
  for (int i = 0; s[i] != '\0'; ++i) {
    s[i] = 1;
    return 0;
  }
  return 1;
}

int main(void) {
  char string[] = "1";
  abc(string);
  // abc("1");
  return 0;
}
