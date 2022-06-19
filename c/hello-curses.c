#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*  for sleep()  */

int main(void) {
  WINDOW* mainwin;

  /*  Initialize ncurses  */

  if ((mainwin = initscr()) == NULL) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }

  /*  Display "Hello, world!" in the centre of the
      screen, call refresh() to show our changes, and
      sleep() for a few seconds to get the full screen effect  */

  mvaddstr(13, 33, "Hello, world!");
  refresh();
  sleep(3);
  getch();

  /*  Clean up after ourselves  */

  delwin(mainwin);
  endwin();
  refresh();

  return EXIT_SUCCESS;
}
