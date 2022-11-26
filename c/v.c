#include <stdio.h>
int main ()
{
    int n, a, b, c;

    do
    {
        scanf("%d", &n);
    }
    while (n < 1 || n > 20);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            printf(" ");
        }
        printf("**");

        for (int g = 2*(n - i) - 1; g >= 0; g--)
        {
            printf(" ");
        }
        printf("*");
        for (int z = 0; z <= n-1; z++)
        {
            printf (" ");
        }
        printf("\n");

    }
    for (int h = 1; h <= n; h++)
    {
        printf(" ");
    }
    printf("*");

    for (int $ = 0; $ <= n-1; $++)
    {
        printf(" ");
    }


}
