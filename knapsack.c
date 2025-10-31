#include <stdio.h>

#define ITEMS 6


struct Item {
    int weight;
    int money;
};


void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sortItemsByRatio(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].money / items[j].weight;
            double ratio2 = (double)items[j + 1].money / items[j + 1].weight;
            if (ratio1 < ratio2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

int knapsackGreedy(int capacity, struct Item items[], int n) {
    int currentWeight = 0;
    int totalValue = 0;

    
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].money;
        }
    }
    
    return totalValue;
}

int main() {

    struct Item items[ITEMS] = {
        {5, 100},
        {10, 200},
        {15, 150},
        {20, 80},
        {25, 225},
        {30, 180}
    };
    
    
    int capacity = 50;

    sortItemsByRatio(items, ITEMS);

    int maxValue = knapsackGreedy(capacity, items, ITEMS);

    printf("Maximum money in knapsack = %d\n", maxValue);

    return 0;
}