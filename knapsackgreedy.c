#include <stdio.h>

void knapsack(int n, int weights[], int values[], int W) {
    double totalContinuousValue = 0.0, ratio[10];
    int i, j, temp, totalDiscreteValue = 0;

    // Calculate value-to-weight ratios
    for (i = 0; i < n; i++)
        ratio[i] = (double)values[i] / weights[i];
        
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap weights
                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;

                // Swap values
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    // Continuous Knapsack: Fill the knapsack fractionally
    int W_cont = W; // copy of W for continuous knapsack
    for (i = 0; i < n && W_cont > 0; i++) {
        if (weights[i] <= W_cont) {
            W_cont -= weights[i];
            totalContinuousValue += values[i];
        } else {
            totalContinuousValue += values[i] * ((double)W_cont / weights[i]);
            break;
        }
    }
    printf("Maximum value in Continuous Knapsack = %.2f\n", totalContinuousValue);

    // Greedy Discrete Knapsack: Fill the knapsack with whole items
    int W_disc = W; // copy of W for discrete knapsack
    for (i = 0; i < n && W_disc > 0; i++) {
        if (weights[i] <= W_disc) {
            W_disc -= weights[i];
            totalDiscreteValue += values[i];
        }
    }
    printf("Maximum value in Greedy Discrete Knapsack = %d\n", totalDiscreteValue);
}

int main() {
    int n, W, weights[10], values[10];
    printf("Enter the number of items and knapsack capacity:\n");
    scanf("%d %d", &n, &W);
    printf("Enter weights and values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &weights[i], &values[i]);

    knapsack(n, weights, values, W);

    return 0;
}
