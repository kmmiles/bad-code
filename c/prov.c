#include <stdio.h>
#define pop 13
#define SIZE 100
#define provterr 13
void printProvince(int);

int main() {
  char prov[provterr][SIZE] = {"Alberta: ",      "British Columbia: ",
                               "Manitoba: ",     "New Brunswick: ",
                               "Newfoundland: ", "Northwest Territory: ",
                               "Nova Scotia: ",  "Nunavut: ",
                               "Ontario: ",      "Prince Edward Island: ",
                               "Quebec: ",       "Saskatchewan: ",
                               "Yukon: "};
  char population[pop];
  for (int i = 0; i < provterr; i++) {
    printf("\n[%d.] %s", i + 1, prov[i]);
    scanf("%c", &population[i]);
  }
  printf("\n");
  return 0;
}
