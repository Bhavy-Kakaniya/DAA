#include <stdio.h>
#include <stdbool.h>

bool findPair(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

int main() {
    int arr[] = {2, 3, 4, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 12;

    if (findPair(arr, n, target))
        printf("true");
    else
        printf("false");

}