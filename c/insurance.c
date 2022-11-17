#include <stdio.h>
#include <stdlib.h>

/* returns base price, based on year. */
double base_price(int year) {
  if(year <= 2010) {
    return 856.0;
  } else if(year >= 2011 && year <= 2013) {
    return 811.0;
  } else if(year >= 2014 && year <= 2016) {
    return 783.0;
  } else if(year >= 2017 && year <= 2020) {
    return 807.0;
  } else if(year == 2021) {
    return 1065.0;
  } else {
    return 0.0;
  }
}

/* returns policy cost, based on year and accidents.
 * if cost cannot be determined, 0.0 is returned.
 */
double policy_cost(int year, int accidents) {
  double basePrice = base_price(year);
  if(basePrice == 0.0) {
    return 0.0;
  }

  if(accidents == 0) {
    return basePrice;
  } else if(accidents == 1) {
    return basePrice * 1.1;
  } else if(accidents == 2) {
    return basePrice * 1.4;
  } else if(accidents == 3) {
    return basePrice * 1.6;
  } else if(accidents > 3) {
    return basePrice * 2.1;
  } else {
    return 0.0;
  }
}

int main(void) {
  int year = 0;
  printf("Enter the year you got your car: ");
  scanf("%d", &year);
  if(year < 2000 || year > 2021) {
    printf("ERROR: Year must be between 2000 and 2021.\n");
    exit(1);
  }

  int accidents = 0;
  printf("Enter the total number of accidents involving your car: ");
  scanf("%d", &accidents);
  if(accidents < 0 || accidents > 100) {
    printf("ERROR: number of accidents must be between 0 and 100.\n");
    exit(1);
  }

  printf("Policy cost: %f\n", policy_cost(year, accidents));
}
