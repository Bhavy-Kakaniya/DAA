#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double bubble_sort(int arr[], int n)
{
    int i, j, temp;
    clock_t start, end;
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void bubble_sort_best_case_1000(int n)
{
    int arr[n];
    FILE *fp_bestcase_1000;

    fp_bestcase_1000 = fopen("bestcase.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp_bestcase_1000, "%d ", i);
    }
    fclose(fp_bestcase_1000);
    fp_bestcase_1000 = fopen("bestcase.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp_bestcase_1000, "%d", &arr[i]);
    }

    fclose(fp_bestcase_1000);
    printf("\nbest case, size 1000: %f", bubble_sort(arr, n));
}

void bubble_sort_worst_case_1000(int n)
{
    int arr[n];
    FILE *fp_worstcase_1000;

    fp_worstcase_1000 = fopen("worstcase.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp_worstcase_1000, "%d ", i);
    }
    fclose(fp_worstcase_1000);
    fp_worstcase_1000 = fopen("worstcase.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp_worstcase_1000, "%d", &arr[i]);
    }

    fclose(fp_worstcase_1000);
    printf("\nworst case, size 1000: %f", bubble_sort(arr, n));
}

void bubble_sort_average_case_1000(int n)
{
    int arr[n];
    FILE *fp_averagecase_1000;

    fp_averagecase_1000 = fopen("averagecase.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp_averagecase_1000, "%d ", rand() % n);
    }
    fclose(fp_averagecase_1000);
    fp_averagecase_1000 = fopen("averagecase.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp_averagecase_1000, "%d", &arr[i]);
    }

    fclose(fp_averagecase_1000);
    printf("\naverage case, size 1000: %f", bubble_sort(arr, n));
}

void bubble_sort_average_case_10000(int n)
{
    int arr[n];
    FILE *fp_averagecase_10000;

    fp_averagecase_10000 = fopen("averagecase10000.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp_averagecase_10000, "%d ", rand() % n);
    }
    fclose(fp_averagecase_10000);
    fp_averagecase_10000 = fopen("averagecase10000.txt", "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp_averagecase_10000, "%d", &arr[i]);
    }

    fclose(fp_averagecase_10000);
    printf("\naverage case, size 10000: %f", bubble_sort(arr, n));
}

void main()
{
    bubble_sort_best_case_1000(1000);
    bubble_sort_worst_case_1000(1000);
    bubble_sort_average_case_1000(1000);
    bubble_sort_average_case_10000(100000);
}