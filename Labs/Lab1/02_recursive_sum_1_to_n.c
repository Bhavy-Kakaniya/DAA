#include <stdio.h>
#include <time.h>

int sum_recursive(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return sum_recursive(n - 1) + n;
}

int sum_iterative(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

void main()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    start = clock();
    printf("\n%d using iteration", sum_iterative(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using iterative function : %f", time_taken);
    
    start = clock();
    printf("\n%d using recursion", sum_iterative(n));
    end = clock();
    time_taken = ((double)(end - start));
    printf("\ntime taken using iterative function : %f", time_taken);

}
