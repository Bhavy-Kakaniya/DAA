#include <stdio.h>

void subArrays(int arr[], int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            printf("[ ");
            for (int k = start; k <= end; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("]\n");
        }
    }
}
void main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Subarrays:\n");
    subArrays(arr, n);
}