#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void main() {
    int a[] = {1, 4, 2, 3};
    int b[] = {2, 5, 1, 6};
    int n = 4;
    int k = 3;

    int sumArr[n * n];
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumArr[idx++] = a[i] + b[j];
        }
    }
    heapSort(sumArr, n * n);

    for (int i = n * n - 1; i >= n * n - k; i--) {
        printf("%d ", sumArr[i]);
    }

}