#include <stdio.h>

void for_loops() {
    int i;
    for (i = 1; i < 10; ++i)
    {
        printf("Ello");
    }

}
int main() {
    for_loops();
    int aa, ii = 20;
    printf("%d", aa); // prints 0
    printf("\n");
    printf("%d", ii); // prints 20

    int a = 20, i;
    printf("%d", a); // prints 20
    printf("\n");
    printf("%d", i); // prints 0
    return 0;
}
