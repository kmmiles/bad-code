#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termcap.h>
#include <unistd.h>

void clear_escape(void) { printf("\033c"); }

void clear_escape2(void) {
  printf("\033[2J\033[3J\033[H");
}

void cls(void) {
  printf("\033[2J\033[3J\033[H");
}

void clear_ncurses(void) {
  WINDOW *win = initscr();
  clear();
  delwin(win);
  endwin();
  refresh();
}

void clear_termcap(void) {
  char buf[1024] = {0};
  char *str = NULL;

  tgetent(buf, getenv("TERM"));
  if ((str = tgetstr("cl", NULL)) != NULL) fputs(str, stdout);
}

int main(void) {
  clear_escape2();
#if 0
  printf("Clear screen with ANSI escape sequence...\n");
  sleep(2);
  clear_escape();

  printf("Clear screen with termcap...\n");
  sleep(2);
  clear_termcap();

  printf("Clear screen with ncurses...\n");
  sleep(2);
  clear_ncurses();
#endif
}
