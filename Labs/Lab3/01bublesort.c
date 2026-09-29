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

    clock_t start;
    clock_t end;

    start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(swap == 0) {
            break;
        }
    }
    end = clock();

    double diff = (double)(end - start) / CLOCKS_PER_SEC;

    printf("time taken = %f\n", diff);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}