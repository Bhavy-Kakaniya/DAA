#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size)
{
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(&arr[i], &arr[minIndex]);
        }
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
    selection_sort(arr, size);
    end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

void main()
{
    srand((unsigned)time(NULL));
    char *file_name = "file.txt";

    int size_of_file_array[] = {1000, 10000, 100000};

    printf("\n---Selection Sort---\n");
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