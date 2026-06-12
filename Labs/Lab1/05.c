#include <stdio.h>
#include <stdbool.h>
void main()
{
    int n = -15, m = 6;
    bool found = false;

    while (!found)
    {
        n--;
        if (n % m == 0)
        {
            found = true;
            printf("%d", n);
            break;
        }
    }
}
