#include <stdio.h>
#include <time.h>

int digit_recursive(int n, int count)
{
    if (n == 0)
    {
        return count;
    }
    count++;
    return digit_recursive(n / 10, count);
}

int digit_iterative(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

void main()
{
    int n;
    int count = 0;

    printf("Enter number : ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    start = clock();
    printf("\n%d using iteration", digit_iterative(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using iterative function : %f", time_taken);

    start = clock();
    printf("\n%d using recursion", digit_recursive(n, count));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using recursion function : %f", time_taken);
}
