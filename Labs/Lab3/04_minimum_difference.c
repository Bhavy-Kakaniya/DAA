#include <stdio.h>
#include <limits.h>
void main()
{
    int arr[] = {1, 5, 3, 19, 18, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int minDiff = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    printf("Min diff = %d", minDiff);
}