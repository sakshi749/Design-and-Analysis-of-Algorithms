//created by sakshi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    srand(time(0));
    int n = 100;
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    quickSort(array, 0, n - 1);

    int x;
    printf("Enter the number: ");
    scanf("%d", &x);

    clock_t start = clock();
    int result = binarySearch(array, x, 0, n - 1);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    if (result == -1)
        printf("Element %d not found\n", x);
    else
        printf("Element %d is found at index %d\n", x, result);

    printf("Time taken in binary search: %f seconds\n", time_spent);

    free(array);20
    return 0;
}
