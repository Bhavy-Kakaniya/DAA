#include <stdio.h>
#include <time.h>

int power_recursion(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    return x * power_recursion(x, y - 1);
}

int power_iterative(int x, int y)
{
    int product = 1;
    for (int i = 1; i <= y; i++)
    {
        product *= x;
    }
    return product;
}

void main()
{
    int x = 3, y = 6;

    printf("Enter number : ");
    scanf("%d", &x);
    printf("Enter power : ");
    scanf("%d", &y);

    clock_t start, end;
    double time_taken;

    start = clock();
    printf("%d using iteration", power_iterative(x, y));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using iterative function : %f", time_taken);

    start = clock();
    printf("%d using recursion", power_recursion(x, y));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using recursion function : %f", time_taken);
}
