#include <stdio.h>
#include <stdbool.h>

void sortMeetings(int arr[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] < arr[minIndex][0])
                minIndex = j;
        }
        int temp = arr[i][0];
        arr[i][0] = arr[minIndex][0];
        arr[minIndex][0] = temp;
        temp = arr[i][1];
        arr[i][1] = arr[minIndex][1];
        arr[minIndex][1] = temp;
    }
}

bool canAttendMeetings(int arr[][2], int n)
{
    sortMeetings(arr, n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] < arr[i - 1][1]) return false;
    }
    return true;
}

void main()
{
    int arr[][2] = {{2, 4}, {1, 2}, {7, 8}, {5, 6}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (canAttendMeetings(arr, n))  printf("true");
    else printf("false");
}