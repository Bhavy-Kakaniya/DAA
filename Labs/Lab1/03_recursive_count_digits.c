#include <stdio.h>

int count = 0;

int digit(int n) {
    if(n == 0) {
        return count;
    }
    count++;
    return digit(n / 10);
}

void main()
{
    int n = 1234567;
    printf("%d", digit(n));
}