#include <stdio.h>
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <string.h>

struct Date {
  int day, month, year;
};

typedef struct {
  int memberID;
  char memberName[20];
  char memberGender[5];
  char memberIC[15];
  char memberContactNum[14];
  char ranking;
  struct Date dateJoined;
} Member;

// n = number of student
// i = loop for how many student
// s = silver
// g = gold
// d = diamond

void create() {
  Member m;
  FILE* fptr;
  int n, i = 0;

  printf("How many member details you want to key in? > ");
  scanf("%d", &n);

  fptr = fopen("memberDetails.txt", "w");

  for (i = 0; i < n; i++) {
    printf("\n");
    printf("\tPlease enter your ID (exp:0001)> ");
    scanf("%d", &m.memberID);

    printf("\tPlease enter your name > ");
    rewind(stdin);
    scanf("%[^\n]", m.memberName);

    printf("\tPlease enter your Gender(Sir / Miss) > ");
    rewind(stdin);
    scanf("%s", m.memberGender);

    printf("\tPlease enter your IC > ");
    rewind(stdin);
    scanf("%s", m.memberIC);

    printf("\tPlease enter your Contact Number > ");
    rewind(stdin);
    scanf("%[^\n]", m.memberContactNum);

    printf("\tRanking?(S = Silver / G = Gold / D = Diamond)> ");
    rewind(stdin);
    scanf("%c", &m.ranking);

    printf("\tDay joined? > ");
    scanf("%d", &m.dateJoined.day);

    printf("\tMonth joined? > ");
    scanf("%d", &m.dateJoined.month);

    printf("\tYear joined? > ");
    scanf("%d", &m.dateJoined.year);

    printf("\n========================================================\n");

    fprintf(fptr, "%d|%s|%s|%s|%s|%c|%d|%d|%d\n", m.memberID, m.memberName,
            m.memberGender, m.memberIC, m.memberContactNum, m.ranking,
            m.dateJoined.day, m.dateJoined.month, m.dateJoined.year);
  }
  fclose(fptr);
}

void display() {
  Member m;
  FILE* fptr;
  int count = 0;

  fptr = fopen("memberDetails.txt", "r");

  if (fptr == NULL) {
    printf("This file cannot be open!\n");
    exit(-1);
  }

  printf("\n");
  printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "ID", "NAME",
         "Gender", "IC", "PhoneNo", "Ranking", "Day", "Month", "Year");
  printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "==", "====",
         "======", "==", "=======", "=======", "===", "=====", "====");

  while (fscanf(fptr, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d|%d|%d", &m.memberID,
                m.memberName, m.memberGender, m.memberIC, m.memberContactNum,
                &m.ranking, &m.dateJoined.day, &m.dateJoined.month,
                &m.dateJoined.year) != EOF) {
    printf("%2d %15s %9s %18s %18s %7c %13d %10d %13d\n", m.memberID,
           m.memberName, m.memberGender, m.memberIC, m.memberContactNum,
           m.ranking, m.dateJoined.day, m.dateJoined.month, m.dateJoined.year);
    count++;
  }
  fclose(fptr);

  printf(
      "\n*---------------------------------------------------------------------"
      "-----------------------------------*\n");
  printf("Number of record is %d..\n", count);
  printf(
      "*-----------------------------------------------------------------------"
      "---------------------------------*\n");
}

void append() {
  Member m;
  FILE* fptr;
  int n, i = 0, s = 0, g = 0, d = 0;

  printf("How many member details you want to key in? > ");
  scanf("%d", &n);

  fptr = fopen("memberDetails.txt", "a");

  for (i = 0; i < n; i++) {
    printf("\t\nPlease enter your ID (exp:0001)> ");
    scanf("%d", &m.memberID);

    printf("\tPlease enter your name > ");
    rewind(stdin);
    scanf("%[^\n]", m.memberName);

    printf("\tPlease enter your Gender(Sir / Miss) > ");
    rewind(stdin);
    scanf("%s", m.memberGender);

    printf("\tPlease enter your IC > ");
    rewind(stdin);
    scanf("%s", m.memberIC);

    printf("\tPlease enter your Contact Number > ");
    rewind(stdin);
    scanf("%[^\n]", m.memberContactNum);

    printf("\tRanking?(S = Silver / G = Gold / D = Diamond)> ");
    rewind(stdin);
    scanf("%c", &m.ranking);

    printf("\tDay joined? > ");
    scanf("%d", &m.dateJoined.day);

    printf("\tMonth joined? > ");
    scanf("%d", &m.dateJoined.month);

    printf("\tYear joined? > ");
    scanf("%d", &m.dateJoined.year);

    printf("\n========================================================\n");

    fprintf(fptr, "%d|%s|%s|%s|%s|%c|%d|%d|%d\n", m.memberID, m.memberName,
            m.memberGender, m.memberIC, m.memberContactNum, m.ranking,
            m.dateJoined.day, m.dateJoined.month, m.dateJoined.year);
  }
  fclose(fptr);
}

void search() {
  Member m;
  FILE* fptr;
  int count = 0, found = 0, searchYr;

  fptr = fopen("memberDetails.txt", "r");

  if (fptr == NULL) {
    printf("This file cannot be open!\n");
    exit(-1);
  }

  printf("Search for the member who joined at which year?> ");
  scanf("%d", &searchYr);
  printf("\n");

  while (fscanf(fptr, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d|%d|%d", &m.memberID,
                m.memberName, m.memberGender, m.memberIC, m.memberContactNum,
                &m.ranking, &m.dateJoined.day, &m.dateJoined.month,
                &m.dateJoined.year) != EOF) {
    if (searchYr == m.dateJoined.year) {
      found = 1;
      printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "ID", "NAME",
             "Gender", "IC", "PhoneNo", "Ranking", "Day", "Month", "Year");
      printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "==", "====",
             "======", "==", "=======", "=======", "===", "=====", "====");
      printf("%2d %15s %9s %18s %18s %7c %13d %10d %13d\n", m.memberID,
             m.memberName, m.memberGender, m.memberIC, m.memberContactNum,
             m.ranking, m.dateJoined.day, m.dateJoined.month,
             m.dateJoined.year);
      count++;
    }
  }
  if (!found) {
    printf("\nRecord Not Found!!");
  }
  printf(
      "\n*---------------------------------------------------------------------"
      "-----------------------------------*\n");
  printf("%d member(s) joined in year %d\n", count, searchYr);
  printf(
      "*-----------------------------------------------------------------------"
      "---------------------------------*\n");

  fclose(fptr);
}

void modify() {
  Member m[100];
  FILE* fptr;
  int count = 0, found = 0, id, i = 0, modiCount = 0, day, month, year;
  char cont, ans, name[20], gender[6], ic[15], contactNum[15], rank;
  fptr = fopen("memberDetails.txt", "r");

  if (fptr == NULL) {
    printf("This file cannot be open!\n");
    exit(-1);
  }

  while (fscanf(fptr, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d|%d|%d", &m[i].memberID,
                m[i].memberName, m[i].memberGender, m[i].memberIC,
                m[i].memberContactNum, &m[i].ranking, &m[i].dateJoined.day,
                &m[i].dateJoined.month, &m[i].dateJoined.year) != EOF) {
    count++;
    i++;
  }
  fclose(fptr);

  do {
    printf("\n");
    printf("Enter the member ID that you want to update> ");
    scanf("%d", &id);
    printf("\n");

    printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "ID", "NAME",
           "Gender", "IC", "PhoneNo", "Ranking", "Day", "Month", "Year");
    printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "==", "====",
           "======", "==", "=======", "=======", "===", "=====", "====");

    for (i = 0; i < count; i++) {
      if (id == m[i].memberID) {
        found = 1;

        printf("%2d %15s %9s %18s %18s %7c %13d %10d %13d\n", m[i].memberID,
               m[i].memberName, m[i].memberGender, m[i].memberIC,
               m[i].memberContactNum, m[i].ranking, m[i].dateJoined.day,
               m[i].dateJoined.month, m[i].dateJoined.year);

        printf("\n");

        printf(
            "=================================================================="
            "================================================\n\n");

        printf("\tPlease enter new name > ");
        rewind(stdin);
        scanf("%[^\n]", name);

        printf("\tPlease enter Gender(Sir / Miss) > ");
        rewind(stdin);
        scanf("%s", gender);

        printf("\tPlease enter IC > ");
        rewind(stdin);
        scanf("%s", ic);

        printf("\tPlease enter Contact Number > ");
        rewind(stdin);
        scanf("%[^\n]", contactNum);

        printf("\tRanking(S = Silver / G = Gold / D = Diamond)> ");
        rewind(stdin);
        scanf("%c", &rank);

        printf("\tDay joined? > ");
        scanf("%d", &day);

        printf("\tMonth joined? > ");
        scanf("%d", &month);

        printf("\tYear joined? > ");
        scanf("%d", &year);

        printf("Comfirm? (Y = Yes)?> ");
        rewind(stdin);
        scanf("%c", &ans);

        if (toupper(ans) == 'Y') {
          strcpy(m[i].memberName, name);
          strcpy(m[i].memberGender, gender);
          strcpy(m[i].memberIC, ic);
          strcpy(m[i].memberContactNum, contactNum);
          m[i].ranking = rank;
          m[i].dateJoined.day = day;
          m[i].dateJoined.month = month;
          m[i].dateJoined.year = year;
          modiCount++;
        }

        printf("\nUpdated Record : \n");
        printf("\n");
        printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "ID", "NAME",
               "Gender", "IC", "PhoneNo", "Ranking", "Day", "Month", "Year");
        printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "==", "====",
               "======", "==", "=======", "=======", "===", "=====", "====");
        printf("%2d %15s %9s %18s %18s %7c %13d %10d %13d\n", m[i].memberID,
               m[i].memberName, m[i].memberGender, m[i].memberIC,
               m[i].memberContactNum, m[i].ranking, m[i].dateJoined.day,
               m[i].dateJoined.month, m[i].dateJoined.year);
      }
    }
    if (!found) printf("No member was found with ID %d\n", id);
    printf("any more record to modify(Y = Yes) ? > ");
    rewind(stdin);
    scanf("%c", &cont);

  } while (toupper(cont) == 'Y');

  fptr = fopen("memberDetails.txt", "w");

  for (i = 0; i < count; i++) {
    fprintf(fptr, "%d|%s|%s|%s|%s|%c|%d|%d|%d\n", m[i].memberID,
            m[i].memberName, m[i].memberGender, m[i].memberIC,
            m[i].memberContactNum, m[i].ranking, m[i].dateJoined.day,
            m[i].dateJoined.month, m[i].dateJoined.year);
  }

  fclose(fptr);

  printf("\n\t%d Record(s) modified..\n\n", modiCount);
}

void delete () {
  Member m[100];
  FILE* fptr;
  int count = 0, found = 0, id, i = 0, deleteCount = 0;
  char cont, ans;
  fptr = fopen("memberDetails.txt", "r");

  if (fptr == NULL) {
    printf("This file cannot be open!\n");
    exit(-1);
  }

  while (fscanf(fptr, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%c|%d|%d|%d", &m[i].memberID,
                m[i].memberName, m[i].memberGender, m[i].memberIC,
                m[i].memberContactNum, &m[i].ranking, &m[i].dateJoined.day,
                &m[i].dateJoined.month, &m[i].dateJoined.year) != EOF) {
    count++;
    i++;
  }
  fclose(fptr);

  do {
    printf("\n");
    printf("Enter the member ID that you want to delete> ");
    scanf("%d", &id);
    printf("\n");

    printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "ID", "NAME",
           "Gender", "IC", "PhoneNo", "Ranking", "Day", "Month", "Year");
    printf("%3s %10s %15s %11s %18s %15s %11s %11s %11s\n", "==", "====",
           "======", "==", "=======", "=======", "===", "=====", "====");

    for (i = 0; i < count; i++) {
      if (id == m[i].memberID) {
        found = 1;

        printf("%2d %15s %9s %18s %18s %7c %13d %10d %13d\n", m[i].memberID,
               m[i].memberName, m[i].memberGender, m[i].memberIC,
               m[i].memberContactNum, m[i].ranking, m[i].dateJoined.day,
               m[i].dateJoined.month, m[i].dateJoined.year);

        printf("\n");

        printf(
            "=================================================================="
            "================================================\n\n");

        printf("Comfirm to delete? (Y = Yes)> ");
        rewind(stdin);
        scanf("%c", &ans);

        if (toupper(ans) == 'Y') {
          strcpy(m[i].memberName, m[i + 1].memberName);
          strcpy(m[i].memberGender, m[i + 1].memberGender);
          strcpy(m[i].memberIC, m[i + 1].memberIC);
          strcpy(m[i].memberContactNum, m[i + 1].memberContactNum);
          m[i].ranking = m[i + 1].ranking;
          m[i].dateJoined.day = m[i + 1].dateJoined.day;
          m[i].dateJoined.month = m[i + 1].dateJoined.month;
          m[i].dateJoined.year = m[i + 1].dateJoined.year;
          deleteCount++;
        }
      }
    }
    if (!found) printf("No member was found with ID %d\n", id);

    printf("Want to delete another record? (Y = Yes) > ");
    rewind(stdin);
    scanf("%c", &cont);

  } while (toupper(cont) == 'Y');

  fptr = fopen("memberDetails.txt", "w");

  for (i = 0; i < count; i++) {
    fprintf(fptr, "%d|%s|%s|%s|%s|%c|%d|%d|%d\n", m[i].memberID,
            m[i].memberName, m[i].memberGender, m[i].memberIC,
            m[i].memberContactNum, m[i].ranking, m[i].dateJoined.day,
            m[i].dateJoined.month, m[i].dateJoined.year);
  }

  fclose(fptr);

  printf("\n%d Record(s) deleted..\n\n", deleteCount);
}

void report() {}

void main() {
  int choice;

  do {
    printf("\n\n\nWelcome To The Menu");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n1.Create");
    printf("\n2.Display");
    printf("\n3.Append");
    printf("\n4.Search");
    printf("\n5.Update");
    printf("\n6.Delete");
    printf("\n7.Report");
    printf("\n0.Exit\n");

    printf("\nEnter the option to process: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        create();
        break;

      case 2:
        display();
        break;

      case 3:
        append();
        break;

      case 4:
        search();
        break;

      case 5:
        modify();
        break;

      case 6:
        delete ();
        break;

      case 7:
        report();
        break;
    }
  } while (choice != 0);
}
