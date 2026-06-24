#include <stdio.h>
#include <time.h>

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main()
{
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci Series using Loop:\n");
    int first = 0, second = 1, next;
    start = clock();

    for (i = 0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken by Loop = %f seconds\n", cpu_time_used);
    printf("\nFibonacci Series using Recursion:\n");

    start = clock();

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by Recursion = %f seconds\n", cpu_time_used);
}