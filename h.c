#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_asc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_asc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_asc(arr, low, high);
        quick_sort_asc(arr, low, pi - 1);
        quick_sort_asc(arr, pi + 1, high);
    }
}

int partition_desc(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_desc(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_desc(arr, low, high);
        quick_sort_desc(arr, low, pi - 1);
        quick_sort_desc(arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int bob[n], james[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &bob[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &james[i]);
    }
    quick_sort_desc(bob, 0, n - 1);
    quick_sort_asc(james, 0, n - 1);
    
    int max_score = 0;
    for (int i = 0; i < n; i++) {
        if (bob[i] > james[i]) {
            max_score += bob[i] - james[i]; 
        }
    }
    printf("%d\n", max_score);
    
return 0;
}
