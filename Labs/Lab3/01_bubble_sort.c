#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int length, int arr[])
{
    for (int i = 0; i < length - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
        if(!swapped) {
            break;
        }
    }
}

void print_arr(int length, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {4, 5, 7, 6, 10, 9, 8, 1, 2, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(length, arr);
    print_arr(length, arr);
}