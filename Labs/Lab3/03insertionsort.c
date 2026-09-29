#include <stdio.h>
#include <time.h>

void main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();

    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    clock_t end = clock();
    double diff = (double)(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}