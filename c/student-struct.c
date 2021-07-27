#include <stdio.h>

int main(void) {

  struct Subject {
    char name[25];
    char grade;
  };

  struct Student {
    char fName[25];
    char lName[25];
    char dob[10];
    char address[50];
    struct Subject subjects[20];
  };

  
  struct Student student;
  memset(&student, 0, sizeof(student));

  printf("%lu\n", sizeof(student.subjects) / sizeof(struct Subject));


}
