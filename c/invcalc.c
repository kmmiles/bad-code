#include <math.h>
#include <stdio.h>

int main()  // ACT's Rudimentary Investment-Return Calculator, V1.1.1
{
  double inv, rate, ret, prf;
  int wks = 1;
  int prc = 0;
  int inc = 0;
  char prd = 'x';
  char ind = 'n';
  do {
    printf("\nInvestment: ");
    scanf("%lf", &inv);
    printf("\nInterest Rate %: ");
    scanf("%lf", &rate);
    rate = rate + 100;
    do {
      prc++;
      printf("\nAnnual Period (a), or Monthly Period (m)?: ");
      scanf(" %c", &prd);
      if (prd == 'm') {
        prf = 4.3;
      }
      if (prd == 'a') {
        prf = 52;
      } else if (prd != 'm' || prd == 'a') {
        prc = 0;
        printf("\nError 01: Invalid period selection!\n");
      }
    } while (prc < 1);
    printf("\nInvestment of $%lf, Rate of %lf%, over a Period of %lf Weeks",
           inv, rate, prf);
    printf("\nIs this correct? (y/n): ");
    scanf(" %c", &ind);
    if (ind == 'y') {
      inc++;
    }
  } while (inc < 1);
  rate = rate / 100;
  printf("\nHow many weeks should we calculate it for?: ");
  scanf(" %d", &wks);
  double x = 1;
  int y = 1;
  printf("\nWeek 0: $%lf", inv);
  for (ret = 0; wks != 0; wks--) {
    x = x / prf;
    ret = powf(rate, x);
    ret = ret * inv;
    printf("\nWeek %d: $%lf", y, ret);
    y++;
    x = y;
  }
  return 0;
}

// Copyright 2022 act
/*
 *This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version. This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
details. You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>.
 */
