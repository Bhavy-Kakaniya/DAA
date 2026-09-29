#include <stdio.h>
#include <time.h>

void main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[minIndex]; 
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    clock_t end = clock();

    double diff = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %f\n", diff);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}