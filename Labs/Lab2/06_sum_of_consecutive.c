#include <stdio.h>
#include <stdbool.h>

bool consecutiveOrNot(int n)
{
    return (n & (n - 1)) != 0;
}

void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (consecutiveOrNot(n))
        printf("true");
    else
        printf("false");
}