#include <stdio.h>
#include <stdlib.h>

#define scanf_s scanf

int main() {
  int selection = 0, resNo = 0, procNo = 0, resCounter = 0, countRes4Avail = 0;
  int resources = 0;  // cols
  int processes = 0;  // rows

  // define the tables
  int *resTable = NULL, *availTable = NULL, *allocatedSum = NULL;
  int *maxClaimTable = NULL, *allocatedTable = NULL, *needTable = NULL;

  // Memory Allocations Heppen Here

  /*
      int* maxClaimTable = (int*)malloc(processes * resources * sizeof(int));
      int* allocatedTable = (int*)malloc(processes * resources * sizeof(int));
      int* needTable = (int*)malloc(processes * resources * sizeof(int));
      resTable = (int*)malloc(resNo * sizeof(int));
      availTable = (int*)malloc(resNo * sizeof(int));
      allocatedSum = (int*)malloc(resNo * sizeof(int));
  */

  printf("1) Enter parameters\n");
  printf("2) Determine safe sequence\n");
  printf("3) Quit Program\n");

  printf("\nEnter selection: ");
  scanf("%d", &selection);

  if (selection == 1) {
    printf("\nEnter number of resources: ");  // cols
    scanf_s("%d", &resources);
    resNo = resources;

    for (int i = 0; i < resNo; i++) {
      resCounter = i;
    }

    printf("Enter number of processes: ");  // rows
    scanf_s("%d", &processes);
    procNo = processes;

    printf("Enter number of units for resources (r0 to r%d): ", resCounter);
    for (int i = 0; i < resNo; i++) {
      scanf_s("%d", &resTable[i]);
    }

    // Max Claim Table Entry
    for (int i = 0; i < procNo; i++) {  // rows
      printf(
          "Enter maximum number of units process p%d will request from each "
          "resource (r0 to r%d): ",
          i, resCounter);
      for (int j = 0; j < resNo; j++) {  // cols
        scanf_s("%d", maxClaimTable + i * resNo + j);
      }
      printf("\n");
    }

    // allocatedTable Table Entry
    for (int i = 0; i < procNo; i++) {  // rows
      printf(
          "Enter number of units of each resource (r0 to r%d) allocatedTable "
          "to process p%d: ",
          resCounter, i);
      for (int j = 0; j < resNo; j++) {  // cols
        scanf_s("%d", allocatedTable + i * resNo + j);
      }
      printf("\n");
    }

    // Calculate Avaiable
    for (int j = 0; j < resNo; j++) {
      allocatedSum[j] = 0;
    }
    for (int i = 0; i < procNo; i++) {   // rows
      for (int j = 0; j < resNo; j++) {  // cols
        allocatedSum[j] = allocatedSum[j] + allocatedTable[i * resNo + j];
      }
    }
    for (int j = 0; j < resNo; j++) {
      availTable[j] = resTable[j] - allocatedSum[j];
    }

    // Calculate Need
    for (int i = 0; i < procNo; i++) {
      for (int j = 0; j < resNo; j++) {  // cols
        needTable[i * resNo + j] = 0;
      }
    }
    for (int i = 0; i < procNo; i++) {   // rows
      for (int j = 0; j < resNo; j++) {  // cols
        needTable[i * resNo + j] =
            maxClaimTable[i * resNo + j] - allocatedTable[i * resNo + j];
      }
    }

    // Print Resources
    printf("Resources:\n\t");
    for (int i = 0; i < resNo; i++) {  // cols
      printf("r%d\t", i);
    }

    printf("\n");

    for (int i = 0; i < resNo; i++) {
      printf("\t%d", resTable[i]);
    }
    ////////////////////////////
    printf("\n");

    // Print Available
    printf("\nAvailable:\n\t");
    for (int i = 0; i < resNo; i++) {  // cols
      printf("r%d\t", i);
    }

    printf("\n");

    for (int i = 0; i < resNo; i++) {
      printf("\t%d", availTable[i]);
    }

    ////////////////////////////
    printf("\n");
    printf("\n");

    // Print Max Claim Table
    printf("Max Claim:\n");

    for (int i = 0; i < resNo; i++) {  // cols
      printf("\tr%d", i);
    }
    printf("\n");
    for (int i = 0; i < procNo; i++) {  // rows
      printf("p%d\t", i);
      for (int j = 0; j < resNo; j++) {  // cols
        printf("%d\t", *(maxClaimTable + i * resNo + j));
      }
      printf("\n");
    }
    /// ////////////////
    printf("\n");
    printf("\n");

    // Print Allocate Table
    printf("Allocated:\n");

    for (int i = 0; i < resNo; i++) {  // cols
      printf("\tr%d", i);
    }
    printf("\n");
    for (int i = 0; i < procNo; i++) {  // rows
      printf("p%d\t", i);
      for (int j = 0; j < resNo; j++) {  // cols
        printf("%d\t", *(allocatedTable + i * resNo + j));
      }
      printf("\n");
    }

    /// ////////////////
    printf("\n");
    printf("\n");

    // Print Need Table
    printf("Need:\n");

    for (int i = 0; i < resNo; i++) {  // cols
      printf("\tr%d", i);
    }
    printf("\n");
    for (int i = 0; i < procNo; i++) {  // rows
      printf("p%d\t", i);
      for (int j = 0; j < resNo; j++) {  // cols
        printf("%d\t", *(needTable + i * resNo + j));
      }
      printf("\n");
    }

    printf("\nLOOK AT HERE %d", allocatedTable[0 * procNo + 6]);

    free(maxClaimTable);
    free(resTable);
    free(allocatedTable);
    free(availTable);
    free(allocatedSum);
    free(needTable);
    //	free(allocatedNeed);
  }

  else if (selection == 2) {
  } else if (selection == 3) {
    exit(0);
  }
}
