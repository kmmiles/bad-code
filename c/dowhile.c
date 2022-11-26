#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
    char name[100];
    char phoneNumber[16];
} person;

int main()
{
    int number;
    do
    {
        printf("Number of people: ");
        scanf("%d", &number);
    }
    while (number < 0 || number > 100);
    person *p = malloc(sizeof(person) * number);
    
    for(int i = 0; i < number; i++, p++)
    {
        printf("Name: ");
        scanf("%s", p->name);
        printf("Phone Number: ");
        scanf("%s", p->phoneNumber);
    }
    return 0;
}
