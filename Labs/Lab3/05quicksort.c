#include <stdio.h>
#include <time.h>
/*
void quickSort(int arr[], int low, int high)
{
    int i, j, temp, pivot;
    if (low < high)
    {
        pivot = arr[low];
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && arr[i] <= pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}
*/

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int i, j, temp, pivot;
        pivot = arr[low];

        while(i <= j){
           while(i <= high && arr[i] <= pivot) i++;
           while(arr[j] > pivot) j--;
        }
    }
}

void main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}