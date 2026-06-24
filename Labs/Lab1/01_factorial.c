#include <stdio.h>
#include <time.h>

int factorial_recursive(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return factorial_recursive(n - 1) * n;
}

int factorial_loop(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}

void main()
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_taken;

    start = clock();
    printf("%d using loop", factorial_loop(n));
    end = clock();

    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\ntime taken using iterative function : %f", cpu_time_taken);

    start = clock();
    printf("\n%d using recursion", factorial_recursive(n));
    end = clock();

    cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\ntime taken using recursive function : %f", cpu_time_taken);

}
