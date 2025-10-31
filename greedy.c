#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to sort activities by finish times using Selection Sort
void sortActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (finish[j] < finish[minIndex]) {
                minIndex = j;
            }
        }
        swap(&finish[i], &finish[minIndex]);
        swap(&start[i], &start[minIndex]);
    }
}
void activitySelection(int start[], int finish[], int n) {
    int i, j;

    printf("Selected activities are:\n");
    i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);

    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            i = j;  
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter the start times of the activities: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    printf("Enter the finish times of the activities: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &finish[i]);
    }
    sortActivities(start, finish, n);
    activitySelection(start, finish, n);

    return 0;
}