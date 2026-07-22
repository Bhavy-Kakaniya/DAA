#include <stdio.h>

void sort(int b[], int m)
{
    int i, j, temp;

    for(i = 0; i < m - 1; i++)
    {
        for(j = 0; j < m - i - 1; j++)
        {
            if(b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int a[20], b[20], n, m;
    int i, temp;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter elements of first sorted array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter elements of second array: ");
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] > b[0])
        {
            temp = a[i];
            a[i] = b[0];
            b[0] = temp;
            sort(b, m);
        }
    }

    printf("First array:");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nSecond array:");
    for(i = 0; i < m; i++)
        printf("%d ", b[i]);
}