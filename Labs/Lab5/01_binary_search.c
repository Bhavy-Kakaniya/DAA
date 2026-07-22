#include <stdio.h>

int binary_search_iterative(int arr[], int size, int target)
{
    int start = 0, end = size;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(int arr[], int target, int start, int end)
{
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binary_search_recursive(arr, target, start, mid - 1);
    }
    else if (arr[mid] < target)
    {
        return binary_search_recursive(arr, target, mid + 1, end);
    }
    return -1;
}

void main()
{
    int arr[] = {12, 34, 56, 67, 79, 80, 90, 101};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    printf("found at index : %d", binary_search_iterative(arr, size, target));
    printf("found at index : %d", binary_search_recursive(arr, target, 0, size - 1));
}