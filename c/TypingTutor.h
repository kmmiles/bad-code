#pragma once
//header guard
#ifndef TYPINGTUTOR_H
#define TYPINGTUTOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SLEEP_TIME 1

void Print_Sentence(char* array_string[], size_t array_size) {
    srand(time(NULL));
    size_t i = rand() % array_size;
    system("clear");
    printf("%s\n", array_string[i]);
}

void User_Input(char user_input[]) {
    time_t input_start;
    printf("\n>>> ");
    input_start = time(NULL);
    scanf("%s", user_input);
    printf("\n\nYour time was %.2f seconds\n", (double)(time(NULL) - (double)input_start));
}

int Compare_Strings(char user_input[], char *str_arr[]) {
    int error = 0;
    for(int i = 0; i <= 20; i++) {
        if(user_input != str_arr[i]) {
            error++;
        }
    }
    printf("You made %d typos\n", error);
    return(0);
}

#endif
