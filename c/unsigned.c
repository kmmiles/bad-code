#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned long ID;
  unsigned int time;
  unsigned int arrival;
} Data;

Data* create_data(long id, int time, int arrival){
  Data *d=(Data*) malloc(sizeof(Data));
  if (time<=0) {
    d->time = 0;
  } else {
    d-> time=time;
  }

  if (arrival < 0) {
    d->arrival = 0;
  } else {
    d-> arrival=arrival;
  }

  if (id<=0) {
    d->ID = 0;
  } else {
    d-> ID=id;
  }

  return d;
}

int is_equal_data(Data* d1, Data* d2){
  if (d1->time==d2->time && d2->arrival==d1->arrival && d1->ID==d2->ID) {
    return 1;
  }
  return 0;
}

int main(void) {

  Data *foo = create_data(-50000, 42, 42);
  Data *bar = create_data(-1, 42, 42);

  if(is_equal_data(foo, bar)) {
    printf("It's equal\n");
  } else {
    printf("It's not equal\n");
  }

  free(foo);
  free(bar);

}
