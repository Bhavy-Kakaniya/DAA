#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100000];

void createFile(char filename[], int n, int type)
{
    FILE *fp = fopen(filename, "w");
    int i, j, temp;

    if(type == 1)      // Best Case
    {
        for(i = 1; i <= n; i++)
            fprintf(fp, "%d\n", i);
    }
    else if(type == 2) // Average Case
    {
        for(i = 0; i < n; i++)
            arr[i] = i + 1;

        for(i = n - 1; i > 0; i--)
        {
            j = rand() % (i + 1);

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        for(i = 0; i < n; i++)
            fprintf(fp, "%d\n", arr[i]);
    }
    else               // Worst Case
    {
        for(i = n; i >= 1; i--)
            fprintf(fp, "%d\n", i);
    }

    fclose(fp);
}

void bubbleSort(int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calculateTime(char filename[], int n)
{
    FILE *fp = fopen(filename, "r");
    int i;

    for(i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    clock_t start, end;

    start = clock();
    bubbleSort(n);
    end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

void main()
{
    int sizes[3] = {1000, 10000, 100000};
    char filename[30];
    int i;

    printf("Bubble Sort Time Analysis\n\n");

    for(i = 0; i < 3; i++)
    {
        createFile("best.txt", sizes[i], 1);
        createFile("average.txt", sizes[i], 2);
        createFile("worst.txt", sizes[i], 3);

        printf("Size = %d\n", sizes[i]);

        printf("Best Case    : %.6f seconds\n",
               calculateTime("best.txt", sizes[i]));

        printf("Average Case : %.6f seconds\n",
               calculateTime("average.txt", sizes[i]));

        printf("Worst Case   : %.6f seconds\n\n",
               calculateTime("worst.txt", sizes[i]));
    }
}