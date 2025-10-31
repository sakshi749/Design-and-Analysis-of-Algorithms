#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100000
#define MAX_CAPACITY 10000
struct Item {
    int weight;
    int value;
};

// Function to sort items by value/weight ratio for Fractional Knapsack
int compare(const void *a, const void *b) {
    double r1 = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double r2 = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    return r2 - r1;
}
// Greedy approach for Fractional Knapsack
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= capacity) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remain = capacity - curWeight;
            finalValue += items[i].value * ((double) remain / items[i].weight);
            break;
        }
    }
    return finalValue;
}
// Dynamic Programming approach for 0-1 Knapsack
int knapsackDP(struct Item items[], int n, int capacity) {
    int dp[capacity + 1];
    for (int i = 0; i <= capacity; i++)
        dp[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= items[i].weight; w--) {
            dp[w] = (dp[w] > dp[w - items[i].weight] + items[i].value) ? dp[w] : (dp[w - items[i].weight] + items[i].value);
        }
    }
    return dp[capacity];
}
void testKnapsack(int numItems, int capacity) {
    struct Item items[numItems];
    
    for (int i = 0; i < numItems; i++) {
        items[i].weight = rand() % 100 + 1;
        items[i].value = rand() % 100 + 1;
    }

    // for Fractional Knapsack (Greedy)
    clock_t start = clock();
    double maxFractionalValue = fractionalKnapsack(items, numItems, capacity);
    clock_t end = clock();
    double time_fractional = (double)(end - start) / CLOCKS_PER_SEC;

    // for 0-1 Knapsack (DP)
    start = clock();
    int maxDPValue = knapsackDP(items, numItems, capacity);
    end = clock();
    double time_dp = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Items: %d, Capacity: %d\n", numItems, capacity);
    printf("Fractional Knapsack (Greedy) - Max Value: %f, Time: %f seconds\n", maxFractionalValue, time_fractional);
    printf("0-1 Knapsack (DP) - Max Value: %d, Time: %f seconds\n", maxDPValue, time_dp);
}

int main() {
    int capacity = MAX_CAPACITY;
    
    // Case 1: 10,000 items
    printf("Case 1: 10,000 items\n");
    testKnapsack(10000, capacity);
    
    // Case 2: 100,000 items
    printf("Case 2: 100,000 items\n");
    testKnapsack(100000, capacity);

    return 0;
}
