//created by sakshi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearchRecursive(int arr[], int start, int end, int target) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            return binarySearchRecursive(arr, mid + 1, end, target);
        return binarySearchRecursive(arr, start, mid - 1, target);
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000;
    }

    bubbleSort(arr, 100);

    int target = arr[rand() % 100];

    printf("Array: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Target: %d\n", target);

    clock_t start_time = clock();
    int result = binarySearchRecursive(arr, 0, 99, target);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    printf("Time taken for binary search: %f seconds\n", time_taken);

    return 0;}