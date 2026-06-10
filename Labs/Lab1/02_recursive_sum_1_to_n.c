#include <stdio.h>

int sum(int n) {
    if(n == 1) {
        return 1;
    }
    return sum(n - 1) + n;
}

void main()
{
    int n = 8;
    printf("%d", sum(n));
}