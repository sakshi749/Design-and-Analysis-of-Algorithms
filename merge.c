//created by sakshi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Original array:\n");
    printArray(arr, SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergeSort(arr, 0, SIZE - 1);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(arr, SIZE);

    printf("Time taken by Merge Sort: %f seconds\n", cpu_time_used);
    double nlogn_time = SIZE * log(SIZE);
    printf("n*log(n) comparison value: %f\n", nlogn_time);

    return 0;
}
