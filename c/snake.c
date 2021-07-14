#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

int main( void ) {

  int i = 0;
  
  char board[90] =
  {
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0
  };

  int width = 9;
  while(1) {
    for ( i = 0; i < 90; ++i) {
    if (i > 0 && i % width==0) {
      printf("\n");
    }
    if( board[i] == 1 ) {
      printf("=");
      sleep(1);
    }
    else if( board[i] == 0 )
      printf(" ");
    }
    board[i + 1] = 1;
    system("clear");
  }
  printf("\n");
  return 0;
}
