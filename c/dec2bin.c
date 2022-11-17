#include <stdio.h>
#include <string.h>

char * dec2bin(int x) {
  int number = x;
  //char result[1024] = {0};
  char *result = malloc(1024);

  for(int i = 0; number > 0; i++)
  {
    char temp[64] = {0};
    sprintf(temp, "%d", number % 2);
    strcat(result, temp);
    number = number / 2;
  }

  return result;
}

int main(int argc, char *argv[]) 
{
  char *str = dec2bin(atoi(argv[1]));
  printf("str: %s\n",str);
  return 0;
}
