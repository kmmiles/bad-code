void sleep(int ticks) {
  for (int x = 0; x <= ticks; x++) {
    ;
  }
}

int main(void) { sleep(99999999); }
