#include <stdio.h>

typedef struct {
    int start;
    int end;
} Activity;

// Function to select the maximum number of non-overlapping activities
void activitySelection(Activity activities[], int n) {
    // The first activity always gets selected
    int lastSelected = 0;
    printf("Selected activities:\n");
    printf("Activity (%d, %d)\n", activities[lastSelected].start, activities[lastSelected].end);

    // Iterate through the activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal
        // to the end time of the last selected activity
        if (activities[i].start >= activities[lastSelected].end) {
            printf("Activity (%d, %d)\n", activities[i].start, activities[i].end);
            lastSelected = i; // Update the last selected activity
        }
    }
}

int main() {
    // Example activities already sorted by end times
    Activity activities[] = {
        {1, 3},
        {2, 5},
        {4, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
