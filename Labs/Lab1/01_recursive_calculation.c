#include <stdio.h>

int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return factorial(n - 1) * n;
}

void main()
{
    int n = 7;
    printf("%d", factorial(n));
}