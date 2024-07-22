#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double continuousKnapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    int n = sizeof(items) / sizeof(items[0]);
    printf("Maximum value in Continuous Knapsack = %.2f\n", continuousKnapsack(W, items, n));
    return 0;
}
