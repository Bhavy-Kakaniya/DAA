#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void create_file(char *filename, int size_of_file, int type)
{
    FILE *fp = fopen(filename, "w");
    if (type == 0) // best
    {
        for (int i = 0; i < size_of_file; i++)
        {
            fprintf(fp, "%d ", i);
        }
    }
    else if (type == 1) // average Case
    {
        int arr[size_of_file];

        for (int i = 0; i < size_of_file; i++)
            arr[i] = i;

        for (int i = size_of_file - 1; i >= 0; i--)
        {
            int j = rand() % (i + 1);

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        for (int i = 0; i < size_of_file; i++)
        {
            fprintf(fp, "%d ", arr[i]);
        }
    }
    else // worst
    {
        for (int i = size_of_file; i > 0; i--)
        {
            fprintf(fp, "%d ", i);
        }
    }
    fclose(fp);
}

double calculate_time(char filename[], int size)
{
    int arr[size];
    FILE *fp = fopen(filename, "r");
    for (int i = 0; i < size; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    clock_t start, end;

    start = clock();
    heap_sort(arr, size);
    end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

void main()
{
    srand((unsigned)time(NULL));
    char *file_name = "file.txt";

    int size_of_file_array[] = {1000, 10000, 100000};

    printf("\n---Heap Sort---\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n Array size = %d", size_of_file_array[i]);
        create_file(file_name, size_of_file_array[i], 0);
        printf("\nBest Case : time taken = %.6f sec\n", calculate_time(file_name, size_of_file_array[i]));
        create_file(file_name, size_of_file_array[i], 1);
        printf("Average Case : time taken = %.6f sec\n", calculate_time(file_name, size_of_file_array[i]));
        create_file(file_name, size_of_file_array[i], 2);
        printf("Worst Case: time taken = %.6f sec\n", calculate_time(file_name, size_of_file_array[i]));
    }
}